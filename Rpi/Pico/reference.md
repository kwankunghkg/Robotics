
BLOG_GitHub_RpiPico_reference_20220705.txt  
  https://github.com/kwankunghkg/Robotics/blob/main/Rpi/Pico/reference.md  
  
last update : 20240106_0157(UTC+8)  
prev update : 20221023_1713(UTC+8)  
prev update : 20220918_1600(UTC+8)  
prev update : 20220705_0608(UTC+8)  
  
----------------------------------------  
  
## Rpi Pico & PicoW  INTRO  
  
----------------------------------------  
  
  
kid-friendly projects, educator-led seminars, and information about our non-profit work, the Raspberry Pi Foundation YouTube channel  
http://rptl.io/rpfyt  
  
  
NEW Raspberry Pi Pico W - your $6 wireless microcontroller  
https://youtu.be/QIdyTlmdVW8  
Raspberry Pi / Jun 30, 2022  
new $6 Raspberry Pi Pico W brings 802.11n wireless networking to Pico platform, while retaining complete pin compatibility with its older sibling.  
http://rptl.io/pico  
  
  
// US$5 for the Pico H, the Foundation has priced the Pico W and Pico WH at US$6 and US$7, respectively. Pico W and Pico H are orderable from today, Pico WH will not launch until August. //  
https://www.notebookcheck.net/Raspberry-Pi-Pico-W-Pico-H-and-Pico-WH-introduced-with-802-11n-Wi-Fi-and-a-new-3-pin-debug-connector.632543.0.html  
  
  
Pico W Overview - Everything you need to know about the newest Pi / pi3g / Jun 30, 2022  
https://youtu.be/4RL4MJ7DVNY  
Raspberry Pi just released Pico W. This variant of the beloved Pico comes with wireless capabilities, thanks to CYW43439 Chip.  
  
  
Pico W Web Server with MicroPython - Control the onboard LED / pi3g / Jun 30, 2022  
https://youtu.be/Or-UVgiMQsU  
Raspberry Pi just released the Pico W. This variant of the beloved Pico comes with wireless capabilities, thanks to the CYW43439 Chip. Learn how to run a MicroPython web server on the Pico W that lets you control the onboard LED over Wi-Fi.  
  
  
code / Pico W GitHub repository  
https://github.com/pi3g/pico-w  
  
  
Pico W Sensor Server - Display Real-time Sensor data over Wi-Fi / pi3g / Jul 4, 2022  
https://youtu.be/grxjmrPT1zQ  
Raspberry Pi just released the Pico W. This variant of the beloved Pico comes with wireless capabilities, thanks to the CYW43439 Chip. Learn how to run a MicroPython web server on the Pico W that displays data from a sensor in real time.  
  
  
RpiPicoW WiFi+BT chip CYW43439  
  
Infineon CYW43439 WiFi module  
  
Murata Electronics - LBEE5KL1YN-814 - SHIELDED SMALL WI-FI 11B/G/N + B  
https://www.murata.com/en-sg/products/connectivitymodule/wi-fi-bluetooth/overview/lineup/type1yn  
datasheet  
https://www.murata.com/products/productdata/8815814344734/type1yn.pdf  
  
  
https://en.wikipedia.org/wiki/Infineon_Technologies  
  
  
  
HK$90.7 (665 In Stock)  
https://www.digikey.hk/en/products/detail/murata-electronics/LBEE5KL1YN-814/16374387  
  
HK$179.44 (庫存量: 1,928)  
https://www.mouser.hk/ProductDetail/Murata-Electronics/LBEE5KL1YN-814?qs=TCDPyi3sCW1FrH0sh%252Bb5wA%3D%3D  
  
