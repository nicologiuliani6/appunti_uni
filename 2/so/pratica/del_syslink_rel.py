import os, stat
import sys

def main():
    if len(sys.argv) < 2:
        print("Uso: python script.py <path/to/dir>")
        return
    root: str = sys.argv[1]

    for dirpath , dirnames , filenames in os.walk (root) :
        for f in filenames + dirnames:
            full = os.path.join(dirpath,f)
            st = os.lstat(full)
            if stat.S_ISLNK(st.st_mode):
                if not os.readlink(full).startswith("/"):
                    os.remove(full)

if __name__ == "__main__":
    main()