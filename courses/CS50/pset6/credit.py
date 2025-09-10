#!/usr/bin/env python3

from cs50 import get_string


def main():
    ## init
    number = get_string("Number:")

    ## compute
    number_length = len(number)
    number_list = [int(n) for n in list(number)]

    if number_length == 15 and number_list[0] == 3 and number_list[1] == 4:
        card = "AMEX"
    elif number_length == 15 and number_list[0] == 3 and number_list[1] == 7:
        card = "AMEX"
    elif number_length == 16 and number_list[0] == 5 and number_list[1] == 1:
        card = "MASTERCARD"
    elif number_length == 16 and number_list[0] == 5 and number_list[1] == 2:
        card = "MASTERCARD"
    elif number_length == 16 and number_list[0] == 5 and number_list[1] == 3:
        card = "MASTERCARD"
    elif number_length == 16 and number_list[0] == 5 and number_list[1] == 4:
        card = "MASTERCARD"
    elif number_length == 16 and number_list[0] == 5 and number_list[1] == 5:
        card = "MASTERCARD"
    elif number_length == 16 and number_list[0] == 4:
        card = "VISA"
    elif number_length == 13 and number_list[0] == 4:
        card = "VISA"
    else:
        card = "INVALID"

    ## index
    i = range(0, number_length)
    j = []
    k = []
    _ = number_length - 2
    while _ > -1:
        j.append(_)
        _ -= 2
    k = [_ for _ in i if _ not in j]

    ## compute
    total = sum([int(y) for x in j for y in list(str(number_list[x] * 2))])
    total += sum([number_list[z] for z in k])
    status = int(list(str(total))[-1])

    ## return
    if status == 0:
        print(card)
    else:
        print("INVALID")

main()
