t=int(input())
o=[]
for _ in range(t):
    n=int(input())
    arr=list(input().split())
    for i in range(n):
        arr[i]=int(arr[i])
    mxp=0
    for i in range(n):
        for j in range(i,n):
            arr[i],arr[j]=arr[j],arr[i]
            prfxmx=0
            sum=0
            for k in range(n):
                if arr[k]>prfxmx:
                    prfxmx=arr[k]
                sum+=prfxmx
            if sum>mxp:
                mxp=sum
            arr[i],arr[j]=arr[j],arr[i]
    o.append(str(mxp))
for l in o:
    print(l)
