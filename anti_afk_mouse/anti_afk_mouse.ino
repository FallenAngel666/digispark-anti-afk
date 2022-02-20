// Anit AFK script for DigiSpark
// Author: Luziferus

#include <DigiMouse.h>

// Configurations
#define MOUSE_MOVE_RADIUS 128 // pixel
#define MOUSE_DELAY_MIN 2000 // ms
#define MOUSE_DELAY_MAX 5000 // ms

// Apply for your current display resolution
#define RESOLUTION_X 1920 
#define RESOLUTION_Y 1080

// You should not change anything below
#define LED 1

int center_x = RESOLUTION_X / 2;
int center_y = RESOLUTION_Y / 2;

int last_position_x = center_x;
int last_position_y = center_y;

void setup() {
  DigiMouse.begin();
  center();

  randomSeed(analogRead(1));
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 0);
}

void loop() {
  DigiMouse.update();
  
  moveToNextPoint();
  mouseClick();
  DigiMouse.delay(random(MOUSE_DELAY_MIN, MOUSE_DELAY_MAX));

  moveBack(); // recenter again
  DigiMouse.delay(random(MOUSE_DELAY_MIN, MOUSE_DELAY_MAX));
  moveBack(); // run back to position
  mouseClick(); 
  
  DigiMouse.delay(random(MOUSE_DELAY_MIN, MOUSE_DELAY_MAX));
  moveWithLastPosition(); // recenter again
  DigiMouse.delay(random(MOUSE_DELAY_MIN, MOUSE_DELAY_MAX));
}

void moveToNextPoint() {
  last_position_x = random(-MOUSE_MOVE_RADIUS, MOUSE_MOVE_RADIUS);
  last_position_y = random(-MOUSE_MOVE_RADIUS, MOUSE_MOVE_RADIUS);

  DigiMouse.moveX(last_position_x);
  DigiMouse.moveY(last_position_y);
}

void moveBack() {
  DigiMouse.moveX(last_position_x * -1);
  DigiMouse.moveY(last_position_y * -1);
}

void moveWithLastPosition() {
  DigiMouse.moveX(last_position_x);
  DigiMouse.moveY(last_position_y);
}

void center() {
  // go out of the screen
  for(int x = 0; x < RESOLUTION_X + 100; x += 100) {
    DigiMouse.moveX(-100);
    DigiMouse.update();
    DigiMouse.delay(100);
  }

  for(int y = 0; y < RESOLUTION_Y + 100; y += 100) {
    DigiMouse.moveY(-100);
    DigiMouse.update();
    DigiMouse.delay(100);
  }

  DigiMouse.delay(1000);
  DigiMouse.update();

  for(int x = 0; x <= center_x; x+=10) {
    DigiMouse.moveX(10);
    DigiMouse.delay(50);
    DigiMouse.update();
  }

  for(int y = 0; y <= center_y; y+=10) {
    DigiMouse.moveY(10);
    DigiMouse.delay(50);
    DigiMouse.update();
  }
  
  DigiMouse.delay(1000);
  DigiMouse.update();
}

void mouseClick() {
  digitalWrite(LED, 1);
  DigiMouse.setButtons(1<<0); 
  DigiMouse.delay(10);
  DigiMouse.setButtons(0);
  DigiMouse.delay(250);
  digitalWrite(LED, 0);
}
