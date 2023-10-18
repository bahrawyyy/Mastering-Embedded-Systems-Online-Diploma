# Create My own RTOS (First Lab)

## Calculating and creating main stack size
- _S_MSP holds the address pointed to by the stack pointer (This info is provided in the linker script)
- Based on the size I choosed, which is 2Kbytes (0x800), _E_MSP holds the calculated value to point to the end of the main stack
- Finally, aligning 8 bytes between the main and process stack, and the resulted address will be stored in PSP_Locator which will be useful in creating stacks for tasks  
![MainStackSize](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/8d106280-f2a7-490e-9e97-7f71f668b4f0)

------------------------------------------------------------------------------------
## Providing configuration for the idle task
- This idle task runs in the background, and I've defined their configurations
- I've defined its priority to be the least, which is for now (255), and calculated and created its stack  
![IdleTaskConfiguration](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/9a45eb2a-6e26-4c1c-9fb5-d9269af169ee)


------------------------------------------------------------------------------------
## Providing configurations for tasks provided by the user
- Creating stack for the task after getting it from user, getting its entry, name, and providing its state, which is "suspend" for now  
![Task1Config](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/f773cf4b-1cb9-4e40-8118-f4afeecf7cb6)


------------------------------------------------------------------------------------
## Deep look inside stacks of tasks
- Inside the stack of both idle task and task1 provided by the user, I have pushed the registers inside their stacks
- Pushing: R0-R12, LR, PC, and xPSR, and putting dummy values inside them for now  
![StackConfiguration](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/40540968-ae2d-4d49-9368-8f200ff8fc51)


------------------------------------------------------------------------------------
## Full view of all tasks
- In this picture, all the configurations for the tasks are provided, their stacks are created, and their entries are defined
![AllTasks](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/ba76cca7-ab42-47b3-8652-65cf15af876c)
