#!/usr/bin/env python3

import re
from cs50 import get_string


def coleman_liau(L, S):
    index = 0.0588 * L - 0.296 * S - 15.8
    return index


def main():
    
    # init: string
    i = get_string("Text: ").strip().replace("!", ".").replace("?", ".")
    j = i.split(".")
    m = list(i)

    # compute
    number_of_letters = 0
    for _ in m:
        if _.isalpha():
            number_of_letters += 1
    number_of_sentences = len(j) - 1
    number_of_words = len(i.split(" "))
    x = (number_of_letters / number_of_words) * 100
    y = (number_of_sentences / number_of_words) * 100
    z = round(coleman_liau(x, y))
    print(number_of_letters, number_of_words, number_of_sentences, x, y, z)
    # return
    if z < 1:
        o = "Before Grade 1"
    elif z < 16:
        o = "Grade {}".format(z)
    elif z > 16:
        o = "Grade 16+"
    print(o)

main()
