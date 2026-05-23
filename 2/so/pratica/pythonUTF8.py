import sys

def read_ascii_sanitize(filepath):
    text = open(filepath, "r", encoding="utf-8").read()

    # ogni carattere NON ASCII diventa "?"
    result = ""
    for c in text:
        if ord(c) < 128: #trasforma in UNICODE (0-127 ASCII)
            result += c
        else:
            result += "?"

    return result

def main():
    if len(sys.argv) < 3:
        print("Uso: python script.py <filein> <fileout>")
        return

    input_value = sys.argv[1]
    ascii_text: str =(read_ascii_sanitize(input_value))
    open(sys.argv[2], "w", encoding="ascii").write(ascii_text)
if __name__ == "__main__":
    main()