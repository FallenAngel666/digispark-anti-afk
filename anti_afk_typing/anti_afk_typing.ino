#include <DigiKeyboard.h>

// Configurations
#define MIN_TYPING_DELAY 200 //ms
#define MAX_TYPING_DELAY 400 //ms

#define DELETE_WRITTEN_TEXT true
#define MIN_TEXT_SIE 32 // chars // if DELETE_WRITTEN_TEXT
#define MAX_TEXT_SIZE 64 // chars // if DELETE_WRITTEN_TEXT

String alpha = " qwertzuiopasdfghjklyxcvbnm "
               " 1234567890 "
               " QWERTZUIOPASDFGHJKLYXCVBNM "
               // "\n" // enable if you want to have new lines
               " qwertzuiopasdfghjklyxcvbnm ";

// You should not change anything below
#define LED 1

int ledBlinkTime = 250; // ms
int currentMaxTextSize = MIN_TEXT_SIE;
int currentTextSize = 0;

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(250);
  resetTextSize();
  randomSeed(analogRead(1));

  pinMode(LED, OUTPUT);
  digitalWrite(LED, 0);

  if(ledBlinkTime > MIN_TYPING_DELAY) {
    ledBlinkTime = MIN_TYPING_DELAY / 2;
  }
}

void loop() {
  if(DELETE_WRITTEN_TEXT) {
    if(currentTextSize > currentMaxTextSize) {
      deleteWrittenText();
      resetTextSize();
    }
  }
  
  printRandomCharacter();
  delayRandomTypingTime();
}

void printRandomCharacter() {
  digitalWrite(LED, 1);
  if(DELETE_WRITTEN_TEXT) {
    currentTextSize++;
  }

  DigiKeyboard.print(alpha.charAt(random(0, alpha.length() - 1)));
  DigiKeyboard.delay(ledBlinkTime);
  digitalWrite(LED, 0);
}

void delayRandomTypingTime() {
  DigiKeyboard.delay(random(MIN_TYPING_DELAY, MAX_TYPING_DELAY) - ledBlinkTime);
}

void resetTextSize() {
  currentMaxTextSize = random(MIN_TEXT_SIE, MAX_TEXT_SIZE);
  currentTextSize = 0;
}

void deleteWrittenText() {
  delayRandomTypingTime();
  DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
  DigiKeyboard.print("\b");
  delayRandomTypingTime();
}
