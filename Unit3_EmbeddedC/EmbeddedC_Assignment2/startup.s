@@ Abdall Elbahrawy (First Startup)

.globl reset
reset:
	ldr sp, =stack_top
	bl main

stop: b stop