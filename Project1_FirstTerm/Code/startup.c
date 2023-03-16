
// Startup.c
// Abdalla Elbahrawy


#include <stdint.h>


extern int main(void);

void Reset_Handler () ;
// Prototypes
void Defalut_Handler()
{
	// Any thing that happens will go to Defaullt_Handler()
	// You just put a prototype for them
	// You can define them in multiple files
	Reset_Handler();
}

void NMI_Handler () __attribute__((weak, alias("Defalut_Handler")));
void Hard_Fault_Handler () __attribute__((weak, alias("Defalut_Handler")));
void MM_Fault_Handler () __attribute__((weak, alias("Defalut_Handler")));
void Bus_Fault () __attribute__((weak, alias("Defalut_Handler")));
void Usage_Fault_Handler () __attribute__((weak, alias("Defalut_Handler")));

extern unsigned int _stack_top;

// Global (.data), We want to put this array in .vectors section
// __attribute__ based on the toolchain, passing an option to the compiler
uint32_t vectors[] __attribute__((section(".vectors"))) = {

	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &Hard_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler

}; 

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler(void)
{
	// Copy data section from flash to SRAM
	// & Because it isn't variable, it is a symbol
	// We don't have any command in C that defines symbols
	// Just a casting to tell compiler that it is an address
	// We want to copy it byte by byte
	unsigned int DATA_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
	unsigned char * P_src = (unsigned char *)&_E_text;
	unsigned char * P_dst = (unsigned char *)&_S_DATA;

	for(int i = 0 ; i < DATA_size ; i++)
	{
		*((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
	}


	// Init .bss in SRAM and initialize with zero
	unsigned int bss_size = (unsigned char *)&_S_bss - (unsigned char *)&_E_bss;
	P_dst = (unsigned char *)&_S_bss;
	for(int i = 0 ; i < bss_size ; i++)
	{
		*((unsigned char *)P_dst++) = (unsigned char)0;
	}

	// jump main()
	main();
}
