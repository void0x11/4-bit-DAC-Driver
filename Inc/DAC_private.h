#include "STD_TYPES.h"

#ifndef MCAL_DAC_PRIVATE_H_
#define MCAL_DAC_PRIVATE_H_

#define GPIOB_BASE_ADDRESS  0x40020400

typedef struct {
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
} GPIO_T;

#define GPIOB  ((GPIO_T *) GPIOB_BASE_ADDRESS)
#define RCC_BASE_ADDRESS  0x40023800

typedef struct {
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 AHB3RSTR;
    volatile u32 RESERVED0;
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 RESERVED1[2];
    volatile u32 AHB1ENR;
} RCC_T;

#define RCC  ((RCC_T *) RCC_BASE_ADDRESS)

#endif /* MCAL_DAC_PRIVATE_H_ */