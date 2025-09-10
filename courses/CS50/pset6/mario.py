#!/usr/bin/env python3

def draw(i, j):
    if i == 0:
        return 0
    else:
        k = j - i
        draw(i - 1, j)
        string = " " * k + "#" * i + "  " + "#" * i
        print(string)


def main():
    status = 1
    while status != 0:
        h = input("Height:")
        if h.isdigit():
            h = int(h)
            if h > 0 and h < 9:
                status = 0
            else:
                status = 1
        else:
            status = 1
    draw(h, h)


main()
