# Emo Light: Intelligent Lighting System for Emotional Well-being

## Project Overview
Emo Light is an intelligent lighting system designed to optimize indoor environments by leveraging color theory and advanced sensors. The system enhances emotional stability, physical health, and energy efficiency by dynamically adjusting lighting based on ambient conditions and user activity. The core functionality includes real-time color detection, complementary color adjustments, brightness regulation, and motion-responsive lighting.

---

## Features
### **1. Real-Time Color Adjustment**
- Detects ambient RGB values using a **TCS3200 color sensor**.
- Applies **complementary color theory** to balance and enhance mood.
- Dynamically adjusts lighting to improve visual comfort and emotional stability.

### **2. Motion-Responsive Lighting**
- Infrared sensor detects user presence to automatically turn lights on/off.
- Saves energy by deactivating lights during inactivity.

### **3. Brightness Regulation**
- Adapts light intensity based on surrounding brightness using a light sensor.
- Reduces glare and ensures optimal illumination for productivity and relaxation.

### **4. Energy Efficiency**
- Features energy-saving modes, including:
  - Lowering brightness during inactivity.
  - Sleep mode for sensors and microcontroller.

---

## Technologies Used
### **Hardware**
- **TCS3200 Color Sensor**: Detects ambient RGB values.
- **Infrared Sensor**: Tracks user movement for motion detection.
- **Light Sensors**: Measures ambient brightness.
- **WS2812 Light Rings**: Provides visual feedback and complementary lighting.
- **Arduino Uno**: Central control unit for data processing and device control.
- **5V DC Power Supply**: Powers all components reliably.

### **Software**
- Developed using **Arduino IDE**.
- Key functionalities include:
  - **Data Collection**: RGB and brightness sensing.
  - **Color Calculation**: Determines complementary colors.
  - **Dynamic Control**: Automated brightness adjustments.
  - **Motion Detection**: Real-time user tracking.

---

## Circuit Design
The system is powered by an **Arduino Uno** microcontroller, connecting:
- **TCS3200 color sensor** for RGB detection.
- **Infrared sensor** for motion detection.
- **WS2812 light rings** for real-time visual feedback.
- **5V DC power module** to ensure stable operation.

### **Power Consumption**
| Component           | Current Consumption         |
|---------------------|-----------------------------|
| Color Sensor        | 2mA                         |
| Infrared Sensor     | 50µA (idle), 60mA (active)  |
| WS2812 Light Rings  | 1200mA (total)             |
| Arduino Uno         | 50mA                        |
| **Total**           | **1312mA**                 |

---

## System Demonstration
- **Ambient Light Detection**: Detects ambient light color and adjusts complementary lighting (e.g., red to blue).
- **Brightness Adaptation**: Automatically brightens or dims lights to ensure optimal comfort.
- **Motion Responsiveness**: Turns lights on/off based on user presence.

---

## Results and Reflections
The Emo Light system successfully demonstrates its ability to:
- Enhance indoor environments using intelligent lighting.
- Improve user mood and productivity through complementary color theory.
- Optimize energy consumption via smart motion and brightness detection.

### **Future Improvements**
- **Hardware Optimization**:
  - Miniaturize components with a custom PCB layout.
  - Add additional sensors (e.g., temperature, humidity).
- **Advanced Features**:
  - Develop a mobile app for remote control.
  - Improve calibration for high-sensitivity environments.

---


## References
- Mersch, P.P.A., Middendorp, H.M., Bouhuys, A.L., Beersma, D.G.M., & van den Hoofdakker, R.H. (1999). Seasonal Affective Disorder and Latitude: A Review of the Literature. *Journal of Affective Disorders, 53*(1), 35-48.
- DF ROBOT (2019). TCS3200 Color Sensor. Retrieved from [DFRobot Wiki](https://wiki.dfrobot.com/TCS3200_Color_Sensor__SKU_SEN0101_).
- Kilari, G., Mohammed, R., & Jayaraman, R. (2020). Automatic Light Intensity Control using Arduino UNO and LDR. IEEE Xplore.

---


