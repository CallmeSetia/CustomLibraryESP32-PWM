/* ===== {ORIGINAL AUTHOR} ==== */
// Name : Dwi Setia Fardhana
// Email: dwi.setia.fardhana@gmail.com
// LinkedIn : Dwi Setia Fardhana
// Program Desc : Basic PWM ESP32 Custom Library v.1.0
/* ============================ */



#ifndef ESP32
#error "pwm.h library untuk ESP32"
#endif // !ESP32
#include <Arduino.h>

#pragma once
#define FADE_UP 1
#define FADE_DOWN 0

class PWM {
    private:
        unsigned int _freq;
        unsigned int _pin;
        unsigned int _ch;
        unsigned int _res;
        unsigned int _max_dutycycle;
    
    public:
        // Setup
        PWM(unsigned int pin, unsigned int frekuensi, unsigned int channel, unsigned int resolusi);
        void PWM_INIT();
        // Setting PWM
        void setPWM(unsigned int dutyCycle);
        void setFadePWM(int fadeMode, int start, int end, int delay);

        // INFO
        int infoFrekuensiPWM();
        int infoChannelPWM();
        int infoResolusiPWM();
        int infoMaksimumDutyCycle();

};

// #endif