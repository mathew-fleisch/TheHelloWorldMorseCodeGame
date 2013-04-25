
/* http://en.wikipedia.org/wiki/Morse_code */
//Sparkfun DesignWest 2013 Callenge
//Author: Mathew Fleisch
//Title: The "Hello World" Morse Code Game
//This program uses Sparkfun's ProtoSnap board or other arduino board
//with a button, buzzer, and rgb led attached to the specified pins below.
//The concept of the program is to input morse code via a button, and have
//a function encode, then decode a sequence of 1-5 button presses into 
//an english character. The letter is then printed to the serial monitor
//and a green light blips, if a character is correctly identified; a red
//light blips and an error is printed to the serial monitor, if no match
//was found. To make game around only using the board, a user can spell
//"hello world" and a different tone will play, as well as a chromatic-
//like tone-blips as each letter is spelled correctly. If the user spells
//the target word (target because you the programmer, can change "hello 
//world" to any other string of chars) incorrectly, they have to start
//at the beginning of the game, with the first letter.
//Note: My button and RGB LED were both backwards via code, so you might
//      need to adjust some variables to get your board to work correctly.
//      (0 == Pressed, 1 == Not Pressed for buttons; and HIGH on the RGB
//      LED meant off in my tests) I included comments and left the 
//      important traces commented out in the following code, so that you
//      can debug the code easier, for your system.
//I don't know morse code, and this is my first project, so I apologize
//if I accidentally duplicated somebody else's game/program and/or if I
//did something silly or wrong. I hope you enjoy and can rerun my code
//on your own board.
//~Mathew

