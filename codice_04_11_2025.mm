#include <Servo.h> // Include servo library  

 

Servo servoRight; // Declare right servo  

Servo servoLeft; // Declare right servo  

 

const int SENS_DXDX=A4; 

const int SENS_DX=A3; 

const int SENS_CX=A2; 

const int SENS_SX=A1;  

const int SENS_SXSX=A0; 

 

void muovi(char direzione) {  

  if (direzione == 'a') {  

    servoRight.writeMicroseconds(1400);  

    servoLeft.writeMicroseconds(1600);  

  } else if (direzione == 'i') {  

    servoRight.writeMicroseconds(1600);  

    servoLeft.writeMicroseconds(1400);  

  } else if (direzione == 's') {  

    servoRight.writeMicroseconds(1400);  

    servoLeft.writeMicroseconds(1400);  

  } else if (direzione == 'd') {  

    servoRight.writeMicroseconds(1600);  

    servoLeft.writeMicroseconds(1600);  

  }   

}  

 

void verifica_motori (){  

    servoRight.writeMicroseconds(1500);  

    servoLeft.writeMicroseconds(1500);     

    delay(900000000);  

}  

 

void quadrato_destra(){  

  for(int i = 0; i<4;i++){  

  muovi('a'); 

  muovi('d');  

  }   // fa andare avanti e girare perfettamente di 90 gradi robottino per farli fare un qudrato  

}  

bool fermo_stop(){ 

  if((SENS_SXSX || SENS_SX || SENS_CX || SENS_DX || SENS_DXDX) == 0){ 

    servoRight.detach();  

    servoLeft.detach();  

    return false; 

  } else { 

  return true; 

  } 

} 

void segui_linea(){ 

  while (SENS_CX == 0 ){ 

    if ((SENS_SX == 0) || (SENS_SXSX == 1)){   // curva larga a sinistra, led 0 on led 1 off led 2 off led 3 on led 4 on  

      muovi('s');     // sposta leggeremente a sinistra per riaddrizzarsi  

    } else if ((SENS_SX == 0) || (SENS_SXSX == 0)){   // curva stretta a sinistra, led 0 off led 1 off led 2 off led 3 on led 4 on 

      muovi('s');    // sposta bruscamente a sinistra per riaddrizzarsi  

    } else if ((SENS_DX == 0) || (SENS_DXDX == 1)){   // curva larga a destra, led 0 on led 1 on led 2 off led 3 off led 4 on  

      muovi('d');     // sposta leggeremente a destra per riaddrizzarsi  

    } else if ((SENS_DX == 0) || (SENS_DXDX == 0)){   // curva stretta a destra, led 0 on led 1 on led 2 off led 3 off led 4 off 

      muovi('d'); // sposta bruscamente a destra per riaddrizzarsi  

    } else { 

      muovi ('a'); 

    } 

  } 

} 

 

 

void setup() {  

  servoRight.attach(11); // Attach right signal to pin 11  

  servoLeft.attach(10);  

 

  while(fermo_stop() == true ){  // se è vero ( almeno 1 led è acceso) può eseguire il codice invece se tutti si spengono si spegne definitivamente 

    segui_linea(); 

  } 

 

  servoRight.detach(); // Attach right signal to pin 11 

  servoLeft.detach();  

}  

 

void loop()  

{  

} 