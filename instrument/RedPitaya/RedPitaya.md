BLOG_GitHub_RedPitaya_20250721.txt  
  https://github.com/kwankunghkg/Robotics/blob/main/instrument/RedPitaya/RedPitaya.md  
  
  
  
----------------------------------------  
  
#### updated  
last : 2025-07-21_17:51(UTC+8)  
prev : 2025-07-21_17:51(UTC+8)  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
Red Pitaya LAN connection  
  http://rp-f00414.local/  
Red Pitaya WiFi Access Point connection  
  http://192.168.128.1/  
  
  
  
----------------------------------------  
  
  
Red Pitaya URL : http://rp-f00414.local/  
Red Pitaya URL : rp-xxxxxx.local/  
xxxxxx are the last 6 characters from MAC address of your STEMlab board. MAC address is written on the Ethernet connector.  
2.2.1. Connect to your Red Pitaya  
  https://redpitaya.readthedocs.io/en/latest/quickStart/connect/connect.html  
  
  
----------------------------------------  
  
  
red pitaya hotspot mode : access point  
red pitaya hotspot SSID : RP_xx  
red pitaya hotspot address 192.168.128.1  
red pitaya hotspot pass : rpk.R...  
  
  
  
----------------------------------------  
  
  
  
C:\Users\kwankung>arp  
Displays and modifies the IP-to-Physical address translation tables used by  
address resolution protocol (ARP).  
ARP -s inet_addr eth_addr [if_addr]  
ARP -d inet_addr [if_addr]  
ARP -a [inet_addr] [-N if_addr] [-v]  
  
C:\Users\kwankung>arp -a  
Interface: 192.168.11.38 --- 0x18  
  Internet Address      Physical Address      Type  
  192.168.11.1          00-0d-0b-64-53-84     dynamic  
  192.168.11.255        ff-ff-ff-ff-ff-ff     static  
  
  
----------------------------------------  
  
  
  
  
Red Pitaya User Manual  
  https://www.elektor.com/downloads/dl/file/id/1088/red_pitaya_user_manual.pdf  
  
  
Red Pitaya Quick-start guide  
  http://data.designspark.info/uploads/knowledge-items/a-starting-guide-for-the-red-pitaya/RP-%20The%20Guide%20v1.0.pdf  
  
  
  
1.6. Troubleshooting  
1.6.1. Problems connecting to Red Pitaya  
  http://redpitaya.readthedocs.io/en/latest/quickStart/troubleshooting/troubleshooting.html  
  
Red Pitaya Hardware Specifications V1.1.1  
  https://www.galagomarket.com/datasheet/redpitaya_hardware%20specifications.pdf  
  
Red Pitaya Data Acquisition DAQ, 8 channels  
  https://hken.rs-online.com/web/p/data-acquisition/1271091/  
STEMLab Logic Analyser User Manual  
  https://docs-apac.rs-online.com/webdocs/1578/0900766b81578196.pdf  
  
STEMLab Logic Analyser Pro  
  https://hken.rs-online.com/web/p/data-acquisition/1271092/  
  
  http://redpitaya.readthedocs.io/en/latest/appsFeatures/apps-featured/logic/logic.html  
  
  
----------------------------------------  
  
  
  
  
  
----------------------------------------  
  
  
  
RedPitaya OS 2.0 not booting on 125-14 #250  
  https://github.com/RedPitaya/RedPitaya/issues/250  
  
red_pitaya_OS-v0.97-RC9-15-jun-2017.img.zip  
  
  
----------------------------------------  
  
  
----------------------------------------  
  
  
----------------------------------------  
  
  
Red Pitaya analog front-end  
  
Red Pitaya, STEMlab 125-14, Featuring AD9767, LTC2145-14, LTC3615  
  
LTC2145 UP-14 / 14-Bit 125Msps Low Power Dual ADCs / 64-Pin (9mm × 9mm) QFN Package  
  https://www.analog.com/en/products/ltc2145-14.html#product-overview  
datasheet  
  https://www.analog.com/media/en/technical-documentation/data-sheets/21454314fa.pdf  
  
  
AD8066ARMZ Analog Devices / High Performance, 145 MHz FastFET™ Op Amp  
  https://www.analog.com/en/products/ad8066.html  
  https://www.analog.com/media/en/technical-documentation/data-sheets/AD8065_8066.pdf  
  
  
----------------------------------------  
  
  
RedPitaya ADC differential front-end QFN-16 ...  
  
// 200MHz bandwidth of the LTC6403-1 (differential amplifier placed just before the ADC pairs) //  
Bypassing front end filter  
  https://forum.redpitaya.com/viewtopic.php?t=24701  
	 When I started at the lab, I remember a colleague that also wanted to bypass the filter and he just used the provided jumper to connect the input of this stage to the output (connect pin 2 to pin 5) https://imgur.com/a/QrpiwwZ  
  
404 LDBM N309 QFN16  
404 LDBM QFN16 differential amp analog devices LTC6403  
  
