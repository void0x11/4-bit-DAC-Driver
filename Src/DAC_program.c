/** DAC_program.c **/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

void DAC_voidInit(void)
{
    SET_BIT(RCC->AHB1ENR, 1); // Enable GPIOB Clock

    // Configure PB12, PB13, PB14, PB15 as Output
    GPIOB->MODER &= ~(3U << 24);
    GPIOB->MODER |=  (1U << 24);
    GPIOB->MODER &= ~(3U << 26);
    GPIOB->MODER |=  (1U << 26);
    GPIOB->MODER &= ~(3U << 28);
    GPIOB->MODER |=  (1U << 28);
    GPIOB->MODER &= ~(3U << 30);
    GPIOB->MODER |=  (1U << 30);

    // Set default DAC output
    DAC_voidSetValue(DAC_DEFAULT_STEP);
}

void DAC_voidSetValue(uint8_t value)
{
    GPIOB->ODR &= ~(DAC_LSB | DAC_X1 | DAC_X2 | DAC_MSB);

    if (value & (1U << 0)) GPIOB->ODR |= DAC_LSB;
    if (value & (1U << 1)) GPIOB->ODR |= DAC_X1;
    if (value & (1U << 2)) GPIOB->ODR |= DAC_X2;
    if (value & (1U << 3)) GPIOB->ODR |= DAC_MSB;
}

uint8_t DAC_u8ConvertStepToBinary(uint8_t step)
{
    return step & DAC_MAX_STEPS;  // Mask to keep only lower 4 bits
}