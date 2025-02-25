This repository contains C code to build and run a paper scissors rock game on the ATmega32u2 microcontroller (UCFunkit)

The code uses various API functions defined by the University of Canterbury to aid in the making of this game.

make            --- builds the application for the ATmega32u2

make program    --- programs the application into the ATmega32u2 flash memory

make clean      --- deletes the object and executable files

make program will initialize a game of Rock-Paper-Scissors. The first screen prompts you to select how many rounds the game will be played for (1-9 rounds). Once the number of rounds is selected, the game begins. Move the navswitch North and West to navigate upwards through the choices, and South and   East to navigate downwards. After both players press the navswitch down to send their entries, the winner will see a "W" displayed on their screen, while the loser will see an "L". If both players send the same choice, they will both see a "T". If multiple rounds are selected, pressing button 1 will move on to the next round. Once all rounds are completed, if you win, a message will appear saying, "You Win! Won (number of wins)/(number of rounds)"; if you lose, it will say, "You Lose! Lost (number of losses)/(number of rounds)." 