HK$78.3 (1 piece)  
HK$720.9 (10 pieces)  
Service Fee HK$56.59  
https://www.arrow.com/en/products/lbee5kl1yn-814/murata-manufacturing  
  
  
US$4 RpiPico /  
US$6 RpiPicoW /  
US$1 RP2040 /  
US$0.7 RP2040 (3.4k quantity) ...  
Raspberry Pi Direct: buy RP2040 in bulk from just $0.70 / Eben Upton / 17th Jan 2022  
https://www.raspberrypi.com/news/raspberry-pi-direct-buy-rp2040-in-bulk-from-just-0-70/  
  
  
Raspberry Silicon update: RP2040 on sale now at $1 / Eben Upton / 1st Jun 2021  
https://www.raspberrypi.com/news/raspberry-pi-rp2040-on-sale/  
  
  
Keeping secrets and writing about Raspberry silicon / Alasdair Allan / 10th Feb 2021  
https://www.raspberrypi.com/news/keeping-secrets-and-writing-about-raspberry-silicon/  
“Hardware design with RP2040” book for inspiration  
https://datasheets.raspberrypi.com/rp2040/hardware-design-with-rp2040.pdf  
  
  
Raspberry fish & RP2040 chip / Ashley Whittaker / 27th Jan 2021  
https://www.raspberrypi.com/news/raspberry-fish-rp2040-chip/  
  
  
Raspberry Pi engineers on the making of Raspberry Pi Pico | The MagPi 102 / Gareth Halfacree / 28th Jan 2021  
https://www.raspberrypi.com/news/raspberry-pi-engineers-on-the-making-of-raspberry-pi-pico-the-magpi-102/  
  
  
Machine learning and depth estimation using Raspberry Pi / David Plowman / 11th Feb 2021  
https://www.raspberrypi.com/news/machine-learning-and-depth-estimation-using-raspberry-pi/  
CVPR 2021 – conference homepage - CVPR (Computer Vision and Pattern Recognition) 2021 conference  
Mobile AI Workshop 2021  
Monocular Depth Estimation Challenge  
  
  
Machine learning, combustion engines and real-time control / Liz Upton / 13th Jan 2015  
https://www.raspberrypi.com/news/machine-learning-engine-control/  
Version 0.1 Raspberry Pi Engine Control with Real-Time, Adaptive Machine Learning (Linux, HCCI) Adam Vaughan Jan 9, 2015  
https://youtu.be/qQG7ocnE3EA  
45,274 views 374 276 subscribers  
This is my first attempt at engine control with an adaptive Extreme Learning Machine algorithm I designed to predict non-stationary, near chaotic Homogeneous Charge Compression Ignition (HCCI) combustion time series in real-time. A high-level overview about the approach is available at:  
https://www.youtube.com/watch?v=_yrLW...  
Pressure data acquisition is recording 240,000 18-bit samples per second (total, all channels) with assembly code added to the Linux kernel in an FIQ. Control commands must be calculated with less than ~300 microseconds of latency to maintain control. I have the control algorithm running in PREEMPT_RT Linux user space and streaming processed data to a d3.js web-based UI over a WebSocket.  
The model training data is from a previous engine in 2012, and took 40 minutes of test cell time to acquire. I haven't re-trained the model for this new engine yet, and only one cylinder's worth of data is used for training (all cylinder models are the same before adaptation).  
A pre-print paper about the algorithm is available at:  
http://arxiv.org/abs/1310.3567  
The final paper is available here:  
http://www.sciencedirect.com/science/...  
  
  
Meet PicoSystem, the tiny hackable handheld based on RP2040 / Ashley Whittaker / 19th Jul 2022  
https://www.raspberrypi.com/news/meet-picosystem-the-tiny-hackable-handheld-based-on-rp2040/  
  
  
A New Handheld Powered By The Same Raspberry Pi Pico Chip! / ETA PRIME / 2021Oct15  
https://youtu.be/m_5voWb7MYU  
88,456 views 2.9K 947K subscribers  
PicoSystem is a pocket-sized handheld gaming console, Powered by the Raspberry Pi's RP2040 chip the same CPU used In the Raspberry Pi Pico!  
This thing is pretty cool and it's a hackable dev handheld gaming console that you can easily make your own games for. Hopefully, in the near future, we can see some emulators like NES PC engine and Gameboy running on the Pico System, and of course I’m waiting for a DOOM port!  
  
  
What is VGA and How to Use it With a Raspberry Pi Pico / Gary Explains / 2022Jul12  
https://youtu.be/KSYjGul84aU  
22,099 views 1K 275K subscribers  
VGA is de-facto PC video standard. It is an analogue video system with a heritage from the IBM PS/2. The Raspberry Pi Pico is fast enough to generate a VGA signal in real time! In this video I look at VGA, how it works, and how to build a simple DAC for generating a VGA signal using the Pico.  
  
  
RP2040 Doom: DOOM1 Demo/Gameplay on a Raspberry Pi Pico / Graham Sanderson / 2022Mar14  
https://youtu.be/eDVazQVycP4  
30,102 views 457 542 subscribers  
  
  
HDMI RpiPico PIO  
https://pi3g.com/products/dvi-sock-raspberry-pi-pico/  
  
  
World’s First RP2040 QWERTY Computer / Chris Lott / May 28, 2021  
https://hackaday.com/2021/05/28/worlds-first-rp2040-qwerty-computer/  
  
  
#PICOmputer​- World first Raspberry RP2040 PICO - QWERTY & IPS devkit / Peter Misenko / Apr 22, 2021  
https://youtu.be/pJGlxj9I5Sg  
11,056 views 291 3.73K subscribers  
  
  
RP2040-PICO-PC small computer made with the Raspberry Pi RP2040-PICO module first prototypes are ready / by OLIMEX Ltd in new product / 09 Apr 2021  
https://olimex.wordpress.com/2021/04/09/rp2040-pico-pc-small-computer-made-with-the-raspberry-pi-rp2040-pico-module-first-prototypes-are-ready/  
  
  
FreeRTOS Kernel SMP for the Raspberry PI Pico / Dr Jon EA Ltd / Sep 23, 2022  
https://youtu.be/nD8XeWjn-2w  
3,033 views / 107 / 100 subscribers  
Tutorial on using #FreeRTOS Kernel #SMP for the #RaspberryPIPico. Code for the example is on github at:  
https://github.com/jondurrant/RPIPicoFreeRTOSSMPExp  
Clone using the command:  
git clone --recurse-submodules https://github.com/jondurrant/RPIPicoFreeRTOSSMPExp  
For more on #FreeRTOS Kernel on Pico or #rp2040 please checkout my Udemy course:  
https://www.udemy.com/course/freertos-on-rpi-pico/?referralCode=C5A9A19C93919A9DA294  
  
  
SMP Demos for the Raspberry Pi Pico Board  
https://www.freertos.org/smp-demos-for-the-raspberry-pi-pico-board.html  
  
  
Symmetric Multiprocessing Branch of FreeRTOS Gets Ported to the Raspberry Pi Pico, RP2040  
https://www.hackster.io/news/symmetric-multiprocessing-branch-of-freertos-gets-ported-to-the-raspberry-pi-pico-rp2040-7709ab0333d2  
  
  
FreeRTOS kernel files  
https://github.com/FreeRTOS/FreeRTOS-Kernel/tree/smp  
  
  
Pico Tutorials / Learn Embedded Systems / 18 videos Last updated on Mar 21, 2022  
https://www.youtube.com/playlist?list=PLEB5F4gTNK68IlRIJtcJ_2cW4dSdmreTw  
1 First Look at the Raspberry Pi Pico: Physical Overview  
2 How to Set Up Visual Studio Code to Program the Pi Pico (Windows)  
3 How to Set Up a Project in Visual Studio Code for the Pi Pico - Blink LED  
4 Soldering Header Pins to your Raspberry Pi Pico  
5 Getting Started with USB Serial Output on the Raspberry Pi Pico  
6 Getting Started with Multicore Programming on the Raspberry Pi Pico  
7 How to Use the Temperature Sensor on the Raspberry Pi Pico in C  
8 Beginners Guide to I2C on the Raspberry Pi Pico (BNO055 IMU Example)  
9 USB Serial Input on the Raspberry Pi Pico  
10 Beginners Guide to SPI on the Raspberry Pi Pico (BMP280 Example)  
11 How to Debug the Raspberry Pi Pico Using Another Pico! - Picoprobe and VSCode Tutorial  
12 Programming the Raspberry Pi Pico in the Arduino IDE!  
13 It's Official! Arduino IDE Support for the Raspberry Pi Pico - How to Install  
14 How To Use FreeRTOS on the Raspberry Pi Pico (RP2040) Part 1: VSCode Setup and Blinky Test!  
https://learnembeddedsystems.co.uk/freertos-on-rp2040-boards-pi-pico-etc-using-vscode  
15 FreeRTOS on the Raspberry Pi Pico (RP2040) Part 2: Tasks and Queues  
https://learnembeddedsystems.co.uk/freertos-part-2-tasks-and-queues-tutorial  
16 FreeRTOS on the Raspberry Pi Pico (RP2040) Part 3: Scheduling and Task Priorities  
https://learnembeddedsystems.co.uk/freertos-on-the-rp2040-part-3-source-code  
17 FreeRTOS on the Raspberry Pi Pico (RP2040) Part 4: Mutex  
https://learnembeddedsystems.co.uk/freertos-on-the-rp2040-part-4-source-code  
18 FreeRTOS on the Raspberry Pi Pico (RP2040) Part 5: Semaphores  
https://learnembeddedsystems.co.uk/freertos-on-the-rp2040-part-5-semaphores  
  
  
A Raspberry Pi Pico conducts this lo-fi orchestra / Ashley Whittaker / 19th Oct 2022  
https://www.raspberrypi.com/news/a-raspberry-pi-pico-conducts-this-lo-fi-orchestra/  
  
  
Commodore 64 + Raspberry Pi 4 = Synth6581 / Simon Martin / 18th Jun 2021  
https://www.raspberrypi.com/news/commodore-64-raspberry-pi-4-synth6581/  
  
  
ordered 5 from kiwi-electronics  
https://www.kiwi-electronics.com/en/raspberry-pi-pico-w-10938  
5 * € 6.57 = € 32.85  
Postal Mail (no tracking): € 3.26  
Sub-Total (Ex. Taxes): € 36.12  
Total: € 36.12 = HKD 280.47  
  
  
    
  
----------------------------------------  
  
