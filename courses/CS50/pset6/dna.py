#!/usr/bin/env python3

import sys
import json


def main():
    if len(sys.argv) != 3:
        print("Usage: {} {} {}".format(sys.argv[0], "databases/small.csv", "sequences/1.txt"))

    # init: sample
    repeats = []
    repeat_hash = {}
    for line in open(sys.argv[1]):
        if line.startswith("name"):
            header = line.strip().split(",")
            repeats = header[1:]
        else:
            arr = line.strip().split(",")
            k = []
            for i, j in enumerate(header):
                if i == 0:
                    continue
                else:
                    _ = j + ":" + arr[i]
                    k.append(_)
            k = "_".join(k)
            repeat_hash[k] = arr[0]
    repeat_counter = {_: [] for _ in repeats}

    # init: sequence
    sequence = open(sys.argv[2]).readlines()[0].strip()

    # count
    key = []
    for x in repeats:
        _ = x + ":" + str(sequence.count(x))
        key.append(_)
    key = "_".join(key)
    print(key)
    print(json.dumps(repeat_hash,indent=4))
    # return
    if key in repeat_hash:
        o = repeat_hash[key]
    else:
        o = "No match"
    print(o)


main()
