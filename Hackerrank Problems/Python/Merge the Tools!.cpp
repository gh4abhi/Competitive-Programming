// Problem Link - https://www.hackerrank.com/challenges/merge-the-tools/problem?isFullScreen=true

def merge_the_tools(string, k):
    l = []
    n = len(string)
    fact = n//k
    k1 = []
    ind = 0
    for i in string:
        ind = ind + 1
        k1.append(i)
        if(ind==k):
            ind = 0
            t = k1[:]
            l.append(t) 
            k1.clear()  
    for i in l:
        di = {}
        for j in i:
            if j not in di.keys():
                print(j,end='')
                di.update({j:1})           
        print()        
                  
    
    # print(l)        
        

if __name__ == '__main__':
