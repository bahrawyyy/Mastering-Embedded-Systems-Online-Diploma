// Lab3 ->> Learn-in-depth
// Abdalla Elbahrawy

// long --> 4byte

#define SYSCTL_RCG2_R 		(*(volatile unsigned long*)(0x400FE108))
#define GPIOA_PORTF_DIR_R 	(*(volatile unsigned long*)(0x40025400))
#define GPIOA_PORTF_DEN_R 	(*(volatile unsigned long*)(0x4002551C))
#define GPIOA_PORTF_DATA_R 	(*(volatile unsigned long*)(0x400253FC))



int main()
{	
	// To make sure that it won't be deleted from optomozation
	volatile unsigned long delay_count;
	// You have to make delay after enabling the clock to make sure
	// that GPIOFA is up and running
	SYSCTL_RCG2_R = 0x20;
	for (delay_count = 0; delay_count < 200; delay_count++);
	GPIOA_PORTF_DIR_R |= (1<<3);  // Dir --> output for pin3
	GPIOA_PORTF_DEN_R |= (1<<3);
	while(1)
	{
		GPIOA_PORTF_DATA_R |= (1<<3);
		for (delay_count = 0; delay_count < 200000; delay_count++);
		GPIOA_PORTF_DATA_R &= ~(1<<3);
		for (delay_count = 0; delay_count < 200000; delay_count++);
	}

	return 0;
}