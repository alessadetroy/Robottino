#include <Servo.h> // Include servo library 

Servo servoRight; // Servo destro 
Servo servoLeft;  // Servo sinistro 

// Pin sensori 
const int SENS_SXSX = A0; 
const int SENS_SX   = A1; 
const int SENS_CX   = A2; 
const int SENS_DX   = A3; 
const int SENS_DXDX = A4; 

// Funzione per muovere il robot 
void muovi(char direzione) { 
  if (direzione == 'a') {        // avanti 
    servoRight.writeMicroseconds(1400); 
    servoLeft.writeMicroseconds(1600); 
    delay(10);
  } else if (direzione == 's') { // sinistra 
    servoRight.writeMicroseconds(1400); 
    servoLeft.writeMicroseconds(1500); 
    delay(10);
  } else if (direzione == 'd') { // destra 
    servoRight.writeMicroseconds(1500); 
    servoLeft.writeMicroseconds(1600); 
    delay(10);
  } else if (direzione == 'x') { // stop 
    servoRight.writeMicroseconds(1500); 
    servoLeft.writeMicroseconds(1500); 
    delay(10);
  } 
} 

// Controlla se i sensori vedono la linea 
bool fermo_stop() { 
  int s1 = digitalRead(SENS_SXSX); 
  int s2 = digitalRead(SENS_SX); 
  int s3 = digitalRead(SENS_CX); 
  int s4 = digitalRead(SENS_DX); 
  int s5 = digitalRead(SENS_DXDX); 

  // Se tutti i sensori sono 0 (nero), fermati 
  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0) { 
    return false; 
  } 
  return true; 
} 

void verifica_motori (){   
    servoRight.writeMicroseconds(1500);   
    servoLeft.writeMicroseconds(1500);      
    delay(900000000);   
}   
// Segui la linea nera 
void segui_linea() {
  int s1 = digitalRead(SENS_SXSX); 
  int s2 = digitalRead(SENS_SX); 
  int s3 = digitalRead(SENS_CX); 
  int s4 = digitalRead(SENS_DX); 
  int s5 = digitalRead(SENS_DXDX);

  if (fermo_stop() == true) { 

    if (s3 == 0 && s2 == 1 && s4 == 1) {    // Linea al centro → vai dritto 
      muovi('a'); 
    } 
    else if (s2 == 0 || s1 == 0) {   // Linea leggermente a sinistra
      muovi('s'); 
    }  
    else if (s4 == 0 || s5 == 0) {   // Linea leggermente a destra
      muovi('d'); 
    }
    delay(10);
  } 
  else {
    muovi('x');
  }
} 

 

void setup() {
  servoRight.attach(11); 
  servoLeft.attach(10); 

  pinMode(SENS_SXSX, INPUT); 
  pinMode(SENS_SX, INPUT); 
  pinMode(SENS_CX, INPUT); 
  pinMode(SENS_DX, INPUT); 
  pinMode(SENS_DXDX, INPUT); 
} 

void loop() { 
  segui_linea();  // il robot segue continuamente la linea 
} 

