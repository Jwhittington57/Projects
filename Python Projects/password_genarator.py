import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters = int(input("How many letters would you like in your password?\n"))
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))

password = ""


for num in range(0, nr_letters):#uses the users input to create a range 0 -nth
    password += (letters[random.randint(0,52)])
#this then appends random letters from the letters list to the password variable
for num in range(0, nr_numbers):
     password += (numbers[random.randint(0,9)])

for num in range(0, nr_symbols):
    password +=(symbols[random.randint(0,8)])

l = list(password) #converts the password to a list
random.shuffle(l) #shuffles the list
result= ''.join(l) #turns the list back to a string joining them together
print(result)