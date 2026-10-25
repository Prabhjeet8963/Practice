def find_max_min(numbers):
    return max(numbers), min(numbers)

n = int(input("How many numbers? "))
numbers = [float(input(f"Enter number {i+1}: ")) for i in range(n)]
max_num, min_num = find_max_min(numbers)
print(f"Max: {max_num}, Min: {min_num}")

"""Enter numbers (space-separated): 1 2 3 4 5  
Max: 5.0, Min: 1.0  """