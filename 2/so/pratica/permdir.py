import sys
import os
import stat
from collections import defaultdict

def main():
    if len(sys.argv) < 2:
        print("Uso: python script.py <path/to/dir>")
        return
    dir = sys.argv[1]
    by_mode = defaultdict(list)

    for entry in os.scandir(dir):
        if not entry.is_file(follow_symlinks=False):  # salta dir, symlink, special files
            continue
        ls_mode = stat.filemode(os.stat(entry.path).st_mode)
        by_mode[ls_mode].append(entry.path)
    
    for ls_mode in by_mode:
        os.makedirs(ls_mode, exist_ok=True)

    for ls_mode, paths in by_mode.items():
        for path in paths:
            filename = os.path.basename(path)
            link_dst = os.path.join(ls_mode, filename)
            os.symlink(path, link_dst)
if __name__ == "__main__":
    main()