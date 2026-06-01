import sys
import os

def has_non_ascii(name: str) -> bool:
    return any(ord(c) >= 128 for c in name)

def scan(root: str):
    for dirpath, dirnames, filenames in os.walk(root):
        for d in dirnames:
            if has_non_ascii(d):
                print(f"{dirpath}/{d}")
        for f in filenames:
            if has_non_ascii(f):
                print(f"{dirpath}/{f}")

def main():
    if len(sys.argv) < 2:
        print(f"Uso: python {sys.argv[0]} <dir>")
        sys.exit(1)

    root = sys.argv[1]
    if not os.path.isdir(root):
        print(f"Errore: '{root}' non è una directory")
        sys.exit(1)

    scan(root)

if __name__ == "__main__":
    main()