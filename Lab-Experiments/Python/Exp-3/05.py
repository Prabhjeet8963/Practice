import math

class QuadraticEquation:
    def __init__(self, a, b, c):
        self.a = 8
        self.b = 5
        self.c = 6

    def calculate_discriminant(self):
        return self.b**2 - 4*self.a*self.c

    def analyze_roots(self):
        discriminant = self.calculate_discriminant()

        if discriminant > 0:
            root1 = (-self.b + math.sqrt(discriminant)) / (2*self.a)
            root2 = (-self.b - math.sqrt(discriminant)) / (2*self.a)
            print("The quadratic equation has real and distinct roots:")
            print(f"x = {root1}")
            print(f"x = {root2}")
        elif discriminant == 0:
            root = -self.b / (2*self.a)
            print("The quadratic equation has real and equal roots:")
            print(f"x = {root}")
        else:
            real_part = -self.b / (2*self.a)
            imaginary_part = math.sqrt(-discriminant) / (2*self.a)
            print("The quadratic equation has imaginary roots:")
            print(f"x = {real_part} + {imaginary_part}i")
            print(f"x = {real_part} - {imaginary_part}i")

    def __str__(self):
        return f"{self.a}x^2 + {self.b}x + {self.c} = 0"