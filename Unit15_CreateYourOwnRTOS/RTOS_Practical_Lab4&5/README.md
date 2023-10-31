# Create My Own RTOS lab 4&5 {Latest version of my RTOS v1.0}

### CPU Utilization
- When all tasks are suspended, CPU runs idle task.
- To conserve power and enter a sleep mode, you can employ the "wfe" instruction to wait for an event.
- The performance analyzer observes a utilization of only 7% of the CPU's processing power.
  
![CPU_Utilization](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/b698415c-27cf-4d5b-80b7-6a8b6560076b)  
------------------------------------------------------------

### Tasks with different priorities
- When tasks have different priorities, the schdeuler choose the higher priority task to put in ready queue.
- Higher priority means small numbers (0-255), 0 is the maximum possible priority

![Priority](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/566bcab5-0fae-4bf9-888a-de1025230b18)
----------------------------------------------------------------

### Priority based round-robin
- When tasks have the same priority, they run based on round-robin scheduling.
- Until, another task with higher priority is activated, then the scheduler will choose to run this task till termination or suspending.

![Round-Robin_Priority](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/f3dfce2a-f743-4fc3-bb03-a881eff9ef2c)
----------------------------------------------------------------


### Task wait
- Suspending tasks according to a predefined time duration.
- For example, run a particular task each 100ms.
  
![TaskWait](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/3c7b6c4e-8af7-45f9-97a1-30e3185e6990)
----------------------------------------------------------------

### Mutex implementation && Priority inversion problem
- A mutex (short for mutual exclusion) is a synchronization mechanism used to protect shared resources and ensure that only one task or thread can access them at a time.
- Priority inversion is a situation in real-time systems where a higher-priority task is delayed due to the temporary blocking by a lower-priority task, often caused by resource conflicts or synchronization mechanisms.
- In normal cases, when a task with lower priority acquires a mutex, and a highe priority task want to acquire the same mutex, then the higher priority task will get suspended temporarily till the release of this mutex.

### Priority inheritance
- Priority inheritance is a real-time scheduling technique that temporarily boosts the priority of a task to prevent priority inversion and ensure timely execution of high-priority tasks.
- Instead of the last scenario where the higher priority task got suspended for a long time especially when there are multiple tasks.
- I made the lower priority task inherit the priority from the highe priority task which wants to acquire the mutex, and when releasing the lower priority task restore its original priority.


![Mutex](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/b7a92ae4-6409-4a7b-aa42-40decce01ee2)
![PriorityInversion2](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/dcdd1470-e96a-4427-8054-7b5cd26a2165)

----------------------------------------------------------------

## Deadlock
- Deadlock is a state in a computer system where two or more processes or threads are unable to proceed because each is waiting for the other to release a resource, causing a standstill in the execution of tasks.
- I solved this problem using a simple algorithm which forces tasks not to acquire more than mutex, then if a task already acquired a mutex, and want to acquire another one, the second acquiring won't get executed.
- Note, there are other advanced algorithms to solve this issue such as:
    - Timeouts and Retry Mechanisms: Set timeouts on resource requests, allowing processes to release and retry if resources are not obtained within a specified time. 
    - Lock Hierarchy: Ensure consistent resource request and release orders to establish a hierarchy among resources and prevent circular waits.
- These algorithms will be considered in next versions inshallah 😊

![Deadlock](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/39214e07-d710-4741-ba91-7d4180cff8e3)

![PreventDeadlock](https://github.com/bahrawyyy/Mastering-Embedded-Systems-Online-Diploma/assets/71684437/82f33928-a304-4678-9ddc-fc2c60bca0ec)
