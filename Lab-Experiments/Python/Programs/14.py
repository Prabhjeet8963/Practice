def sum_digits(n):
    return sum(int(digit) for digit in str(n))

num = int(input("Enter a number: "))
print(f"Sum of digits: {sum_digits(num)}")
"""Enter a number: 456  
Sum of digits: 15  """