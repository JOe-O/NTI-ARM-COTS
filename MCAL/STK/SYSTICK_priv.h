#define STK_CTRL	*((volatile u32*)0xE000E010)
#define STK_LOAD	*((volatile u32*)0xE000E014)
#define STK_VAL		*((volatile u32*)0xE000E018)

#define SYSTICK_ENABLE   0x00000001
#define SYSTICK_DISABLE  0xFFFFFFFE
