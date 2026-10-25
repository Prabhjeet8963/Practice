sec = float(input("Enter seconds: "))
hour, min = 0, 0

if sec <= 3600:
    min = sec / 60
else:
    hour = sec // 3600
    min = (sec % 3600) / 60

print("Hours:", hour, "Minutes:", min)
