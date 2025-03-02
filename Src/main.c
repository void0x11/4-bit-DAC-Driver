#include "stm32f4xx.h"
#include <stdio.h>

// Declare the Functions we will deal with
void GPIO_Config(void);
uint8_t Convert_Step_To_Binary(uint8_t step);
void Set_DAC_Value(uint8_t value);

// Enable GPIO Clocks
#define GPIOBEN    (1U<<1)  // Enable GPIOB Clock

// Define DAC Output Pins (PB12, PB13, PB14, PB15)
#define PB12      (1U<<12)  // PB12 (LSB X0)
#define PB13      (1U<<13)  // PB13 (X1)
#define PB14      (1U<<14)  // PB14 (X2)
#define PB15      (1U<<15)  // PB15 (MSB X3)

// Define DAC Pins for Readability
#define DAC_LSB    PB12
#define DAC_X1     PB13
#define DAC_X2     PB14
#define DAC_MSB    PB15

int main(void)
{
    GPIO_Config();

	// We are interested in Step 3, 7, 10, 13
	// This should output 0.936 V, 2.187 V, 3.119 V, 4.05 V

    uint8_t step = 15;
    uint8_t binaryValue = Convert_Step_To_Binary(step);

    // Send the step value to the DAC
    Set_DAC_Value(binaryValue);

    while (1)
    {
        // Infinite loop
    }
}

void GPIO_Config(void)
{
	// Enable GPIOB Clock
	RCC->AHB1ENR |= GPIOBEN;

	// MODERy = 2 * y , (2 * y) + 1
	// Set them to 01 (Output Mode)

	// PB12 (Output Mode: Bits 25,24)
	GPIOB->MODER &= ~(3U << 24); // Clear both bits
	GPIOB->MODER |=  (1U << 24); // Set PB12 as Output (01)

	// PB13 (Output Mode: Bits 27,26)
	GPIOB->MODER &= ~(3U << 26);
	GPIOB->MODER |=  (1U << 26);

	// PB14 (Output Mode: Bits 29,28)
	GPIOB->MODER &= ~(3U << 28);
	GPIOB->MODER |=  (1U << 28);

	// PB15 (Output Mode: Bits 31,30)
	GPIOB->MODER &= ~(3U << 30);
	GPIOB->MODER |=  (1U << 30);
}

void Set_DAC_Value(uint8_t value)
{
    // Clear all 4 DAC pins
	GPIOB->ODR &= ~DAC_LSB;		// Clear PB12
	GPIOB->ODR &= ~DAC_X1;		// Clear PB13
	GPIOB->ODR &= ~DAC_X2;		// Clear PB14
	GPIOB->ODR &= ~DAC_MSB;		// Clear PB15

    if (value & (1U << 0))
    {
        GPIOB->ODR |= DAC_LSB;  // If bit 0 is 1, set PB12 HIGH (X0)
    }

    // 1U << 1 creates a bitmask '0010' -> checks bit 1
    if (value & (1U << 1))
    {
        GPIOB->ODR |= DAC_X1;   // If bit 1 is 1, set PB13 HIGH (X1)
    }

    // 1U << 2 creates a bitmask '0100' -> checks bit 2
    if (value & (1U << 2))
    {
        GPIOB->ODR |= DAC_X2;   // If bit 2 is 1, set PB14 HIGH (X2)
    }

    // 1U << 3 creates a bitmask '1000' -> checks bit 3 (Most Significant Bit)
    if (value & (1U << 3))
    {
        GPIOB->ODR |= DAC_MSB;  // If bit 3 is 1, set PB15 HIGH (X3)
    }
}

uint8_t Convert_Step_To_Binary(uint8_t step)
{
    step &= 0x0F;  // Ensure step is within 4-bit range (0-15)
    return step;   // Return the binary value
}
