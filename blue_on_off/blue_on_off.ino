#include "Keyboard.h"

char winKey = KEY_LEFT_GUI;

char ctrlKey = KEY_LEFT_CTRL;
char altKey = KEY_LEFT_ALT;
char delKey = KEY_DELETE;



void setup() {
  Serial1.begin(9600); // Bluetooth communications
  Serial.begin(9600); // USB communications
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Arduino Micro
  }
  Serial.println("Serial connection made (Arduino --> USB)");
  
  while (!Serial1) {
    ; // wait for serial1 port to connect. Needed for Arduino Micro
  }
  Serial.println("Serial 1 connection made (Arduino <--> Bluetooth)");
    Keyboard.begin();
}

void loop() {
  if (Serial1.available() > 0) {
    byte b = Serial1.read();
    String quote = "'";
  Serial.println(b); 
  if (b==49)
  {
   Serial.println("Presed - winKey+l");  
    Keyboard.press(winKey);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
  }
  else if(b==50)
  {
      Keyboard.press(ctrlKey);
       Keyboard.press(altKey);
        Keyboard.press(delKey);
         Keyboard.releaseAll();
           delay(1000);
      Keyboard.print("QWE987qwe987");
      Keyboard.write(KEY_RETURN);
      
    }
    
  }
  
}