## Rpi Pico & PicoW  DEMO  
  
----------------------------------------  
  
Raspberry Pi Pico RP2040 Programming in MicroPython, Complete Course for Beginners with Examples / Electronic Clinic /  Mar 3, 2022  Raspberry Pi Pico Projects  
https://youtu.be/rAGw-08IOSw  
73K subscribers / 52,711 views  //   
  
  
  
Step-by-Step Pi Pico W: WIFI, gpio Control and Webserver / Lutz /  Jul 23, 2022  Pi Pico  
https://youtu.be/fqsOZ_FVgfg  
1.1K subscribers / 12,007 views  //   
	00:00 Introduction  
	01:00 initail setup (wlan scan and mac)  
	02:40 blinking on board LED  
	03:58 Initial Wlan / Wifi (wlan scan and mac)  
	06:57 Static Website  
	14:15 Website with GPIO control and state display  
	In this tutorial i show how to setup a raspberry Pi Pico w (or other board with a RP2040 and WiFI) and i show how to setup the WLAN and read out the Mac address. I explain how to update the UF2 file I´m showing how to setup a Website and control GPIO´s with it. For the programming code i´m using Micro Python.  
  
  
***** Creating a WiFi App for Pi Pico W / Lutz /  Aug 22, 2023  Pi Pico  
https://youtu.be/znwLqv2otRQ  
1.09K subscribers / 1,877 views  //   
	I Explain how to create a socket for WiFi communication in KOTLIN with android studio to Build your own app, setp the Internet permission and a micropyhton Sever running on a @raspberrypi pico W in thonny to reacte to the socket commands.  
