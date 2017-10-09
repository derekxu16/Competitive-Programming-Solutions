import sys

input = sys.stdin.readline

flakes = set()


def answer():
    for x in range(int(input())):
        current = tuple(sorted([int(x) for x in input().split()]))
        if current in flakes:
            return ("Twin snowflakes found.")
        else:
            flakes.add(current)
    return ("No two snowflakes are alike.")

print(answer())
