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
│── Startup/        # Startup files for STM32
│── README.md       # Documentation
│── Makefile        # Build instructions (if applicable)
│── main.c          # Main firmware source file
```

## Hardware Setup
### Required Components
- **STM32 Nucleo-F411RE**
- **External DAC**
- **Jumper Wires**
- **Multimeter (for voltage measurements)**

### Pin Configuration
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
Use **STM32CubeIDE** or compile using `Makefile`:
```sh
make
```

### Step 3: Flash the Code to the Board
Use **OpenOCD** or STM32CubeProgrammer:
```sh
make flash
```

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

### Step 2: Observe DAC Output
- Connect **PB12-PB15** to an **external DAC**.
- Measure the output **analog voltage** using a multimeter.

## Code Breakdown
### GPIO Configuration
```c
void GPIO_Config(void)
{
    RCC->AHB1ENR |= GPIOBEN; // Enable GPIOB Clock

    // Set PB12, PB13, PB14, PB15 as Output
    GPIOB->MODER &= ~(3U << 24);
    GPIOB->MODER |=  (1U << 24);
    GPIOB->MODER &= ~(3U << 26);
    GPIOB->MODER |=  (1U << 26);
    GPIOB->MODER &= ~(3U << 28);
    GPIOB->MODER |=  (1U << 28);
    GPIOB->MODER &= ~(3U << 30);
    GPIOB->MODER |=  (1U << 30);
}
```

### Setting DAC Output
```c
void Set_DAC_Value(uint8_t value)
{
    GPIOB->ODR &= ~(PB12 | PB13 | PB14 | PB15); // Clear all bits

    if (value & (1U << 0)) GPIOB->ODR |= PB12;  
    if (value & (1U << 1)) GPIOB->ODR |= PB13;  
    if (value & (1U << 2)) GPIOB->ODR |= PB14;  
    if (value & (1U << 3)) GPIOB->ODR |= PB15;  
}
```

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
- **[Your Name]** (Developer)
- **[Contributor Name]** (Hardware Testing)
- **[Your Organization]** (Sponsor)

## Final Notes
✔️ Works on **STM32F411RE**  
✔️ Uses **PB12-PB15 for 4-bit DAC output**  
✔️ Fully tested with an external DAC  

---

Let me know if you need **any modifications**! 🚀