SW Links:  
	https://developer.android.com/studio  
	https://thonny.org/  
	https://github.com/LutzEmbeddedTec/Pico_app  
  
  
***** Real time clock sync over WiFi - Pi Pico w - in 6 Minutes / Lutz /  Jan 28, 2023  Pi Pico  
https://youtu.be/fItvY5JIvo8  
1.1K subscribers / 4,501 views  //   
	In this Video i explain the usage of the RTC real time clock in combination with the NTP Protocoll and update with the WIFI module for the @raspberrypi pico W.  
	examples in micro pyhton, for the RTC function, NTP (network time protocol) snyc and how th run a alarm a defined time.  
	  https://github.com/LutzEmbeddedTec/Pico_w_RTC  
  
  
  
  
  
  
Using Raspberry Pi Pico W with Telegram Bot  
  https://www.cytrontech.vn/tutorial/using-raspberry-pi-pico-w-with-telegram-bot  
  
Getting Started: Using Raspberry Pi Pico W with Telegram Bot / Cytron Technologies /  Jun 9, 2023  #CircuitPython #RaspberryPi #Telegram  
https://youtu.be/hHQu4O9OnVo  
26.7K subscribers / 1,658 views  //   
	In this video, we will guide you through the process of utilizing Telegram to control and communicate with your Raspberry Pi Pico W. By the end of this tutorial, you will acquire the knowledge and skills necessary to send commands from Telegram to your Pico W, enabling you to perform specific actions effortlessly. The potential applications are vast and exciting! 💡🚀  
	📄 Tutorial:   
	  https://my.cytron.io/tutorial/using-raspberry-pi-pico-w-with-telegram-bot  
	👉 The code has been developed by Dr. Norasmad, and you can access it through the provided links below:  
	- settings.toml:   
	  https://github.com/mymadi/FKTE-Cytron/blob/main/Basic_Kits/18%20WiFi%20Connect/settings.toml  
	- telegram_bot:   
	  https://github.com/mymadi/FKTE-Cytron/blob/main/Basic_Kits/19%20Telegram%20Bot/19telegram_bot_ex1.py  
  
  
  
  
