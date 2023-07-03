n = int(input("Enter number of months(n): "))
k = int(input("Enter number of pairs produced(k): "))
count = 1
no_of_rabbits = []
i1 = 0
i2 = 1

while(count <= n):
    if count < 3:
        no_of_rabbits.append(1) # [1, 1]
    else:
        f1 = no_of_rabbits[i1]
        f2 = no_of_rabbits[i2]
        if i2 < 2:
            fn = f1 + f2 + k - 1
        else:
            fn = f1 + f2
        no_of_rabbits.append(fn)
        i1 = i1 + 1
        i2 = i2 + 1
    count = count + 1
print(no_of_rabbits)
print(f"Number of rabbit pairs at {n} month: {sum(no_of_rabbits) - 1}")