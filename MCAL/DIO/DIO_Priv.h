/*
 * DIO_Priv.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ART
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define 	GPIOA_BASE_ADD					(0x48000000)
#define		GPIOB_BASE_ADD					(0x48000400)
#define		GPIOC_BASE_ADD					(0x48000800)
#define		GPIOD_BASE_ADD					(0x48000C00)
#define		GPIOF_BASE_ADD					(0x48001400)


#define GPIOA_MODER						*((volatile u32 *)(GPIOA_BASE_ADD + 0x00))
#define GPIOA_ODR						*((volatile u32 *)(GPIOA_BASE_ADD + 0x14))
#define GPIOA_OTYPER					*((volatile u32 *)(GPIOA_BASE_ADD + 0x04))
#define GPIOA_OSPEEDR					*((volatile u32 *)(GPIOA_BASE_ADD + 0x08))
#define GPIOA_PUPDR						*((volatile u32 *)(GPIOA_BASE_ADD + 0x0C))
#define GPIOA_IDR						*((volatile u32 *)(GPIOA_BASE_ADD + 0x10))


#define		GPIOB_MODER				*((volatile u32 *)(GPIOB_BASE_ADD + 0x00))
#define		GPIOB_OTYPER			*((volatile u32 *)(GPIOB_BASE_ADD + 0x04))
#define		GPIOB_OSPEEDR			*((volatile u32 *)(GPIOB_BASE_ADD + 0x08))
#define		GPIOB_PUPDR		        *((volatile u32 *)(GPIOB_BASE_ADD + 0x0C))
#define		GPIOB_IDR	            *((volatile u32 *)(GPIOB_BASE_ADD + 0x10))
#define		GPIOB_ODR		    	*((volatile u32 *)(GPIOB_BASE_ADD + 0x14))
#define		GPIOB_BSRR		    	*((volatile u32 *)(GPIOB_BASE_ADD + 0x18))
#define		GPIOB_BRR		    	*((volatile u32 *)(GPIOB_BASE_ADD + 0x28))


#define		GPIOC_MODER				*((volatile u32 *)(GPIOC_BASE_ADD + 0x00))
#define		GPIOC_OTYPER			*((volatile u32 *)(GPIOC_BASE_ADD + 0x04))
#define		GPIOC_OSPEEDR			*((volatile u32 *)(GPIOC_BASE_ADD + 0x08))
#define		GPIOC_PUPDR		        *((volatile u32 *)(GPIOC_BASE_ADD + 0x0C))
#define		GPIOC_IDR	            *((volatile u32 *)(GPIOC_BASE_ADD + 0x10))
#define		GPIOC_ODR		    	*((volatile u32 *)(GPIOC_BASE_ADD + 0x14))
#define		GPIOC_BSRR		    	*((volatile u32 *)(GPIOC_BASE_ADD + 0x18))
#define		GPIOC_BRR		    	*((volatile u32 *)(GPIOC_BASE_ADD + 0x28))


#define		GPIOD_MODER				*((volatile u32 *)(GPIOD_BASE_ADD + 0x00))
#define		GPIOD_OTYPER			*((volatile u32 *)(GPIOD_BASE_ADD + 0x04))
#define		GPIOD_OSPEEDR			*((volatile u32 *)(GPIOD_BASE_ADD + 0x08))
#define		GPIOD_PUPDR		        *((volatile u32 *)(GPIOD_BASE_ADD + 0x0C))
#define		GPIOD_IDR	            *((volatile u32 *)(GPIOD_BASE_ADD + 0x10))
#define		GPIOD_ODR		    	*((volatile u32 *)(GPIOD_BASE_ADD + 0x14))
#define		GPIOD_BSRR		    	*((volatile u32 *)(GPIOD_BASE_ADD + 0x18))
#define		GPIOD_BRR		    	*((volatile u32 *)(GPIOD_BASE_ADD + 0x28))


#define		GPIOF_MODER				*((volatile u32 *)(GPIOF_BASE_ADD + 0x00))
#define		GPIOF_OTYPER			*((volatile u32 *)(GPIOF_BASE_ADD + 0x04))
#define		GPIOF_OSPEEDR			*((volatile u32 *)(GPIOF_BASE_ADD + 0x08))
#define		GPIOF_PUPDR		        *((volatile u32 *)(GPIOF_BASE_ADD + 0x0C))
#define		GPIOF_IDR	            *((volatile u32 *)(GPIOF_BASE_ADD + 0x10))
#define		GPIOF_ODR		    	*((volatile u32 *)(GPIOF_BASE_ADD + 0x14))
#define		GPIOF_BSRR		    	*((volatile u32 *)(GPIOF_BASE_ADD + 0x18))
#define		GPIOF_BRR		    	*((volatile u32 *)(GPIOF_BASE_ADD + 0x28))


#endif /* DIO_PRIV_H_ */
