    T=int(raw_input())
    while T>0:
    N=int(raw_input())
    str1=raw_input()
    str2=raw_input()
    list1=[int(n) for n in str1.split(' ')]
    list1.sort()
    list2=[int(n) for n in str2.split(' ')]
    list2.sort()
    print sum(list1[i]*list2[i] for i in range(len(list1)))
    T-=1 
