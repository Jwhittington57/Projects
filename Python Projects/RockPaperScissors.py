import random
from random import choice

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''
options =[rock, paper, scissors]
computer_choice = random.choice(options)

user_choice = int(input("choose 0 for rock, 1 for paper or 2 for scissors\n"))
if user_choice > 2 or user_choice < 0:
    print("invaid option, you lose.")
    quit()

if user_choice == 0:
    print("you've chose rock " + options[user_choice])
    user_choice = options[0]

if user_choice == 1:
    print("you've chose paper " + options[user_choice])
    user_choice = options[1]
if user_choice == 2:
    print("you've chose scissors " + options[user_choice])
    user_choice = options[2]


computer_choice = random.choice(options)
if computer_choice == options[0]:
    print(f"computer chose rock {computer_choice}")
if computer_choice == options[1]:
    print(f"computer chose paper {computer_choice}")
if computer_choice == options[2]:
    print(f"computer chose scissors {computer_choice}")


#all possiblites regarding rock
if user_choice == options[0] and computer_choice == options[0]: #both choose rock
    print("its a draw")

if user_choice == options[0] and computer_choice == options[1]: #user picks rock cpu picks paper
    print("cpu wins. Paper beats rock")
if user_choice == options[0] and computer_choice == options[2]: # user picks rock & cpu picks scissor
    print("you win. rock beats scissors")

# all possiblites regarding paper
if user_choice == options[1] and computer_choice == options[1]:  # both choose paper
    print("its a draw")

if user_choice == options[1] and computer_choice == options[2]:  # user picks paper cpu picks scissor
    print("cpu wins. scissors beats paper")

if user_choice ==options [1] and computer_choice == options[0]:  # user picks paper & cpu picks rock
    print("you win. paper beats rock")

# all possiblites regarding scissor
if user_choice == options[2] and computer_choice == options[2]:  # both choose scissor
    print("its a draw")

if user_choice == options[2] and computer_choice == options[0]:  # user picks scissor cpu picks rock
    print("cpu wins rock beasts, scissors")

if user_choice == options[2] and computer_choice == options[1]:  # user picks scissor & cpu picks paper
    print("you win scissors beat paper")
