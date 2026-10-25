import tkinter as tk
import random
import string

def generate_password():
    try:
        length = int(length_entry.get())
    except ValueError:
        result_label.config(text="Enter a valid number")
        return

    if var.get() == "numeric":
        characters = string.digits
    else:
        characters = string.ascii_letters + string.digits + string.punctuation

    password = ''.join(random.choice(characters) for _ in range(length))
    result_label.config(text=password)

def copy_to_clipboard(event):
    root.clipboard_clear()
    root.clipboard_append(result_label.cget("text"))
    result_label.config(text="Copied to clipboard!")

# GUI setup
root = tk.Tk()
root.title("Password Generator")
root.geometry("350x250")

tk.Label(root, text="Password Length:").pack(pady=5)
length_entry = tk.Entry(root)
length_entry.pack()

var = tk.StringVar(value="mixed")
tk.Radiobutton(root, text="Numeric Only", variable=var, value="numeric").pack()
tk.Radiobutton(root, text="Mixed Characters", variable=var, value="mixed").pack()

tk.Button(root, text="Generate Password", command=generate_password).pack(pady=10)

result_label = tk.Label(root, text="", fg="blue", cursor="hand2", wraplength=300)
result_label.pack(pady=10)
result_label.bind("<Button-1>", copy_to_clipboard)

tk.Label(root, text="(Click password to copy)").pack()

root.mainloop()