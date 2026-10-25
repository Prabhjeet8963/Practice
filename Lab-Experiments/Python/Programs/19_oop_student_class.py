class Student:
    branch = "Btech Electronic & Communication Engineering"
    
    def input_details(self):
        self.name = input("Enter name: ")
        self.roll = input("Enter roll number: ")
    
    def show_details(self):
        print("Name:", self.name)
        print("Roll:", self.roll)
        print("Branch:", self.branch)

s = Student()
s.input_details()
s.show_details()