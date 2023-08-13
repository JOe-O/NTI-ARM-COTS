#ifndef __TYPEDEF_H
#define __TYPEDEF_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;
typedef double d64;
typedef long double d128;




typedef union{
	struct{
		u32 BIT_0: 1;
		u32 BIT_1: 1;
		u32 BIT_2: 1;
		u32 BIT_3: 1;
		u32 BIT_4: 1;
		u32 BIT_5: 1;
		u32 BIT_6: 1;
		u32 BIT_7: 1;
		u32 BIT_8: 1;
		u32 BIT_9: 1;
		u32 BIT_10: 1;
		u32 BIT_11: 1;
		u32 BIT_12: 1;
		u32 BIT_13: 1;
		u32 BIT_14: 1;
		u32 BIT_15: 1;
		u32 BIT_16: 1;
		u32 BIT_17: 1;
		u32 BIT_18: 1;
		u32 BIT_19: 1;
		u32 BIT_20: 1;
		u32 BIT_21: 1;
		u32 BIT_22: 1;
		u32 BIT_23: 1;
		u32 BIT_24: 1;
		u32 BIT_25: 1;
		u32 BIT_26: 1;
		u32 BIT_27: 1;
		u32 BIT_28: 1;
		u32 BIT_29: 1;
		u32 BIT_30: 1;
		u32 BIT_31: 1;

	}Bits;
	u32 Whole_Register;
}tuniReg;




#endif
