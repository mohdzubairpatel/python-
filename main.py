import random

computer=random.choice([1,0,-1])

'''
enter s for snake
enter w for water 
enter g for gun

'''

yourdict={"s":-1,"w":1,"g":0}
reversedict={-1:"snake",1:"water",0:"gun"}

your=input("enter your choice:")
you=yourdict[your]
print(f"you choosen {reversedict[you]}\ncomputer choosen {reversedict[computer]}")
if you == computer:
    print("match drawn")
else:
    if you==-1 and computer==1:   #-1-1=-2
       print("you win!")
    elif you==1 and computer==-1: # 1-(-1)=2
        print("you loose!")
    elif you==-1 and computer==0: # -1-0=-1
         print("you loose!")
    elif you==1 and computer==0: #1-0=1
         print("you win!")
    elif you==0 and computer==1: #0-1=-1
         print("you loose!")
    elif you==0 and computer==-1: # 0-(-1)=1
         print("you win!")
    else:
        print("incorrect chioce!")
    
    