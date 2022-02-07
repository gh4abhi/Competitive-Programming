// Problem Link - https://www.hackerrank.com/challenges/word-order/problem?isFullScreen=true

n = int(input())
l = []
di  = {}
for i in range(n):
    s = input()
    if s not in di.keys():
        di.update({s:1})
        l.append(s)
    else:
        di[s] = di[s] + 1
print(len(l))
for i in l:
    print(di[i], end=' ')            
