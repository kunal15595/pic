Added read/write byte to the message functions

Bool ByteWrite(uint8_t MsgID, uint8_t index, uint8_t byte);
uint8_t ByteRead(uint8_t MsgID, uint8_t index);

These two functions can be used to create data structures such as stacks and circular buffers.

Some Pic24F devices such as the PIC24FJ256DA210 have done away with the PSVPAG register and replaced it with DSRPAG and DSWPAG registers. 
Uncomment this line at the top of 'multitask.s' file to add support for those devices.
 
	.equiv NO_PSV_PAGE,1	;Adds support for PIC24FJ256DA210 family.

Unzipping the files should create the correct directory structure.
The default install directory is: C:\PicRtos\

If you change the default install, to succesfully build and run the examples, you may have to point the compiler to the correct directories.

You do this in 'Project/Build Options/Project'/

Depending on the speed of your system, it may take a few seconds for the Logic analyser window to update and Mplab to respond after a break on trace buffer full.

To turn on syntax highlighting, right click in one of the source files in the IDE and choose ‘Properties’, or choose ‘Edit’ from the menu and ‘Properties’ then click on the ‘Text’ tab. Use the browse button to select the 'keywords.txt' file.

Use the 'Build All' speed button or Project option and not the
'Make' button when compiling the examples. Make will not rebuild 'multitask.s' for
the processor variant and the linker will complain,

If Example 3 fails to build, it is because some versions of include file 'p24FJ128GA010.inc' have omitted to define the T1IP2 interrupt priority bit?

;----- IPC0 Bits -----------------------

.equiv INT0IP0, 0x0000
.equiv INT0IP1, 0x0001
.equiv INT0IP2, 0x0002

.equiv IC1IP0, 0x0004
.equiv IC1IP1, 0x0005
.equiv IC1IP2, 0x0006

.equiv OC1IP0, 0x0008
.equiv OC1IP1, 0x0009
.equiv OC1IP2, 0x000A

.equiv T1IP0, 0x000C
.equiv T1IP1, 0x000D 
.equiv T1IP2, 0x000E ;This is the bit they missed!

If you edit the file and add the missing bit, The example will compile and run ok.