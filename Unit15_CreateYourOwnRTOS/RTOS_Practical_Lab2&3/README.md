# Create My Own RTOS lab 2&3

### Update Scheduler table & Ready Queue
- Update and sort scheduler table based on priority using one of sorting algorithms (Currently: BubbleSort)
- Update ready Queue by adding the highest priority task(s) to it taking in consideration same priority tasks will run round-robin
- Based on the tasks in the ready Queue, we will decide which task should run next     
  
![SortingTasks](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/7afa40fb-184a-4f36-8a62-3400c4d01230) 
------------------------------------------------------------

### Switch context & Restore
- When transitioning between tasks, the CPU will autonomously manage the preservation and restoration of xPSR, PC, LR, R12, R3, R2, R1, and R0 in the current task's stack
- Our responsibility is to ensure that the remaining registers are appropriately pushed and popped in the task's stack to uphold their values during this context switch and restoration process.
  
![SwitchContext](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/0484840c-6f13-4dae-91ec-ba222cde0ccb)
----------------------------------------------------------------

### Tasks in action
- First when their is no tasks, the idleTask will run by default, and it has the least possible priority
- When creating and activating tasks, the OS will decide which will run next based on priority
- If same priority tasks, then they will run round-robin
  
![RoundRobin](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/db561720-7104-489c-8cd5-15a5a1928405)

