import sys

input = sys.stdin.readline

n = int(input())

grades = list(int(x) for x in input().split())

grades.sort()

grades.pop(0)
grades.pop()

sum = 0

for grade in grades:
    sum += grade

print(sum//len(grades))