LTC6403-1 - 200MHz, Low Noise, Low Power Fully Differential Input/Output Ampliﬁer/Driver  
  https://www.analog.com/en/products/ltc6403-1.html#product-overview  
datasheet  
  https://www.analog.com/media/en/technical-documentation/data-sheets/64031fb.pdf  
  
  
// LTC6403-1 or the anti-aliasing filter. Everything is hidden in the “Amplifier & Filter” box. These are the joys of “closed hardware”  //  
  
Red Pitaya - ADC driver - LTC6403-1  
  
Modifications to the Red Pitaya card in software defined radio (SDR)  
  https://wiki.electrolab.fr/Projets:Lab:2018:Red_Pitaya  
google translate website French to English  
  https://wiki-electrolab-fr.translate.goog/Projets:Lab:2018:Red_Pitaya?_x_tr_sl=fr&_x_tr_tl=en&_x_tr_hl=en&_x_tr_pto=wapp  
  
LTC6403-1 example schematic  
  https://wiki.electrolab.fr/File:ModC.gif  
  
  
  
LTC6404 - 600MHz, Low Noise, High Precision Fully Differential Input/Output Ampliﬁer/Driver  
  https://www.analog.com/en/products/ltc6404.html  
datasheet  
  https://www.analog.com/media/en/technical-documentation/data-sheets/6404f.pdf  
  
  
  
----------------------------------------  
  
  
I think I fried on of my input channels...  
  https://forum.redpitaya.com/viewtopic.php?t=386  
  
Input Stage Imperfections  
  https://forum.redpitaya.com/viewtopic.php?t=468  
  
Problem with discontinuity in Red Pitaya's input channels  
  https://forum.redpitaya.com/viewtopic.php?t=23130  
  
  
----------------------------------------  
  
  
Converting dBFS to dBm with an SDR receiver based on the LTC2145-14 clocked at 125 Mhz  
  https://ez.analog.com/data_converters/high-speed_adcs/f/q-a/112282/converting-dbfs-to-dbm-with-an-sdr-receiver-based-on-the-ltc2145-14-clocked-at-125-mhz  
  
  
----------------------------------------  
  
  
Package 16-Lead Plastic QFN (3mm × 3mm) Exposed Pad Variation AA  
  https://www.analog.com/media/en/package-pcb-resources/package/pkg_pdf/ltc-legacy-qfn/qfn_16_05-08-1700.pdf  
QUAD FLAT NO-LEAD PACKAGE  QFN16 (4x4) 2.1mm x 2.1mm  
  http://www.bdtic.com/download/ST/CD00073333.pdf  
  
  
  
  
----------------------------------------  
  
  
  
Red Pitaya, STEMlab 125-14, Featuring AD9767, LTC2145-14, LTC3615  
  
LTC2145 UP-14 / 14-Bit 125Msps Low Power Dual ADCs / 64-Pin (9mm × 9mm) QFN Package  
  https://www.analog.com/en/products/ltc2145-14.html#product-overview  
  https://www.analog.com/media/en/technical-documentation/data-sheets/21454314fa.pdf  
  
  
  
----------------------------------------  
  
  
----------------------------------------  
  
  
  
adc dual 10bit 125msps 65 pin  
  
ANALOG DEVICES AD9608BCPZ-125 / Analogue to Digital Converter, 10 bit, 125 MSPS, Differential, Single Ended, Serial, SPI, Single  
  https://ie.farnell.com/analog-devices/ad9608bcpz-125/adc-10bit-125msps-lfcsp-vq-ep/dp/4017136  
  
AD9608BCPZ-125 Dual ADC 10-Bit 125MSPS 1.8V Analog-to-Digital Converter / 64-lead frame chip scale package [LFCSP-VQ]  
  https://4donline.ihs.com/images/VipMasterIC/IC/ANDI/ANDI-S-A0001403744/ANDI-S-A0001403744-1.pdf?hkey=52A5661711E402568146F3353EA87419  
  
  
LTC2281 Dual 10-Bit, 125Msps Low Power 3V ADC  
  https://www.analog.com/media/en/technical-documentation/data-sheets/2281fb.pdf  
  
  
  
----------------------------------------  
  
  
AD8065/AD8066 Op Amps 145 MHz FastFET  
  https://www.analog.com/media/en/technical-documentation/data-sheets/AD8065_8066.pdf  
  
TXC BFBC90 125MHz / OSCILLATORS - CMOS - Tight Stability  
  https://txccrystal.com/oscillator.html  
TXC 7x5mm SMD LVDS CXO BF SERIES  
  http://txccrystal.com/images/pdf/bf.pdf  
  
  
----------------------------------------  
  
  
Phase Noise and Frequency Stability of the Red-Pitaya Internal PLL  
  
  The entire system, with the exception of the SoC processor, works at 125MHz clock provided by a local quartz oscillator (CXO BFBC90 from. TXC Corporation).  
  
  
  
