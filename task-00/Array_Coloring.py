t=int(input())
answers=[]
for _ in range(t):
    n=int(input())
    l=input().split()
    a=[]
    for i in l:
        a.append(int(i))
    colour={}
    rn="red"
    for j in a:
        colour[j]=rn
        if rn=="red":
            rn="blue"
        else:
            rn="red"
    b=a.copy()
    b.sort()
    exists=True
    for k in range(n-1):
        if colour[b[k]] == colour[b[k+1]]:
            exists=False
            break
    if exists:
        answers.append("YES")
    else:
        answers.append("NO")
for ans in answers:
    print(ans)
