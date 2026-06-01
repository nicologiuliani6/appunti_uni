import os
import sys

def main():
    if len(sys.argv) != 2:
        print("usage: script.py [dir]")
        sys.exit(1)
    root: str = os.path.normpath(sys.argv[1])
    files = []
    for dirpath, dirnames, filenames in os.walk(root):
            depth = dirpath.replace(root, '').count(os.sep)
            for f in filenames:
                files.append((depth, f, os.path.join(dirpath, f)))
    # ordina: prima i più profondi, a parità di profondità ordine alfabetico
    files.sort(key=lambda x: (-x[0], x[1]))

    for depth, name, path in files:
        print(path)
if __name__ == "__main__":
    main()