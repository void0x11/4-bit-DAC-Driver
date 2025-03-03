# 4-bit DAC Driver for STM32F411RE

## 📌 Overview
This project implements a **4-bit DAC (Digital-to-Analog Converter) driver** for the **STM32F411RE** using GPIO-based digital outputs. The driver follows an **MCAL (Microcontroller Abstraction Layer)** architecture, ensuring modularity and scalability.

## 📁 Project Structure
```
/Project_Root
│── Src/
│   ├── DAC_program.c    # DAC driver implementation
│── Inc/
│   ├── DAC_interface.h  # Public function prototypes
│   ├── DAC_private.h    # Internal registers and macros
│   ├── DAC_config.h     # Configurable settings
│── main.c               # Application entry point
│── Makefile (if needed)
```

## ⚙️ Features
- **4-bit DAC implementation using GPIO pins**
- **Configurable voltage reference (VREF)**
- **Uses `PB12 - PB15` for output data**
- **Follows industry-standard MCAL architecture**
- **Modular design with `interface.h`, `config.h`, `private.h`, and `program.c`**

## 🚀 Getting Started
### 1️⃣ Hardware Setup
- Connect the **DAC output (PB12 - PB15)** to an external DAC circuit or logic analyzer.
- Ensure **VREF is set to 5V** (configurable in `DAC_config.h`).

### 2️⃣ Software Requirements
- **STM32CubeIDE** or **Keil uVision**
- **ARM GCC Toolchain** (if using Makefile)
- **ST-Link Debugger** for programming

### 3️⃣ Build & Flash
#### **Using Makefile (Optional)**
```sh
make clean
make all
make flash
```

#### **Using STM32CubeIDE**
1. Import the project
2. Build the project (`Ctrl + B`)
3. Flash to the board (`Run > Debug`)

## 🔧 Configuration
The driver includes `DAC_config.h` for user settings:
```c
#define DAC_VREF       5.0   // Reference Voltage (V)
#define DAC_MAX_STEPS  15    // Max 4-bit steps (0-15)
#define DAC_DEFAULT_STEP 0   // Default startup step value
```
Modify these values as needed.

## 📝 API Reference
### **`void DAC_voidInit(void)`**
Initializes the DAC by configuring GPIOB and enabling the clock.

### **`void DAC_voidSetValue(uint8_t stepValue)`**
Sets the DAC output based on the provided 4-bit step value.

### **`uint8_t DAC_u8ConvertStepToBinary(uint8_t step)`**
Ensures the step value is within the valid 4-bit range (0-15).

## 🛠️ Debugging & Testing
- Use an **oscilloscope** to measure DAC output voltages.
- Use `GPIOB->ODR` register to verify output states.
- Debug using **ST-Link Utility** or **OpenOCD**.

## 📌 Future Enhancements
- Add **PWM-based DAC smoothing** for better resolution.
- Implement **DMA-based DAC updates**.
- Add support for **higher resolution DACs (8-bit, 12-bit, etc.)**.

## 📜 License
This project is open-source under the **MIT License**.
---