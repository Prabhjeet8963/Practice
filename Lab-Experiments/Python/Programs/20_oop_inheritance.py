class Parent:
    def __init__(self):
        self.common = "Common Attribute"
    
    def show(self):
        print("Parent method")

class Child1(Parent):
    def child_method(self):
        print("Child1 method")

class Child2(Parent):
    def child_method(self):
        print("Child2 method")

c1 = Child1()
c2 = Child2()
c1.show()
c1.child_method()
c2.show()
c2.child_method()
print(c1.common)
print(c2.common)