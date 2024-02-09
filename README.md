# Tournament-Battle-Game (C++)

## Description
A tournament style game, which focuses on object-oriented principles, has a user player that generates a player of customizable attributes, selectable weapon and armour, which then is matched randomly against computer generated players with wide variety of attributes. The player will battle the computer players and based on their attributes, weapon and armour choices, will move to the next round. The user will battle in 3 rounds including a final battle to eventually win, if a balanced amount of points is allocated for their attributes and they can select strong enough armour and weapons.

## How to Run
To create the game files, one simply needs to run:
```
make
```
which will run the makefile and will compile all of the required code.
Once the code has been successfully compiled, simlply run:
```
./main
```
and the game will run. 

## How to Play
The user will first be asked:
```
Enter your name:
```
to which the user will enter their name and the game will begin. The user will then be presented with the ability to choose their attributes. These attributes are split across 3 different areas; Strength, Speed and Drip. The user has the option to allocate 15 points total across the three areas, so the user needs to think wisely about where they allocate their stats. They will be presented with these prompts:
```
Enter your desired strength between 0 and 15: 3     #selecting three for the strength
Enter your desired speed between 0 and 12: 10       #selecting 10 for the speed
Enter your desired drip of 2 for your drip: 2       #selecting the remaining 2 for the drip
```
Once the user has selected their stats, they will then select their weapon and armour from the prompts as such:
```
Please choose which type of weapon you would like
For a heavy weapon, press 1
   ,  /\  .  
  //`-||-'\\ 
 (| -=||=- |)
  \\,-||-.// 
   `  ||  '  
      ||     
      ||     
      ||     
      ||     
      ||     
      ()


For a light weapon, press 2
     _____
     \___/
      \_/
      |_|
      |_|     
      |_|
      |_|
     [ | ]      
     | | |
     | | |
     | | |
     | | |
     | | |
     | | |
     \ | /
      \ /
       V 
             

For a range weapon, press 3
      ()
       \\
        \\
         ))   
  ###=========>       
         ))
        //
       //
      ()

Please choose which type of armour you would like
For Leather, press 1
For Gold, press 2
For Chain, press 3
For Diamond, press 4
For Iron, press 5
For Netherite, press 6
```
Once these are all selected, the user will then battle against random computer players, with the option to attack on their turn, and then either attempt to block or take a hit on the opponents turn. Warning: choosing to block may only work sometimes, and a failed block will result in increase of damage taken.
The user will be prompted as follows:
```
Press 1 for your opponent to take their turn
Press 2 to block (choose with caution)
```
The user will also be prompted to attack, or they may choose to leave the game. This process will repeat until one player is defeated. If the user wins, they will be prompted to go through to the next battle. This is repeated until the tournament ends and either the user is the winner, or the user is defeated and the game ends.
