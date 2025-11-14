# 🦖 Rexduino – The Arduino-Powered Dinosaur UosM YEAR2 SEM 1   

**Rexduino** is a dynamic, interactive robotic dinosaur powered by Arduino. Inspired by the legendary T-Rex and driven by our passion for robotics and childhood imagination, Rexduino brings prehistoric life into the modern world through motion, sensors, sound, and light.

> Built as part of the [FEEG2001 Systems Design and Computing] project at University of Southampton Malaysia.

---

## 📜 Table of Contents

- [📌 Project Inspiration](#-project-inspiration)
- [🔧 Design Overview](#-design-overview)
- [🧠 Arduino Integration](#-arduino-integration)
- [🎮 Features & Interactions](#-features--interactions)
- [🧪 Testing & Showcase](#-testing--showcase)
- [🚀 Future Applications](#-future-applications)
- [👥 Team Members](#-team-members)
- [📁 Repository Structure](#-repository-structure)
- [🔌 Getting Started](#-getting-started)

---

## 📌 Project Inspiration

### A Childhood Dream  
Rexduino was inspired by the awe of dinosaurs and the dream to bring them to life through robotics.

### Bridging Generations  
It connects childhood fascination with modern technology—showing that even complex ideas like personality-driven robotics can be built with creativity and accessible tools.

---

## 🔧 Design Overview

### 🛠 Phases of Development:
1. Initial concept sketches (Triduinodroid, Pterodruinosaur, Rexduino)
2. Dirty modelling (prototyping with basic materials)
3. Movement design with servos and stepper motors
4. Sound and light integration for immersive interaction

---

## 🧠 Arduino Integration

**Central Brain:** Arduino Uno

### 🔍 Inputs:
- **HC-SR04 Ultrasonic Sensor:** Detects nearby objects to trigger fear/curiosity reactions.
- **LDR (Light Dependent Resistor):** Detects light to direct head movement.

### ⚙ Outputs:
- **Stepper Motor (Body):** Moves Rexduino forward or backward based on distance sensing.
- **Servo Motors:**
  - **Neck Servo:** Rotates the head toward light.
  - **Mouth Servo:** Bites when LDR is blocked.
- **LED Backbone:** Lights up during biting motion.
- **Buzzer:** Plays sound to accompany biting.

> The components are fully wired and integrated on an Arduino-controlled breadboard system.

---

## 🎮 Features & Interactions

| Feature                        | Trigger                       | Behavior                           |
|-------------------------------|-------------------------------|------------------------------------|
| Head Turning                  | Light detected by LDR         | Servo rotates neck to light source |
| Biting Motion + Sound         | LDR covered                   | Mouth closes, buzzer plays sound   |
| Body Movement (Forward)       | Object detected (close)       | Dinosaur charges forward           |
| Body Movement (Backward)      | Object detected (far)         | Dinosaur retreats in fear          |
| LED Activation                | During bite                   | LED backbone lights up             |

---

## 🧪 Testing & Showcase

### Final Performance Outcomes:
- 🦖 Simulated personality (curious vs. fearful movement)
- 🔊 Real-time sound feedback during biting
- 💡 Reactive head turning makes interaction lifelike

> Final presentation included full demo of motion, sound, and sensory interactivity.

---

## 🚀 Future Applications

Rexduino isn't just a fun dinosaur — it represents what’s possible with **accessible robotics**:

- **📚 Education:** Inspiring young learners through hands-on robotics
- **🎮 Entertainment:** Interactive toys and learning companions
- **🛠 Expansion:** Add more sensors (IR, sound, or pressure), AI processing, or wireless control

---

## 👥 Team Members

- **Yee Kai Xiong**  
- **Teh Journ Xi**  
- **Liang Zhen Yu**  
- **Ryan Lo Tzu Sheng**  
- **Zhang Zhi Ming**

---

## 📁 Repository Structure

