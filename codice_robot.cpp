#include <Servo.h> // Include servo library 

 

Servo servoRight; // Declare right servo 

Servo servoLeft; // Declare right servo 

 

void muovi(String direzione, int tempo) { 

  if (direzione == "avanti") { 

    servoRight.writeMicroseconds(1300); 

    servoLeft.writeMicroseconds(1700); 

  }  

  else if (direzione == "indietro") { 

    servoRight.writeMicroseconds(1700); 

    servoLeft.writeMicroseconds(1300); 

  } else if (direzione == "sinistra") { 

    servoRight.writeMicroseconds(1300); 

    servoLeft.writeMicroseconds(1300); 

  } else if (direzione == "destra") { 

    servoRight.writeMicroseconds(1700); 

    servoLeft.writeMicroseconds(1700); 

  } 

  delay(tempo); 

} 

void verifica_motori (){ 

    servoRight.writeMicroseconds(1500); 

    servoLeft.writeMicroseconds(1500);    

    delay(900000000); 

} 

void quadrato_destra(){ 

  for(int i = 0; i<4;i++){ 

  muovi("avanti",3000); 

  muovi("destra",600); 

  }   // fa andare avanti e girare perfettamente di 90 gradi robottino per farli fare un qudrato 

} 

 

void setup() { 

  servoRight.attach(11); // Attach right signal to pin 12 

  servoLeft.attach(10); 

 

  quadrato_destra(); 

  verifica_motori(); 

 

  servoRight.detach(); // Attach right signal to pin 12 

  servoLeft.detach(); 

} 

void loop() // Main loop auto-repeats 

{ // Empty, nothing needs repeating 

} 