const int buttonPin = 7;
const int tonePin =  2; 
const int ledPin = 13;
const int greenPin = 5;
const int redPin = 3;
const int tonePitch = 440;
const int delayTime = 40; //Minimum time between sequences
const char letters[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
const int* mcode[36];
const int mcode0[5]  = {1, 2, 0, 0, 0}; //a
const int mcode1[5]  = {2, 1, 1, 1, 0}; //b
const int mcode2[5]  = {2, 1, 2, 1, 0}; //c
const int mcode3[5]  = {2, 1, 1, 0, 0}; //d
const int mcode4[5]  = {1, 0, 0, 0, 0}; //e
const int mcode5[5]  = {1, 1, 2, 1, 0}; //f
const int mcode6[5]  = {2, 2, 1, 0, 0}; //g
const int mcode7[5]  = {1, 1, 1, 1, 0}; //h 
const int mcode8[5]  = {1, 1, 0, 0, 0}; //i
const int mcode9[5]  = {1, 2, 2, 2, 0}; //j
const int mcode10[5] = {2, 1, 2, 0, 0}; //k
const int mcode11[5] = {1, 2, 1, 1, 0}; //l
const int mcode12[5] = {2, 2, 0, 0, 0}; //m
const int mcode13[5] = {2, 1, 0, 0, 0}; //n
const int mcode14[5] = {2, 2, 2, 0, 0}; //o
const int mcode15[5] = {1, 2, 2, 1, 0}; //p
const int mcode16[5] = {2, 2, 1, 2, 0}; //q
const int mcode17[5] = {1, 2, 1, 0, 0}; //r
const int mcode18[5] = {1, 1, 1, 0, 0}; //s
const int mcode19[5] = {2, 0, 0, 0, 0}; //t
const int mcode20[5] = {1, 1, 2, 0, 0}; //u
const int mcode21[5] = {1, 1, 1, 2, 0}; //v
const int mcode22[5] = {1, 2, 2, 0, 0}; //w
const int mcode23[5] = {2, 1, 1, 2, 0}; //x
const int mcode24[5] = {2, 1, 2, 2, 0}; //y
const int mcode25[5] = {2, 2, 1, 1, 0}; //z

const int mcode26[5] = {1, 2, 2, 2, 2}; //1
const int mcode27[5] = {1, 1, 2, 2, 2}; //2
const int mcode28[5] = {1, 1, 1, 2, 2}; //3
const int mcode29[5] = {1, 1, 1, 1, 2}; //4
const int mcode30[5] = {1, 1, 1, 1, 1}; //5
const int mcode31[5] = {2, 1, 1, 1, 1}; //6
const int mcode32[5] = {2, 2, 1, 1, 1}; //7
const int mcode33[5] = {2, 2, 2, 1, 1}; //8
const int mcode34[5] = {2, 2, 2, 2, 1}; //9
const int mcode35[5] = {2, 2, 2, 2, 2}; //0

int charsInGame = 10;
char game[] = "helloworld";
int crnt = 0;

int buttonState = 0;
int delayTrack = 0;
int tmpSeq[5];
int seqIndex = 0;

void setup() {
  pinMode(tonePin, OUTPUT);  
  pinMode(ledPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  mcode[0]  = mcode0;
  mcode[1]  = mcode1;
  mcode[2]  = mcode2;
  mcode[3]  = mcode3;
  mcode[4]  = mcode4;
  mcode[5]  = mcode5;
  mcode[6]  = mcode6;
  mcode[7]  = mcode7;
  mcode[8]  = mcode8;
  mcode[9]  = mcode9;
  mcode[10] = mcode10;
  mcode[11] = mcode11;
  mcode[12] = mcode12;
  mcode[13] = mcode13;
  mcode[14] = mcode14;
  mcode[15] = mcode15;
  mcode[16] = mcode16;
  mcode[17] = mcode17;
  mcode[18] = mcode18;
  mcode[19] = mcode19;
  mcode[20] = mcode20;
  mcode[21] = mcode21;
  mcode[22] = mcode22;
  mcode[23] = mcode23;
  mcode[24] = mcode24;
  mcode[25] = mcode25;
  mcode[26] = mcode26;
  mcode[27] = mcode27;
  mcode[28] = mcode28;
  mcode[29] = mcode29;
  mcode[30] = mcode30;
  mcode[31] = mcode31;
  mcode[32] = mcode32;
  mcode[33] = mcode33;
  mcode[34] = mcode34;
  mcode[35] = mcode35;
  Serial.begin(9600);
}
void loop(){  
  //My button was backwards (0 == Pressed, 1 == Not Pressed), 
  //so remove the bangs in front of the var 'buttonState', 
  //if your button works correctly.
  buttonState = digitalRead(buttonPin);
  
  //My LEDs were also backwards, so I set them to "HIGH" to turn them off
  //You will need to invert HIGH/LOW for red/green pins, if your LEDs act normally.
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  int timeTrack = 0;
  int stopSequence = 0;
  

  if (!buttonState) {
    //While the button is pressed, keep track of how much time has passed and play a tone.
    while(!buttonState) {
      //the debug light works normally
      digitalWrite(ledPin, HIGH); 
      tone(tonePin, tonePitch); 
      timeTrack++;
      delay(10);
      buttonState = digitalRead(buttonPin);
    }
    
    /*
    //This trace will tell you how long the button has been pressed so far
    Serial.print("Length: ");
    Serial.print(timeTrack);
    Serial.println("");  
    */
    if(!stopSequence) {
      if(timeTrack < 20) {
        //The button has been pressed for less than 20 units, so record a "dit" or 1
        //Serial.println("dit");
        tmpSeq[seqIndex] = 1;
      } else {
        //The button has been pressed for more than 20 units, so record a "dah" or 2
        //Serial.println("dah");
        tmpSeq[seqIndex] = 2; 
      }
      seqIndex++;  
    } 
    digitalWrite(ledPin, LOW); 
    noTone(tonePin); 

  } else {
    delayTrack = 0;
    while(buttonState) {
      delayTrack++;
      delay(10);
      buttonState = digitalRead(buttonPin); 
      if(delayTrack) { 

        if(delayTrack > delayTime || seqIndex > 4) {
          stopSequence = 1;
          /* 
          Serial.print("Delayed: ");
          Serial.print(delayTrack);
          Serial.println("");
          */       
        } else {
          stopSequence = 0; 
        }
        if(stopSequence) {
          int i;
          //this loop sets the rest of the temp sequence to 0
          for(i = seqIndex; i < 5; i++) { tmpSeq[i] = 0; }
          
          /*
          //This trace will loop through the temp sequence, 
          //and print 1, 2 or 0 (dit, dah, empty)
          for(i = 0; i < 5; i++) {
            if(tmpSeq[0]) {
              Serial.print(tmpSeq[i]);
              if(i != 4) { 
                Serial.print(",  ");
              }
            }
          }
          if(tmpSeq[0]) { Serial.println(""); }
          */
          if(tmpSeq[0]) {
            int crntLetter = getLetter(tmpSeq);
            if(crntLetter > -1) {
              digitalWrite(greenPin, LOW);
              delay(100);
              digitalWrite(greenPin, HIGH);
              Serial.print(letters[crntLetter]);
              if(letters[crntLetter] == game[crnt]) {
                tone(tonePin, (crnt*100), 30);
                crnt++;
                if(crnt == charsInGame) {
                  digitalWrite(greenPin, LOW);
                  tone(tonePin, 880, 500);
                }
              } else {
                crnt = 0;
              }
              if(crnt) {
                Serial.print(" +");
              }
              Serial.println("");
            } else {
              tone(tonePin, 100, 100);
              digitalWrite(redPin, LOW);
              delay(100);
              digitalWrite(redPin, HIGH);
              Serial.println("Could not find match...");
            }
          }
          seqIndex = 0;
        }
      }
    }
    digitalWrite(ledPin, LOW); 
    noTone(tonePin);
  }
}

int getLetter(int tmpSeq[5]) {
  int j,k,found;
  found = -1;
    for(j = 0; j < 36; j++) { //letters array
      for(k = 0; k < 5; k++) { //blips from individual letter
            /*
            //This trace will show you each comparison before it happens, for each letter
            Serial.print(letters[j]);
            Serial.print(": ");
            Serial.print(mcode[j][k]);
            Serial.print(" ?= ");
            Serial.print(tmpSeq[k]);
            */
          if(mcode[j][k] == tmpSeq[k]) { 
            //Serial.print(" True");
          } else { 
            //Serial.print(" False");
            //Serial.println("");
            break;
          }
          //Serial.println("");
          
          //The loop has gone all the way through the target sequence, 
          //without throwing a false, so letters[j] must be the target letter
          if(k == 4) {
            found = j;
            break;
          }
      }
    }
  //Serial.println("");
  return found;
}
