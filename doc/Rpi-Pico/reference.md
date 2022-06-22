
-----------------------------------------------------------

In-depth: Raspberry Pi Pico's PIO - programmable I/O!		stacksmashing Mar 9, 2021
  https://youtu.be/yYnQYF_Xa8g  
64,723 views
2.6K
138K subscribers
In this video we take an in-depth look into the new Raspberry Pi Pico/RP2040 high-speed programmable I/O system: PIO!
For a high level video check 
  
  https://www.youtube.com/watch?v=o-tRJ...
I know this video is quite fast-paced and dense, but I'm trying to experiment with different formats for these in-depth videos :)
Errata:
- 8:20 - the register is always decremented, not only if the condition is met
- 9:01 - The pin will be OFF for one cycle and ON for 2 cycles - said it the other way around accidentally
- Pico PIO examples: 
  https://github.com/raspberrypi/pico-examples/tree/master/pio  
- C SDK Book: 
  https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf  
- BBC Micro Emu on the Pico: 
  https://youtu.be/WaPJmCgseQw  
Timestamps:
00:00:00​ - Intro
00:01:15​ - PIO architecture
00:02:30 - The state machine
00:05:30​ - IO Mapping
00:06:56​ - Set Instruction
00:07:47​ - Jump Instruction
00:09:08​ - Mov Instruction
00:10:23 - In/Out Instructions
00:10:53 - Push/Pull Instructions
00:11:43 - IRQ Instruction
00:12:47 - Wait Instruction
00:13:38 - Delay
00:14:45 - Side-Set
00:15:48 - Program Wrapping

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 1 - Overview with Pull, Out, and Parallel Port		Life with David May 12, 2021
  https://youtu.be/YafifJLNr6I  
10,779 views
591
2.64K subscribers
Join David as he introduces us to the Raspberry Pi Pico's PIO features with theory and examples.   Part 1 looks at programming a parallel port on the Pico for outputting 8 bit data to a 6502 computer. 
Good PIO Theory Video: https://www.youtube.com/watch?v=yYnQY...
PIO code used in video: https://github.com/LifeWithDavid/Rasp...
00:00 - Introduction
00:38 - PIO Overview
03:00 - PIO Instructions
03:23 - State Machines
03:50 - GPIO Pin Mapping
05:40 - PIO Program Example
10:58 - PIO Parallel Port Demo
11:47 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 2 - Side Set, Wait, and Handshaking		Life with David May 25, 2021
  https://youtu.be/BAP_n7gxg6M  
5,387 views
317
2.64K subscribers
Join David as he explores handshaking on the Raspberry Pi Pico using the Programmable Input/ Output Wait and Side Set features. 
Data Ready with Side Set code: https://github.com/LifeWithDavid/Rasp...
Handshaking with Dual PIOs code: https://github.com/LifeWithDavid/Rasp...
00:00 - Introduction
00:52 - Handshaking
01:53 - PIO Instruction Review
02:22 - Side Set Option
02:52 - Delay Option
03:10 - Combined Options
03:25 - Side Set Example
05:34 - Dual PIO Handshaking
07:19 - Wait Instruction
08:55 - Handshaking Demonstration
10:00 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 3 - Parallel Data Transfer to a 6502		Life with David Jun 7, 2021
  https://youtu.be/dGNJGC_wZtk  
2,869 views
197
2.64K subscribers
Join David as he incorporates all the tools he has learned to implement PIO parallel data transfer between the Pico and his homebuilt 6502 computer.
Sorry about the sloppy transition @1:04.  Had a glitch during editing; it was supposed to be much cooler.
The code for this project can be found here:
  https://github.com/LifeWithDavid/Pico...
00:00 - Introduction
00:47 - Review of Bit Bang data transfer
01:17 - Converting Bit Bang program to PIO
03:23 - Explaining the PIO data transfer program
05:47 - Removing previously required hardware
06:18 - Testing the PIO data transfer program
07:39 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 4 - PIO Timing		Life with David Jun 19, 2021  
  https://youtu.be/7PDuECyrgX0  
2,890 views
227
2.64K subscribers
Join David as he examines the timing functions and features of the RP 2040 PIO that can be used for time critical applications.
00:00 - Introduction
01:05 - Timing Instructions
01:22 - The Set Instruction
01:50 - Frequency
02:34 - Frequency Timing Demonstration
03:48 - NOP
04:50 - Delay
07:18 - Delay time vs. number of Sidesets
08:42 - Jump vs. Wrap
09:33 - Wait
09:57 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 6 - VGA Video and C/C++		Life with David Sep 23, 2021  
  https://youtu.be/mrThmFlgV_s  
4,138 views
257
2.64K subscribers
Join David as he investigates VGA video on a Raspberry Pi Pico (RP2040).  What more will we need to know before we can write our own VGA programs?
00:00 - Introduction
00:48 - MicroPython vs. C/C++
01:35 - VGA introduction and Pico Hardware Interface
03:55 - Setting up to Compile C/C++ Code
04:58 - Getting and Compiling the Video Demos
06:44 - Downloading files into the Pico
07:29 - Video Demonstrations
08:53 - How does it work?
10:42 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 7 - C/C++ Introduction to Writing, Compiling and Running PIO programs		Life with David Oct 10, 2021
  https://youtu.be/zeudTftbTmw  
