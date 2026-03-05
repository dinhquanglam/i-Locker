# i-Locker — Intelligent Parcel Locker for Students

i-Locker is an intelligent parcel locker prototype designed for student campuses. Couriers can drop parcels into lockers, and students retrieve them securely using a unique passcode. The goal is to reduce parcel mix-ups, improve privacy, and save time for both students and couriers.

> Built for **IEEE SEACAS 2022 Hackathon** — **2nd Prize** 🏆

---

## Table of Contents
- [Project Overview](#project-overview)
- [Problem](#problem)
- [Solution](#solution)
- [How It Works](#how-it-works)
- [Prototype Demo Flow](#prototype-demo-flow)
- [System Architecture](#system-architecture)
- [Hardware](#hardware)
- [Firmware](#firmware)
- [Repository Structure](#repository-structure)
- [Getting Started](#getting-started)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

---

## Project Overview
**i-Locker** is an automatic parcel locker system concept and prototype:
- Couriers place parcels into lockers.
- A passcode is generated per parcel/receiver.
- Students enter the passcode on-site to unlock the correct locker.
- Passcodes expire after use (and can also expire after a time limit, e.g., 24h).

This repo includes a working **hardware prototype firmware** (keypad + LCD + locker outputs).

---

## Problem
Campus parcel delivery often causes:
- Parcels being swapped or taken by mistake
- Crowded pickup points and manual handling
- Privacy and security concerns
- Wasted time for students, couriers, and staff

---

## Solution
i-Locker addresses this with:
- **Automatic lock/unlock**
- **Passcode-based access**
- **Organized locker sections** (prototype + scalable concept)

---

## How It Works
A clear end-to-end flow:

1. **Courier delivers parcel** and places it into an available locker slot.
2. **System generates a passcode** associated with the parcel (e.g., by tracking number in an application).
3. **Student receives the passcode** (e.g., via email/notification).
4. **Student enters passcode at the locker** → the correct locker unlocks.
5. **Passcode expires** after successful retrieval.
6. *(Optional policy)* If not collected after **24 hours**, the code expires and the courier can retrieve the parcel.

> Note: The current firmware prototype demonstrates the on-device unlocking logic. A full deployment would connect passcode generation/notification to a backend/app.

---

## Prototype Demo Flow
What the prototype shows today:
- LCD prompts the user to enter a password
- User types a 4-digit code on the keypad
- If code matches a locker passcode, the corresponding locker output is activated (LED/actuator signal)
- If incorrect, the LCD shows an error

---

## System Architecture
**High-level components**
- **User Interface (On-site):** Keypad + LCD
- **Controller:** Microcontroller (prototype firmware)
- **Locker Actuation:** Output pins (LED demo / can be replaced by relay/solenoid control)
- **(Future) Backend/App:** Code generation, tracking number mapping, notifications (email/SMS), expiration rules

---

## Hardware
Prototype hardware (as used in the firmware):
- 3×4 **Keypad** (for passcode entry)
- 16×2 **I2C LCD** (for instructions and feedback)
- **Locker outputs** (LEDs in the prototype; can be replaced with relays/solenoids)
- Microcontroller board (ESP32-family boards are listed in the project materials; Arduino-compatible setup works)

---

## Firmware
The firmware implements:
- Keypad input collection (4 digits)
- Passcode comparison
- Triggering the correct locker output
- LCD feedback (“Enter Password”, “Correct”, “Incorrect”)

> In the demo firmware, locker passcodes are hardcoded (e.g., `1111`, `2222`, `3333`, `4444`) for 4 lockers.
> In a production version, passcodes should be generated dynamically and stored securely.

---

## Repository Structure
Typical layout (may vary slightly depending on updates):
- `i-LockerCode/`
  - `i-LockerCode.ino` — Arduino/ESP-style firmware source

---

## Getting Started

### 1) Requirements
- Arduino IDE (or PlatformIO)
- Keypad + I2C LCD libraries (install via Library Manager as needed)
- Supported microcontroller board configured in your IDE

### 2) Wiring (Guidance)
Wiring depends on your board and pin mapping.
- Connect keypad rows/cols to digital pins
- Connect LCD via I2C (SDA/SCL + power)
- Connect locker outputs (LEDs or relay inputs) to digital pins

> Tip: Check the pin definitions in the firmware file and wire accordingly.

### 3) Upload
1. Open `i-LockerCode/i-LockerCode.ino` in Arduino IDE
2. Select the correct board + COM port
3. Upload
4. Use Serial Monitor (optional) for debugging logs

---

## Roadmap
Ideas to evolve i-Locker beyond the prototype:
- Real **passcode generation** linked to tracking numbers
- **Notification system** (email/SMS/app)
- **One-time codes** + secure storage (hashing)
- **Time-based expiration** (24h policy) and admin override
- Logging & audit trail (who opened which locker and when)
- Scale to many locker slots (e.g., “100 sections” concept)

---

## Contributing
Contributions are welcome:
- Bug fixes
- Hardware improvements (relay/solenoid driver design)
- Backend/app integration proposals
- Documentation and diagrams

Open an issue or submit a pull request.

---

## License
Add a license file if you want others to reuse the project easily.
- If you haven’t decided: MIT is a common choice for hackathon prototypes.

---

## Acknowledgements
- IEEE SEACAS 2022 Hackathon organizers and mentors
- Team members and contributors