----------------------------------------  
  
  
----------------------------------------  
  
  
Red Pitaya STEMLab Diagnostic Kits  
  https://www.mouser.com/new/red-pitaya/red-pitaya-diagnostic-kit/  
On-the-Board  
	Analog Devices AD8066 Operational Amplifiers are voltage feedback amplifiers with FET inputs offering high performance and ease of use. The AD8066 is a dual amplifier. These amplifiers are developed in the Analog Devices, Inc. proprietary XFCB process and allow exceptionally low noise operation (7.0nV/√Hz and 0.6 fA/√Hz) and very high input impedance.  
	Analog Devices AD8021 High-Speed Amplifiers allow for a choice of a gain bandwidth product that best suits the application. With a single capacitor, the user can compensate the AD8021 for the desired gain with little trade-off in bandwidth. The AD8021 is a well-behaved amplifier that settles to 0.01% in 23ns for a 1V step. The amplifier has a fast overload recovery of 50ns.  
	Analog Devices AD8132 Differential Amplifiers are used as a differential driver for the transmission of high-speed signals over low cost twisted pair or coaxial cables. The feedback network can be adjusted to boost the high-frequency components of the signal.  
	Analog Devices ADP5302 Battery Voltage Monitors are high efficiency, ultralow quiescent current step-down regulator that draws only 240nA quiescent current to regulate the output at no load.  
	Analog Devices AD9763 Digital-to-Analog Converters are dual-port, high speed, 2-channel, 10-/12-/14-bit CMOS DACs. Each part integrates two high-quality TxDAC+® cores, a voltage reference, and digital interface circuitry into a small 48-lead LQFP. The AD9763 offer exceptional AC and DC performance while supporting update rates of up to 125MSPS.  
	Analog Devices AD9608 Analog to Digital Converters are monolithic, dual-channel, 1.8V supply, 10-bit, 105MSPS/125MSPS analog-to-digital converters (ADC). The converters feature a high-performance sample-and-hold circuit and an on-chip voltage reference.  
	Analog Devices ADP5052 LDO Regulators combine four high-performance buck regulators and one 200mA low dropout (LDO) regulator in a 48-lead LFCSP package. The ADP5052 meet demanding performance and board space requirements. The devices enable direct connection to high input voltages up to 15V with no preregulators.  
  
  
  
  
----------------------------------------  
  
  
----------------------------------------  
  
  
  
Zynq 7000 Boards, Kits, and Modules  
  https://www.xilinx.com/products/boards-and-kits/device-family/nav-zynq-7000.html  
  
  
  
  
AMD Zynq 7000 SoC ZC702 Evaluation Kit  
  https://www.xilinx.com/products/boards-and-kits/ek-z7-zc702-g.html  
  
  
  
Enclustra FPGA Solutions / MA-ZX2-20-2I-D9-R2 / SOM ZYNQ 7Z020 512MB / 嵌入式模組 ARM Cortex-A9 Zynq-7000 (Z-7020) 512MB 64MB / hk$2,635  
  https://www.digikey.hk/zh/products/detail/enclustra-fpga-solutions/MA-ZX2-20-2I-D9-R2/13173958  
  https://www.enclustra.com/assets/scripts/downloadmanuald.php?f=Mars_ZX2_User_Manual.pdf  
  https://github.com/enclustra  
	Xilinx Zynq®-7010/7020 All Programmable SoC, CLG400 package  
	• Dual ARM® Cortex™-A9 MPCore™with CoreSight™ and NEON™ extension  
	• Xilinx Artix-7 28 nm FPGA fabric  
	• 108 user I/Os up to 3.3 V  
	• 12 ARM peripheral I/Os (SPI, SDIO, CAN, I2C, UART) shared with FPGA I/Os  
	• 96 FPGA I/Os (single-ended, differential or analog)  
	• 512 MB DDR3L SDRAM  
	• 64 MB quad SPI flash  
	• Gigabit Ethernet  
	• USB 2.0 On-The-Go (OTG)  
	• Real-time clock  
	• SO-DIMM form factor (30 × 67.6 mm, 200 pins)  
	• The module can be operated using a single 3.3 V supply voltage  
  
  
  
微相 Xilinx FPGA ZYNQ 核心板 XC7Z010 XC7Z020 工业级 XME0724 / MicroPhase旗舰店 上海 / 20231230 ¥899  
  https://detail.tmall.com/item.htm?id=687950452082  
颜色分类：  
	XME0724-10C  
	XME0724-10C专票  
	XME0724-10C专票带下载器  
	XME0724-10I  
	XME0724-10I专票  
	XME0724-10I专票带下载器  
	XME0724-20I  
	XME0724-20I专票  
	XME0724-20I专票带下载器  
  
  
  
璞致FPGA XILINX ZYNQ核心板ZYNQ7000 7010 7020 XC7Z010 XC7Z020 /  璞致电子科技  上海 / 20231230  /  ¥759-1411 约 HKD 837-1556  
  https://item.taobao.com/item.htm?id=605524247374  
  
  
  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
End of File.  
