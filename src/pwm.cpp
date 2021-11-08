/* ===== {ORIGINAL AUTHOR} ==== */
// Name : Dwi Setia Fardhana
// Email: dwi.setia.fardhana@gmail.com
// LinkedIn : Dwi Setia Fardhana
// Program Desc : Basic PWM ESP32 Custom Library v.1.0
/* ============================ */


#include "pwm.h"

PWM::PWM(unsigned int pin, unsigned int frekuensi = 5000, unsigned int channel = 0, unsigned int resolusi = 8) {
    // Ke Variabel PWM 
    this->_pin = pin;
    this->_freq = frekuensi;
    this->_ch = channel;
    this->_res = resolusi;
    this->_max_dutycycle = (int)(pow(2, this->_res) - 1); 


    // Setup 
    // Channel PWM yang bisa digunakan (0-15), set PWM duty cycle frequency, dan PWM resolution (1 - 16 bits) 
};

void PWM::PWM_INIT() {
    ledcSetup(this->_ch, this->_freq, this->_res);
    ledcAttachPin(this->_pin, this->_ch);
}


// SETTING PWM
void PWM::setPWM(unsigned int dutyCycle) {
    ledcWrite(this->_ch, dutyCycle);
}

void PWM::setFadePWM(int fadeMode, int start, int end, int Delay = 4) {
    
    // Fix Error untuk Limit Delay, Start dan End
    if (Delay < 0) {
        Delay = 1;
    } 

    if (start < 0) {
        start = 0;
    }
    
    if (end > this->_max_dutycycle) {
        end = this->_max_dutycycle;
    }
    else if (end < 0) {
        end = 0;
    }
 
    // Mode Transisi naik
    if (fadeMode == FADE_UP) {
        for(int dutyCycle = start; dutyCycle <= end; dutyCycle++){   
            ledcWrite(this->_ch, dutyCycle);
            delay(Delay);
        }
    }
    // Mode Transisi down
    else if (fadeMode == FADE_DOWN) {
        for(int dutyCycle = end; dutyCycle >= start; dutyCycle--){
             ledcWrite(this->_ch, dutyCycle);
            delay(Delay);
        }
    }
    
}


// GET INFO DARI PWM PARAMETER
int PWM::infoResolusiPWM(){
    return this->_res;
}

int PWM::infoChannelPWM() {
    return this->_ch;
}

int PWM::infoFrekuensiPWM() {
    return this->_freq;
}

int PWM::infoMaksimumDutyCycle() {
    return this->_max_dutycycle;
}