Raspberry Pi Pico W Telegram Bot CircuitPython 8.0.0-beta.2 Internet of Things IoT / Idrisz my /  Oct 15, 2022  
https://youtu.be/Qfp911u12iU  
887 subscribers / 2,146 views  //   
  
  
  
Pico W Wi-Fi Doorbell - With HTTP Requests and IFTTT / pi3g /  Jul 12, 2022  Raspberry Pi Pico W  
https://youtu.be/uYWIA4h-y6s  
2.03K subscribers / 9,077 views  //   
	Use your Raspberry Pi Pico W as a smart doorbell, that sends you e-mails or app notifications. That way you can see that someone is at the door, even if you are not at home.  
Step-by-step tutorial:   
  https://picockpit.com/raspberry-pi/raspberry-pi-pico-w-wi-fi-doorbell-tutorial/  
  
  
Let's Get Started with the PICO W / Making Stuff with Chris DeHut /  Jul 7, 2023  Raspberry Pi Pico, CNC, Electronics, Sensors, Arduino, Raspberry PI, Python  
https://youtu.be/OoL4ESJeNew  
8.15K subscribers / 6,399 views  //   
	In this video we will cover the very basics of obtaining the proper UF2 file and installing it into the PICO.  Also covered is an example program that will be used as a framework for several other videos on this channel.  This particular example program creates a nice looking webpage that the PICO W can serve and it has a nice graphical interface for sending data to the PICO W.  
  
  
E10 Can a Hall Effect sensor by used for localisation in ZoomTown / Making Stuff with Chris DeHut /  Dec 15, 2023  #HallEffect #PICO #Robotics  
https://youtu.be/bvUDoVqfDv0  
8.16K subscribers / 188 views  //   
	E010 - Localisation is critical for autonomous robot navigation, often requiring multiple sensors.  While exploring a hall effect sensor for localisation, it was discovered it might also be useful for reading the road signs in ZoomTown.  
	#HallEffect, #A3141,  
	Some of the technologies explored in this experiment include, but is certainly not limited to:  
	[*] Autonomous Robotics  
	[*] Photo reflective sensors  
	[*] Time of flight sensors  
	[*] Hall effect sensors  
	[*] Rotary encoders  
	[*] Odometry  
	[*] Line following  
	[*] Color recognition and detection sensor  
	[*] Automatic route planning  
	[*] Localization  
	[*] Robotic cars  
	[*] Dead Reckoning  
  
  
  
  
  
How to make a Bluetooth remote using a Raspberry Pi Pico W and MicroPython / Kevin McAleer /  Premiered Jul 3, 2023  #Pico​ #MicroPython​ #Robotics  
https://youtu.be/-0wCtKz1l78  
24.1K subscribers / 12,782 views  //   
	00:00 Introduction  
	00:10 Bluetooth Announcement  
	00:28 Bluetooth Basics  
	01:24 Profiles  
	02:28 Bluetooth connection stages  
	03:45 Generic Attribute Profiles  
	04:19 Synchronous vs Asynchronous code  
	06:25 Asynchronous coding  
	10:00 BLE Services and Characteristics  
	12:45 Demo - BurgerBot  
	14:26 VS Code - creating the code  
	14:38 Remote-control.py  
	28:34 Debugging the code  
	29:40 Bluetility  
	31:47 testing remote_control.py   
	31:59 robot_code.py  
	43:57 Remotely Controlling the robot with bluetooth  
	44:19 PCBWay Sponsor  
  
  
  
New Use for Raspberry Pi Pico W -- ESPHome and Home Assistant! / mostlychris /  Nov 28, 2022  Bluetooth (BLE)  
https://youtu.be/oQpEWwXqnbM  
28.8K subscribers / 20,781 views  //   
	Install ESPHome on the Raspberry Pi Pico W. Integrate it with Home Assistant to start using it with your smart home.  
  
  
  
  
How to create a raspberry PI TelegramBot - Part 1 / CMTEQ /  May 10, 2023  Python Programming the Easy way.  
https://youtu.be/OytL_ssA8Xc  
2.64K subscribers / 434 views  //   
	In this tutorial we take you through the basic steps of creating a Telegram Bot, an application capable of sending text messages and photos into a telegram group chat, this application will be build using python script and we will use the raspberry PI as our sever.  
	Things to learn here:  
	-  Raspberry PI Linux commands  
	-  Python script  
	-  Telegram API integration  
	-  Arduino Raspberry PI Asynchronous communication  
	-  Python serial communication library  
  
  
  
  
  
----------------------------------------  

  
  
  
----  
  
  
  
----  
  
  
  
----  
  
  
  
----  
End of File.  
