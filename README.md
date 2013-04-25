TheHelloWorldMorseCodeGame
==========================

Arduino game for Sparkfun's ProtoSnap

http://en.wikipedia.org/wiki/Morse_code
Sparkfun DesignWest 2013 Challenge
Author: Mathew Fleisch
Title: The "Hello World" Morse Code Game
This program uses Sparkfun's ProtoSnap board or other Arduino board
with a button, buzzer, and rgb led attached to the specified pins below.
The concept of the program is to input morse code via a button, and have
a function encode, then decode a sequence of 1-5 button presses into 
an english character. The letter is then printed to the serial monitor
and a green light blips, if a character is correctly identified; a red
light blips and an error is printed to the serial monitor, if no match
was found. To make game around only using the board, a user can spell
"hello world" and a different tone will play, as well as a chromatic-
like tone-blips as each letter is spelled correctly. If the user spells
the target word (target because you the programmer, can change "hello 
world" to any other string of chars) incorrectly, they have to start
at the beginning of the game, with the first letter.
Note: My button and RGB LED were both backwards via code, so you might
      need to adjust some variables to get your board to work correctly.
      (0 == Pressed, 1 == Not Pressed for buttons; and HIGH on the RGB
      LED meant off in my tests) I included comments and left the 
      important traces commented out in the following code, so that you
      can debug the code easier, for your system.
I don't know morse code, and this is my first project, so I apologize
if I accidentally duplicated somebody else's game/program and/or if I
did something silly or wrong. I hope you enjoy and can rerun my code
on your own board.
~Mathew
