/** DAC_interface.h **/
#ifndef MCAL_DAC_INTERFACE_H_
#define MCAL_DAC_INTERFACE_H_

#include "STD_TYPES.h"

// Function Prototypes
void DAC_voidInit(void);
void DAC_voidSetValue(u8 Copy_u8StepValue);
uint8_t DAC_u8ConvertStepToBinary(uint8_t step);

#endif /* MCAL_DAC_INTERFACE_H_ */