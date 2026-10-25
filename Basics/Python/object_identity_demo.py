a=3
c=6
print(id(a))
def check(number):
    print(id(a))
    return c
b= check("number")
a=a+a
print(id(a))

print(id(b))
d=[2,4,5,6]

print(id(d))
def check(number):
    print(id(d))
    d.append(7)
    return d
   
print(id(d))
check("number")
print(id(d))
print(d)

