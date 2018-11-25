import sys
from math import ceil

input = sys.stdin.readline

n, q = map(int, input().split())

words = []
for i in range(n):
    words.append(input().strip())
words.sort()
wordInd = {}
for i in range(len(words)):
    wordInd[words[i]] = i+1

for i in range(q):
    w, p = input().split()
    p = int(p)

    print(ceil(wordInd[w]/p))