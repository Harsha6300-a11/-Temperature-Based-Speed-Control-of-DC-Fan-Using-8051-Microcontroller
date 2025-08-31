# -Temperature-Based-Speed-Control-of-DC-Fan-Using-8051-Microcontroller
Temperature-Based Speed Control of DC Fan using 8051 Microcontroller, LM35 sensor, ADC0804, and L293D motor driver. The project implements real-time ambient temperature monitoring and automatic DC fan speed control using software PWM logic, with temperature readings and fan status displayed on a 16x2 LCD. Written in Embedded C (Keil µVision).


This project demonstrates **automatic fan speed control** using the **8051 microcontroller** and an **LM35 temperature sensor**.  
The system monitors real-time temperature, converts analog data via **ADC0804**, and adjusts the **fan speed** using a software-generated PWM signal through **L293D motor driver**.  

A **16x2 LCD** is used to display current temperature and fan status (`OFF`, `LOW`, `MEDIUM`, `HIGH`).  

---

## Features
- Reads ambient temperature via **LM35 sensor**  
- Converts analog signal using **ADC0804**  
- Processes data with **8051 Microcontroller** (AT89C51/AT89S52)  
- Generates **PWM signal** in software for motor speed control  
- Drives DC fan with **L293D Motor Driver**  
- Real-time display on **16x2 LCD**  

---

##  Hardware Components
- 8051 Microcontroller (AT89C51/AT89S52)  
- LM35 Temperature Sensor  
- ADC0804 (8-bit ADC)  
- L293D Motor Driver  
- DC Fan (5V/12V)  
- 16x2 LCD Module  
- Power Supply (5V regulated)  
- Supporting passive components (resistors, capacitors, crystal, etc.)  

---

## Software Tools
- **Keil µVision IDE** (Embedded C programming)  
- **Proteus (Optional)** for simulation  
- **Flash Magic / Programmer** for burning hex file  

---

## Working Principle
1. **LM35 Sensor** measures ambient temperature and outputs analog voltage.  
2. **ADC0804** converts analog signal to digital value (8-bit).  
3. **8051** reads digital data, calculates temperature in °C.  
4. Based on predefined thresholds, **PWM duty cycle** is adjusted:  
   - `< 25°C` → Fan OFF  
   - `25–29°C` → LOW speed  
   - `30–34°C` → MEDIUM speed  
   - `≥ 35°C` → HIGH speed  
5. **L293D** drives the fan motor using the PWM signal.  
6. **LCD** displays real-time **temperature** and **fan status**.  

---


---

##  Output Example
- LCD Display:
```

Temp: 28C  LOW

```
```

Temp: 36C  HIGH

```

---

## Skills Demonstrated
- 8051 Microcontroller programming in **Embedded C**  
- **Analog-to-Digital Interfacing** (LM35 + ADC0804)  
- **PWM Logic Generation in Software**  
- **LCD Interfacing** with 8051  
- **Motor Control using L293D**  
- Basics of **embedded automation & control systems**  

---


