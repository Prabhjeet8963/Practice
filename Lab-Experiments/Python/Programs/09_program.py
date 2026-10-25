#Factorial of a number:
n = int(input("Enter a number: "))
factorial = 1
for i in range(1, n+1):
 factorial *= i
 print(f"Factorial of {n} is {factorial}")

"""Output:
Enter a number: 5
Factorial of 5 is 120"""

