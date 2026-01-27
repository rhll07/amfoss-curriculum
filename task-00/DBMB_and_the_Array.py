t=int(input())
o=[]
for _ in range(t):
    test_arr=list(input().split())
    n=int(test_arr[0])
    s=int(test_arr[1])
    x=int(test_arr[2])
    arr=list(input().split())
    arr_sum=0
    for i in range(n):
        arr[i]=int(arr[i])
    arr_sum=sum(arr)
    if arr_sum<=s and (s-arr_sum)%x==0:
        o.append("YES")
    else:
        o.append("NO")
for j in o:
    print(j)