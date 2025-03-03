/** main.c **/
#include "stm32f4xx.h"
#include "DAC_interface.h"

int main(void)
{
    DAC_voidInit();

    uint8_t step = 15;
    uint8_t binaryValue = DAC_u8ConvertStepToBinary(step);
    DAC_voidSetValue(binaryValue);

    while (1);
}