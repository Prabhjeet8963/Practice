name=input("Enter a string")
found_upper = False  

for char in name:
    if(char.isupper()):
       print(char)
       found_upper=True
    else:
        print("no upper digitts are present")