a=int(input("inserisci a: "))
b=int(input("inserisci b: "))
c=int(input("inserisci c: "))
d=int(input("inserisci d: "))
somma=a+b+c+d
media=int(somma)/4

if ((a-media)<=(b-media)):
    if ((a-media)<=(c-media)):
        if ((a-media)<=(d-media)):
            print("a")
        else:
            print("d")
    elif((c-media)<(d-media)):
        print("c")
    else:
        print("d")
else:
    if ((b-media)<=(c-media)):
        if ((b-media)<=(d-media)):
            print("b")
        else:
            print("d")
    elif((c-media)<(d-media)):
        print("c")
    else:
        print("d")