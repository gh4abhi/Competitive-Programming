// Problem Link - https://www.hackerrank.com/challenges/defaultdict-tutorial/problem?isFullScreen=true

from collections import defaultdict
n,m = map(int, input().split())
i = 0;
gA = {}
for j in range(n):
    a = input()
    if(a not in gA.keys()):
        gA.update({a:[]})
    gA[a].append(i)    
    i = i+1
for i in range(m):
    a = input()
    if a not in gA.keys():
        print(-1,end=' ')
    else:
        for j in gA[a]:
            print(j+1,end = ' ')
    print()            
