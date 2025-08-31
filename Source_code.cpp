#include <reg51.h>          // 8051 register definitions
#include "lcd.h"            // Assume lcd.h has standard 16x2 LCD routines

// Pin connections (adjust as per your circuit)
sbit CS  = P2^0;    // ADC0804 Chip Select
sbit RD  = P2^1;    // ADC0804 Read
sbit WR  = P2^2;    // ADC0804 Write
sbit INTR= P2^3;    // ADC0804 Interrupt

sbit FAN = P1^0;    // Fan PWM output to L293D EN pin

// Function prototypes
unsigned char ADC_Read();
void PWM_Generate(unsigned char duty);

// Global variables
unsigned char tempC = 0;
unsigned char dutyCycle = 0;

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i=0;i<ms;i++)
        for(j=0;j<1275;j++);
}

// Read temperature from ADC0804
unsigned char ADC_Read() {
    unsigned char adc_value;
    
    WR = 0;           // Start conversion
    delay_ms(1);
    WR = 1;
    
    while(INTR==1);   // Wait for conversion complete
    
    RD = 0;           // Read data
    adc_value = P0;   // ADC data on Port0
    RD = 1;
    
    return adc_value;
}

// Simple software PWM on FAN pin
void PWM_Generate(unsigned char duty) {
    FAN = 1;
    delay_ms(duty);         // ON time
    FAN = 0;
    delay_ms(100-duty);     // OFF time (total 100ms period)
}

void main() {
    unsigned char adc_value;
    lcd_init();
    lcd_cmd(0x80);
    lcd_string("Temp Ctrl Fan");
    
    while(1) {
        adc_value = ADC_Read();  
        tempC = (adc_value * 5 * 100) / 256;  // LM35: 10mV/°C, ADC=8bit (5V)
        
        // Decide duty cycle based on thresholds
        if(tempC < 25) {
            dutyCycle = 0;   // Fan OFF
        }
        else if(tempC >= 25 && tempC < 30) {
            dutyCycle = 30;  // LOW
        }
        else if(tempC >= 30 && tempC < 35) {
            dutyCycle = 60;  // MEDIUM
        }
        else {
            dutyCycle = 90;  // HIGH
        }
        
        // Display temperature
        lcd_cmd(0xC0);
        lcd_string("Temp:");
        lcd_num(tempC);
        lcd_string("C ");
        
        // Display Fan Status
        if(dutyCycle==0) lcd_string("OFF  ");
        else if(dutyCycle==30) lcd_string("LOW  ");
        else if(dutyCycle==60) lcd_string("MED  ");
        else lcd_string("HIGH ");
        
        // Generate PWM continuously
        PWM_Generate(dutyCycle);
    }
}