2,465 views
125
2.64K subscribers
Join David as he programs, compiles and runs simple Raspberry Pi Pico PIO programs in C.  Introduction to the PIO assembler, Cmake and nmake are included.
00:00 - Introduction
00:46 - MicroPython vs. C/C++
02:53 - Convert MicroPython to C - PIO assembler
06:37 - C Mina Program
07:38 - Cmake
08:46 - CMakeLists
10:08 - Compiling
12:52 - Build Files
13:39 - Running Example 1
14:05 - More Complexity 
15:29 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 8 - Introduction to DMA		Life with David Oct 25, 2021  
  https://youtu.be/OenPIsmKeDI  
3,642 views
190
2.64K subscribers
Join David as he explores Direct Memory Access (DMA) for the RP2040.  Included are examples of how DMA works with PIO and IRQ.
Files for this episode:  
  https://github.com/LifeWithDavid/Raspberry-Pi-Pico-PIO/commit/d060dead08dc1f8abf97eb4c92e5cfe83da5d1a5  
00:00 - Introduction
00:44 - DMA Structure
02:57 - Simple DMA-PWM Fade LED Example
03:39 - Initialize PWM
05:09 - Configure DMA
08:10 - Rune the DMA-PWM Example
08:41 - DMA-PIO-IRQ LED Example
09:31 - PIO Program
12:01 - Main C program
12:34 - Interrupt Handler
14:13 - Configure PIO
14:43 - Configure DMA
16:30 - Run the DMA-PIO-IRQ Example
16:44 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 9 - Direct Memory Access and Pulse Width Modulation: A Deeper Dive		Life with David Nov 25, 2021  
  https://youtu.be/-Wh3SIAl0Ic  
1,837 views
102
2.64K subscribers
Join David as he takes a deeper dive into Direct Memory Access (DMA) and Pulse Width Modulation (PWM) for the RP2040.  Included is an example on sequencing through a series of GPIO pins without any processor involvement after the sequence has started.
00:00 - Introduction
01:32 - DMA refresher
02:15 - DMA chaining and aliases
05:00 - PWM details, slices, and channels
07:30 - Detailed example
08:15 - PWM code
09:50 - DMA code
18:45 - Closing
Links:
Files for this episode:
  https://github.com/LifeWithDavid/Raspberry-Pi-Pico-PIO/blob/main/dma_step_fade.c  


-----------------------------------------------------------

-----------------------------------------------------------


Raspberry Pi Pico PIO - VGA: Homebrew Video Interface Program Ep.12		Life with David Feb 11, 2022  
  https://youtu.be/ZEBkM5FQ86Q  
850 views
2.64K subscribers
Join David as he programs a homebrewed VGA interface for the Raspberry Pi Pico using DMA and PIO.  
Link for files used in this video:  
  https://github.com/LifeWithDavid/Raspberry-Pi-Pico-PIO/blob/fc3e25c3d254869be01189d5546fb8b737f302c3/Episode%2012%20Files.txt  
00:00 - Introduction
01:19 - VGA sync pulses
02:09 - Horizontal timing PIO program
04:20 - Vertical timing PIO program
07:19 - Video Output PIO program
09:53 - Controlling C program
10:55 - Sync pulse interrupt handler
11:59 - Main C program
12:46 - DMA configuration
14:30 - First images
15:00 - Display tearing investigation
17:14 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 13 - PIO and the Arduino IDE		Life with David Feb 28, 2022
  https://youtu.be/gtmuTtuOQ0w  
631 views
2.64K subscribers
Earle Philhower RP2040 core link:
  Raspberry Pi Pico Arduino core, for all RP2040 boards   
  https://github.com/earlephilhower/arduino-pico  
Link to files for this Episode:  
  https://github.com/LifeWithDavid/Raspberry-Pi-Pico-PIO/blob/93ba387d3d4ac3bf744e2275d88b8763faef377d/Episode%2013%20Arduino%20IDE%20files.txt  
00:00 - Introduction
00:35 - MicroPython and C/C++
01:08 - The Arduino IDE
01:34 - Installing the Arduino IDE
03:06 - Running two simple sketches
04:30 - Running an RP2040 PIO sketch
08:36 - Detailed program explanation
10:46 - Programs not adhering to the Arduino IDE standard format
11:52 - Closing

-----------------------------------------------------------

Raspberry Pi Pico PIO - Ep. 14 - Arbitrary Waveform Generator		Life with David Apr 22, 2022
  https://youtu.be/_lZ1Pw6WAqI  
523 views
91
2.88K subscribers
Join David as he uses the Raspberry Pi Pico (RP2040) as an Arbitrary Waveform Generator.  This episode includes Direct Memory Access, Programmable Input Output, and the theory and building of a Digital to Analog converter.  
Link to program files for this Episode:  
  https://github.com/LifeWithDavid/Raspberry-Pi-Pico-PIO/blob/d244a4b7d0b5c187c08e7311026b45fdff7da13e/EP%2014%20AWG%20Files.txt  
00:00 Introduction
00:35 Function Generator History 
01:20 Using a Raspberry Pi Pico as an AWG
02:28 Digital to Analog Convertor Theory
04:04 Building the DAC
04:48 The Amplifier
05:17 Proof of Concept MicroPython Program
05:37 DMA Theory
06:25 AWG C program details
11:10 AWG PIO program details
12:33 Testing the AWG
13:38 AWG Frequency Accuracy
13:55 Closing


===========================
end of file 
