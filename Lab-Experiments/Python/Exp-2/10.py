print("A\tB\tA & B\tA | B\tA ^ B")

print(f"{0}\t{0}\t{0 & 0}\t{0 | 0}\t{0 ^ 0}")
print(f"{0}\t{1}\t{0 & 1}\t{0 | 1}\t{0 ^ 1}")
print(f"{1}\t{0}\t{1 & 0}\t{1 | 0}\t{1 ^ 0}")
print(f"{1}\t{1}\t{1 & 1}\t{1 | 1}\t{1 ^ 1}")
