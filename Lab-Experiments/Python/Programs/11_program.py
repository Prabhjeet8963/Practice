N = int(input("Enter a number: "))
count = 0
num = 2
print(f"First {N} prime numbers:")
while count < N:
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            break
    else:
        print(num, end=" ")
        count += 1
    num += 1

"""Enter a number: 5  
First 5 prime numbers: 2 3 5 7 11  """