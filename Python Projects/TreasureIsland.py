print(r'''
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\ ` . "-._ /_______________|_______
|                   | |o ;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/_____ /
*******************************************************************************
''')
print("Welcome to Treasure Island.\n")
print("Your mission is to find the treasure.\n")
print("After a monster storm you ship wreck on a mysterious island. "
      "You awake and see none of your crew. so "
      "you begin walking into the jungle to search for your shipmates. "
      "you come to a cross roads with two paths\n")
dec = input("left or right?")

if dec == "right":
    print("you fell into a hole with no way out. Game over")

if dec == "left":
    print("you slide down a muddy slope and splash into a river")
    dec = input("do you SWIM to land or WAIT to see where the current takes you ?")
    if dec == "wait":
        print("the river leads to a huge waterfall plunging you to a horde of rocks. GAME OVER")
    if dec == "swim":
        print("while swimming out of the river you see a small clearing with a building with 3 doors")
        dec = input("which door?(red, yellow, blue)")

        if dec == "red":
            print("the door explodes and you are burned by fire. GAME OVER")
        elif dec == "blue":
            print("A pack of wild beast burst out the door ravaging you. GAME OVER")

        elif dec == "yellow":
                print('you enter the structure it is completely dark. '
                      'you hear a voice call out "HELP ME, HELP ME PLEASE"')
                dec = input("GO to the voice, or EXIT out the Structure?")
                if dec == "exit":
                    print("while exiting the structure you trip on a rock back into the "
                          "river leading to a huge waterfall plunging you to a horde of rocks. GAME OVER")
                if dec == "go":
                    print("you discover one of your shipmates, he says he's been trapped in this structure for hours, "
                          "so he is sure this is where the treasure is located. "
                          "he just isn't sure how to solve the riddle...")
                    print("the riddle is a math problem: 3 * (3 + 3) / 3 - 3?")
                    dec = input("what is the answer?")
                    if dec != "3":
                        print('The building begins to shake '
                              'and rocks fall from the ceiling you\'re crushed by a rock. '
                              'GAME OVER')
                    if dec == "3":
                        print("The building shakes, a wall begins to rise "
                              "behind it you see a floating light that gets brighter "
                              "as you walk towards it.\n")
                        dec = input("do you REACH out for it or do you WALK past it down the hall")
                        if dec == "walk":
                            print("the light was blinding as you walked "
                                  "by and you couldn't see the trapdoor and "
                                  "fell into a pit of doom. GAME OVER ")

                        if dec == "reach":
                            print("as you grab the light. Everything goes dark. there is nothing. "
                                  "you close your eyes for a second and open them again to see "
                                  "you are back home as if nothing has happened. "
                                  "you open your hand to see priceless gym. YOU WIN")


        else:
            print("eaten by beasts, game over.")

    else:
        print("game over attacked by trout")

else:
    print("fall into hole gameOver")

