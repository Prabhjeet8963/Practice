with open("student.txt", "w") as f:
    f.write(input("Enter roll number: ") + "\n")
    f.write(input("Enter name: ") + "\n")

with open("student.txt", "r") as f:
    print("\nDetails:")
    print(f.read())

"""Enter roll number: 241612044042
Enter name: Divyanka vidyarthi

 Details:
241612044042
Divyanka vidyarthi"""