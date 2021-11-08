/* ===== {ORIGINAL AUTHOR} ==== */
// Name : Dwi Setia Fardhana
// Email: dwi.setia.fardhana@gmail.com
// LinkedIn : Dwi Setia Fardhana
// Program Desc : Basic PWM ESP32 Custom Library v.1.0
/* ============================ */

#include <Arduino.h>
#include "pwm.h"

PWM LED1(16, 5000, 0, 8); // ARGUMENT : PIN GPIO, Frekuensi, PWM Channel, Resolusi ADC => LED1
PWM LED2(18, 5000, 1, 8); // ARGUMENT : PIN GPIO, Frekuensi, PWM Channel, Resolusi ADC => LED2

void setup() {
  Serial.begin(9600);

  LED1.PWM_INIT();
  LED2.PWM_INIT();
}

void loop() {
  LED1.setFadePWM(FADE_UP, 0, 255, 4); //PWM TRANSISI NAIK pd LED1
  delay(1000);
  LED1.setFadePWM(FADE_DOWN, 0, 255, 4); //PWM TRANSISI TURUN LED1
  
  LED2.setPWM(200); // Set PWM STATIS Nilai 200 pada LED2

  // == Print Info == //
  Serial.println("Frequensi PWM pada LED1 : " + String(LED1.infoFrekuensiPWM()));
  Serial.println("Frequensi PWM pada LED2 : " + String(LED2.infoFrekuensiPWM()));
  

  delay(10); // Untuk menghilangkan BUG
}