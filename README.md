# STM32 DAC Driver (4-Bit Parallel)

## Overview
This project implements a **4-bit DAC (Digital-to-Analog Converter) driver** on an **STM32 Nucleo-F411RE** development board. The driver configures **PB12, PB13, PB14, and PB15** as **digital outputs** to interface with an external DAC circuit.

## Features
- **4-bit Digital Output** via GPIOB
- **Precise Voltage Steps** based on 4-bit binary representation
- **Uses Low-Level Register Access (No HAL)**
- **Efficient Bitwise Operations for Performance**

## Directory Structure
```
/Project_Root
│── Debug/          # Compiled binaries and debug files
│── Src/            # Source code (.c files)
|────main.c         # Main firmware source file
│── Startup/        # Startup files for STM32
│── README.md       # Documentation
```

## Hardware Setup
### Required Components
- **STM32 Nucleo-F411RE**
- **External DAC**
- **Jumper Wires**
- **Multimeter (for voltage measurements)**

### Nucleo-F411RE Schematic

![alt text](<Pasted image 20250216185434.png>)

### External DAC Schematic Design

![alt text](<R to R DAC (Final).png>)

### Pin Configuration from the Nucleo board to the DAC inputs
| **Pin**  | **GPIO** | **Function (DAC Bit)** |
|---------|---------|---------------------|
| PB12    | X0 (LSB)  | Least Significant Bit |
| PB13    | X1        | Second Bit |
| PB14    | X2        | Third Bit |
| PB15    | X3 (MSB)  | Most Significant Bit |

## Installation & Compilation
### Step 1: Clone the Repository
```sh
git clone https://github.com/your-repo/STM32-DAC-Driver.git
cd STM32-DAC-Driver
```

### Step 2: Compile the Code
Use **STM32CubeIDE** to import as a c project

### Step 3: Flash the Code to the Board
Use **STM32CubeProgrammer** to build the project


## Usage
### Step 1: Modify the DAC Step Value
In `main.c`, set the `step` value:
```c
uint8_t step = 15;  // Set a value between 0-15
```
Expected **binary output (PB12-PB15)**:
| **Decimal** | **Binary Output (PB15 PB14 PB13 PB12)** |
|------------|----------------------------------|
| 3         | `0011` (LOW LOW HIGH HIGH) |
| 7         | `0111` (LOW HIGH HIGH HIGH) |
| 10        | `1010` (HIGH LOW HIGH LOW) |
| 13        | `1101` (HIGH HIGH LOW HIGH) |

## Debugging
### Verify GPIO Output
Check if the pins are toggling correctly:
```c
printf("GPIOB->ODR: 0x%X\n", GPIOB->ODR);
```
Expected output (for step `9` → `1001`):
```
GPIOB->ODR: 0x9000
```

This confirms **PB15 (1) PB14 (0) PB13 (0) PB12 (1)**.

## License
MIT License.  
Feel free to use and modify!

## Contributors
- **[Ahmed Amin]** (Developer)