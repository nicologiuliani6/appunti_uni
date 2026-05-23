import sys
from dataclasses import dataclass
import os

@dataclass
class DB:
    inode: int
    path: str

items = []
def putin(folder_path: str, remain_depth: int):
    if (remain_depth == -1): return
    for entry in os.scandir(folder_path):
        items.append(DB(entry.stat().st_ino, folder_path+entry.name))
        if entry.is_dir():
                putin(folder_path+entry.name+"/", remain_depth-1)
            

def main():
    if len(sys.argv) == 1:
         depth = float('inf')
    elif int(sys.argv[1]) < 0:
        print("python3 inotab.py [depth]")
        exit(1)
    else: depth: int = int(sys.argv[1])

    putin("./", depth)
    items.sort(key=lambda x: x.inode)
    for s in items:
        print(s.inode, s.path.removeprefix("./"))

if __name__ == "__main__":
    main()