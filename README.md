# Scrabble

This is a command line version of scrabble

Upon starting the game you are given the following options

1. New Game
2. Settings
3. Add Word
4. Exit

Choosing 1 will start a new game for the chosen(or default) number of rounds and letters. Random letters will be genereted and printed 

  Round 1. Available letters: x a i r o e z x e m

From which you can make a word

  air (the word we have chosen)
  Score: 3
  Round 2. Available letters: x a i r o e z x e m

You can only use the letters available, and as many times as the letter is given(per round, meaning that you can use the same letter on the next round)
You cannot use the same word in multiple rounds. The number of points is equal to the number of letters used

Using an invalid/used word or using invalid letters will give you a proper messege and you can replay the round(there is not point deduction)

The game finishes when all rounds have been passed. You see your score and you go back to the main menu


Choosing 2(Settings) will give you these options :
1. Change Number of Letters
2. Change Number of Rounds

The number of letters can be an integer between 1 and 26. Default is 10
The number of rounds can be an integer between 1 and 30. Default is 10


Choosing 3(Add word) lets you add any word to the game. If the word already exists nothing will change. Added words are saved in the file and will be available if
if you quit the program the run it again.


Choosing 4 will quit the program.

