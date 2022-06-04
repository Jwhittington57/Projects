print("Welcome to the tip calculator!")
bill = float(input("What was the total bill? $"))
tip = int(input("What percentage tip would you like to give? 10 12 15 "))
people = int(input("How many people to split the bill? "))

convertTip=  float(tip / 100 + 1) #converts amount to be tipped to a percent
calc = float((bill/people) * convertTip) #converts what each person should pay
totalTipped = bill *(tip/100)

print(f"Your total is:  {round(calc, 2)}  you're tipping: {totalTipped}" )

