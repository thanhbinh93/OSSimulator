"# OSSimulator" 
Operating System Simulator 
+ The project will simulate a simple computer system consisting of a CPU and Memory.
+ The simulator illustrates some important low-level concepts of an operating system:
	a.	Processor interaction with main memory.
	b.	Processor instruction behavior.
	c.	Role of registers.
	d.	Stack processing.
	e.	Procedure calls.	
	f.	System calls.
	g.	Interrupt handling.
	h.	Memory protection.
	i.	I/O.
	
Installing
	+ Build project by compiler: GNU GCC Compiler
	+ File .exe will be found ../bin/Debug/Ossimulator_.exe or ../bin/Release/Ossimulator_.exe
	
Run testing
	+ Format intruciton on cmd: [Ossimulator_.exe] [ossimulator] [path file txt] [tick time]
	+ [ossimulator]: argument flag for os simulate
	+ [path file txt]: path to program inlcude optCode that supported by this program
	+ [tick time]: A timer will interrupt the processor after every X instruction
	+ Ex: Ossimulator_.exe ossimulator program1.txt 30
