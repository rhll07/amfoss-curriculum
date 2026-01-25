t=int(input())
out=[]
if t>=1 and t<=20:
    for _ in range(t):
        n=int(input())
        if n>=1 and n<=20:
            s=1
            line=""
            for i in range(n):
                line+=str(s)+" "
                s+=1
            out.append(line.strip())
        else:
            out.append("Invalid number!")
    for line in out:
        print(line)
else:
    print("Invalid number!")
