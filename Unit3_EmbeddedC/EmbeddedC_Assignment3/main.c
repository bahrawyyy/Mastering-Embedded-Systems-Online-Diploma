typedef volatile unsigned int vuint32_t;

#define RCC_BASE     0x40021000
#define GPIOA_BASE   0x40010800

#define RCC_APB2ENR    *(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH    *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(vuint32_t *)(GPIOA_BASE + 0x0C)


typedef union{
	vuint32_t   allFields;
	struct{
		vuint32_t  reserved:13;
		vuint32_t Pin13:1;
	}Pin;
}R_ODR_t;


volatile R_ODR_t * R_ODR = (volatile R_ODR_t *)(GPIOA_BASE + 0x0C);
unsigned char g_variables[3] = {1,2,3};   // Just to put in .data
unsigned char const const_variables[3] = {1,2,3};   // And this in .rodata
unsigned char bss_var[3];


int main(void)
{
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH &= 0xff0fffff;   // To keep the status of other bytes
	GPIOA_CRH |= 0x00200000;

    while(1){
//    	GPIOA_ODR |= (1<<13);
//    	for(int i=0 ; i< 5000 ; i++);   // Arbitary delay
//    	GPIOA_ODR &= ~(1<<13);
//    	for(int i=0 ; i< 5000 ; i++);   // Arbitary delay
    	R_ODR->Pin.Pin13 = 1;
    	for(int i=0 ; i< 5000 ; i++);   // Arbitary delay
    	R_ODR->Pin.Pin13 = 0;
    	for(int i=0 ; i< 5000 ; i++);   // Arbitary delay
    }
return 0;
}
