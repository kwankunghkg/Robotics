  
BLOG_GitHub_Repair_Power_SMPS_20240312.txt  
  https://github.com/kwankunghkg/Robotics/blob/main/Repair/Electrical/Power/SMPS/README.md  
  
last update : 20240312_0352(UTC+8)  
prev update : 20240312_0316(UTC+8)  
  
--------------------------------------------------  
  
## Repair - Power_SMPS  
  
--------------------------------------------------  
  
  
  
--------------------------------------------------  
  
LNK364PN datasheet (PDF)  
  https://www.mouser.com/datasheet/2/328/lnk362-364-1511784.pdf  
  
  
{493} LNK564PN, How To Test LNK562, LNK563, LNK564PN IC Functional Test / Haseeb Electronics / Nov 10, 2021  
https://youtu.be/k2rmeKlWyrY  
117K subscribers  7,980 views  
  
  
{491} LNK564PN, Datasheet, Application Circuit Diagram, Equivalent, for LNK562, LNK563 & LNK564 / Haseeb Electronics / Nov 8, 2021  
  https://youtu.be/2H-f2gd38ws  
117K subscribers  21,298 views  
	in this video i discussed LNK564PN, Datasheet, Application Circuit Diagram, Equivalent, for LNK562, LNK563 & LNK564. it is LNK564, LNK564PN, LNK564PG, we can find datasheet, pinout, sample circuit, application note, circuit diagram from the manufacturer as well. i explained the lnk564pn circuit diagram and how to repair and troubleshoot smps switch mode power supply, how to design smps high frequency transformer using ee16 ferrite gapped core 
	it is Lowest component count switcher, Very tight parameter tolerances using proprietary IC trimming technology and transformer construction techniques enable Clampless™designs – decreases component count/system cost and increases efficiency  
	Frequency jittering greatly reduces EMI – enables low cost input filter configuration  
	LinkSwitch-LP switcher ICs cost effectively replace all unregulated isolated linear transformer based (50/60 Hz) power supplies up to 3 W output power. For worldwide operation, a single universal input design replaces multiple linear transformer based designs. The self-biased circuit achieves an extremely low no-load consumption of under 150 mW. The internal oscillator  
	Output power may be limited by specifi c application parameters including core size and Clampless operation 
	Minimum continuous power in a typical non-ventilated enclosed adapter measured at 50 °C ambient. 
	Minimum practical continuous power in an open frame design with adequate  
	heat sinking, measured at 50 °C ambient. 
	Packages: P: DIP-8B, G: SMD-8B. For lead-free package options, see Part Ordering Information.  
  
  
  
  
--------------------------------------------------  
  
----------------------------------------  
  
SMPS  
  
SMPS circuit  
  
  
  https://electronics.stackexchange.com/questions/387855/smps-circuit-components-need-some-explaination  
  
  
Switched-Mode Power Supply (SMPS) Circuit Working Explanation 
  https://www.electrothinks.com/2020/10/Switched-mode-power-supply-smps-circuit-working-explanation.html#google_vignette  
  
  
  
  https://theorycircuit.com/simple-smps-circuit/  
  
TNY267 TinySwitch-II family IC from Power Integrations  
TNY263-268 TinySwitch-II Family / Enhanced, Energy Efficient, Low Power Off-line Switcher  
  https://www.mouser.com/datasheet/2/328/tny263_268-1512708.pdf  
  
EL817 - Optocoupler 
  
  https://en.wikipedia.org/wiki/Galvanic_isolation  
  https://en.wikipedia.org/wiki/Opto-isolator  
  
  
TL431 precision reference IC  
  https://en.wikipedia.org/wiki/TL431  
	The TL431 integrated circuit (IC) is a three-terminal adjustable precise shunt voltage regulator. With the use of an external voltage divider, a TL431 can regulate voltages ranging from 2.495 to 36 V, at currents up 100 mA.  
  
  
  
  
  
----------------------------------------  
  
What is X1 Y1 capacitor ?  
  
Safety Capacitors First: Class-X and Class-Y Capacitors 
  https://www.allaboutcircuits.com/technical-articles/safety-capacitor-class-x-and-class-y-capacitors/  
	So for an X1/Y1 combination, this simply means that the capacitor can be used either as an X1 capacitor in a line-to-line application or as a Y1 capacitor in a line-to-ground application. Examples include the following: Vishay (PDF) offers their VY2 Class X1 (440 VAC) / Class Y2 (300 VAC) capacitor.  
  
  
class Y1 safety capacitor  
  
	Y1 class capacitors are rated up to 500VAC, with a peak test voltage of 8kV. Y2 capacitors have 150 to 300VAC ratings and a peak test voltage of 5kV. Y3 capacitors are rated to 250VAC with no peak test voltage specified.  
	  
	The difference between Y1 and Y2 capacitors is the maximum isolation voltage of the component. Y2 capacitors can be used for barriers with up to 1500VAC test voltage, Y1 rated capacitors can be used for barriers up to 3000VAC test voltage.  
  
  
  
  
Vishay AY2 Series AC Rated Safety Capacitors | Tech Specs 
  https://www.allaboutcircuits.com/new-industry-products/vishay-ay2-series-ac-rated-safety-capacitors-tech-specs/  
Vishay AY2 Series AC Rated Safety Capacitors | Tech Specs / All About Circuits /  Jun 14, 2018  
https://youtu.be/cPsF0RbHhu0  
36.6K subscribers / 605 views  // 
  
  
  
  
***** How to use Safety Capacitors - What are they? / Kiss Analog /  May 8, 2020  
https://youtu.be/fQSlo1zmAlA  
27.3K subscribers / 22,956 views  // 
	This video is about Safety Capacitors and how to use them and what they are.  I'll talk about the difference of an X and Y capacitor.  There are X1, X2, and Y1, and Y2 capacitors sometimes referred to as RFI capacitors.  
	https://www.spectrum-soft.com/downloa...  
	Micro-Cap Tutorial #4:  • Micro-Cap Tutorial #4: Adding a new P...  
	Micro-Cap Tutorial #3:  • Micro-Cap Tutorial #3: Boost Converter  
	Micro-Cap Tutorial #2:  • Micro-Cap Tutorial #2: Vacuum Tube Am...  
	Micro-Cap Tutorial #1: Tube Amplifier  • Micro-Cap Tutorial #1: Tube Amplifier  
	Micro-Cap SPICE Simulation is now Free  • Micro-Cap SPICE Simulation is now Free  
	Boost Converter  Introduction  • Boost Converter  Introduction  
  
  
  
Dealing with the DEATH CAPACITOR in Vintage Gear / Blueglow Electronics /  Mar 19, 2019  
https://youtu.be/Q0jM05sxy28  
48.6K subscribers / 146,614 views  // 
	BG237 - A lot of mystery out there around what a "DEATH CAPACITOR" is, why they were used and how to replace them.  I did my best to explain all of this and remove some of the mystery surrounding.  This applies to guitar, stereo, Hi-Fi, Ham Radio, Test Equipment, and other vintage tube electronics and amplifiers.  
	A link to the X1/Y2 safety caps that I use:  
	https://www.mouser.com/ProductDetail/...  
  
  
  
  
  
----------------------------------------  
  
japan voltage reason  
  
	Japan is connected to a 100-volt current and uses two frequencies. Those are 50 Hz in Kansai and in the east of the country, and 60 Hz in Kanto and in the north. It originates from the fact that eastern Japan imported German power generators during the Meiji period while the west imported them from the USA.  
  
  https://en.wikipedia.org/wiki/Electricity_sector_in_Japan  
	This originates from the first purchases of generators from AEG for Tokyo in 1895 and from General Electric for Osaka in 1896. This frequency difference partitions Japan's national grid, so that power can only be moved between the two parts of the grid using frequency converters, or HVDC transmission lines.  
  
  
  
  
  
----------------------------------------  
  
Digital Multimeter Safety and CAT ratings / Kiss Analog /  Nov 20, 2019  CAT Ratings  
https://youtu.be/efw-myo52NQ  
27.3K subscribers / 4,081 views  // 
	This video is about Digital Multimeter Safety.  I explain what the CAT ratings are and what they mean to the digital multimeter.  Why an inexpensive digital multimeter might be just as safe as a Fluke digital multimeter.  
	AMAZON 90DM150 multimeter (nice lower cost): https://amzn.to/2WzphpD  
	Greenlee DM820A multimeter: https://amzn.to/2WHdjKV  
	https://content.fluke.com/promotions/...  
  
  
Multimeter Safety Tutorial / Kiss Analog /  Mar 23, 2020  CAT Ratings  
https://youtu.be/75nwp0iY9BY  
27.3K subscribers / 1,627 views  // 
	Sorry - I tried uploading 3 times and the 3rd time it reported a good upload, but the video freezes at about 12:40 min, so there is a part 2 and part 3 - hoping that the shorter videos will upload without issue.  
	This video is a Multimeter Safety Tutorial.  I explain what the CAT ratings are and what they mean to the digital multimeter.  Why an inexpensive digital multimeter might be just as safe as a Fluke digital multimeter for the right applications.  
	AMAZON 90DM150 multimeter (nice lower cost): https://amzn.to/2WzphpD  
	Greenlee DM820A multimeter: https://amzn.to/2WHdjKV  
	Multimeter Safety CAT ratings:  • Digital Multimeter Safety and CAT rat...  
	https://content.fluke.com/promotions/...  
  
  
Probe Master vs Competitor Multimeter Test Leads / Kiss Analog /  Nov 7, 2020  #silicone #best  
https://youtu.be/i4IvB90jZxs  
27.3K subscribers / 24,446 views  // 
	This video is about Probe Master vs Competitor Test Leads for your multimeter.  How to find your best Multimeter Test leads.  I will open 9 new probe kits including Probe Master, Fluke TL175E TwistGuard, Micosa, Handskit, Kaiweets, Wgge, Liumy and Sumnacon.  I purchased these to show the comparison to Probe Master multimeter probes and I'll show some used probes to illustrate the wear that might be expected. #best test leads, #silicone test leads  
  
  
  
  
How do you test a MOV varistor with a multimeter?  
	In this type of test, the varistor is placed in a circuit and the resistance or voltage is measured across it. This can be done using a digital multimeter. The results of the test can then be used to help determine the varistor's characteristics, such as its clamping voltage and rated current.  
  
Varistor Testing  
  https://eepower.com/forums/threads/varistor-testing.503/#  
  
  
“Scientists study the world as it is; engineers create the world that has never been.” - Theodore von Karman  
  
  
  
.  
  
  
  
  
  
  
  
  
  
  
----------------------------------------  
  
  
switching mode power supply c14 621-4 dip-4  
  
  
  
----------------------------------------  
  
  
LNK364PN datasheet (PDF)  
  https://www.mouser.com/datasheet/2/328/lnk362-364-1511784.pdf  
  
  
{493} LNK564PN, How To Test LNK562, LNK563, LNK564PN IC Functional Test / Haseeb Electronics / Nov 10, 2021  
  https://youtu.be/k2rmeKlWyrY  
117K subscribers  7,980 views  
	in this video i demonstrated LNK564PN, How To Test LNK562, LNK563, LNK564PN IC functional Test  
	discussed LNK564PN, Datasheet, Application Circuit Diagram, Equivalent, for LNK562, LNK563 & LNK564. it is LNK564, LNK564PN, LNK564PG, we can find datasheet, pinout, sample circuit, application note, circuit diagram from the manufacturer as well. i explained the lnk564pn circuit diagram and how to repair and troubleshoot smps switch mode power supply, how to design smps high frequency transformer using ee16 ferrite gapped core 
	it is Lowest component count switcher, Very tight parameter tolerances using proprietary IC trimming technology and transformer construction techniques enable Clampless™designs – decreases component count/system cost and increases efficiency  
	Frequency jittering greatly reduces EMI – enables low cost input filter configuration  
	LinkSwitch-LP switcher ICs cost effectively replace all unregulated isolated linear transformer based (50/60 Hz) power supplies up to 3 W output power. For worldwide operation, a single universal input design replaces multiple linear transformer based designs. The self-biased circuit achieves an extremely low no-load consumption of under 150 mW. The internal oscillator  
	Output power may be limited by specifi c application parameters including core size and Clampless operation 
	Minimum continuous power in a typical non-ventilated enclosed adapter measured at 50 °C ambient. 
	Minimum practical continuous power in an open frame design with adequate  
	heat sinking, measured at 50 °C ambient. 
	Packages: P: DIP-8B, G: SMD-8B. For lead-free package options, see Part Ordering Information.  
  
  
{491} LNK564PN, Datasheet, Application Circuit Diagram, Equivalent, for LNK562, LNK563 & LNK564 / Haseeb Electronics / Nov 8, 2021  
  https://youtu.be/2H-f2gd38ws  
117K subscribers  21,298 views  
	in this video i discussed LNK564PN, Datasheet, Application Circuit Diagram, Equivalent, for LNK562, LNK563 & LNK564. it is LNK564, LNK564PN, LNK564PG, we can find datasheet, pinout, sample circuit, application note, circuit diagram from the manufacturer as well. i explained the lnk564pn circuit diagram and how to repair and troubleshoot smps switch mode power supply, how to design smps high frequency transformer using ee16 ferrite gapped core 
	it is Lowest component count switcher, Very tight parameter tolerances using proprietary IC trimming technology and transformer construction techniques enable Clampless™designs – decreases component count/system cost and increases efficiency  
	Frequency jittering greatly reduces EMI – enables low cost input filter configuration  
	LinkSwitch-LP switcher ICs cost effectively replace all unregulated isolated linear transformer based (50/60 Hz) power supplies up to 3 W output power. For worldwide operation, a single universal input design replaces multiple linear transformer based designs. The self-biased circuit achieves an extremely low no-load consumption of under 150 mW. The internal oscillator  
	Output power may be limited by specifi c application parameters including core size and Clampless operation 
	Minimum continuous power in a typical non-ventilated enclosed adapter measured at 50 °C ambient. 
	Minimum practical continuous power in an open frame design with adequate  
	heat sinking, measured at 50 °C ambient. 
	Packages: P: DIP-8B, G: SMD-8B. For lead-free package options, see Part Ordering Information.  
  
  
  
  
  
  
  
----------------------------------------  
  
  
----------------------------------------  
  
SMPS / 220V AC input / 12V 2A 5V 2A DC output  
  
TO-220 2N60C datasheet pdf  
  
FQP2N60C / FQPF2N60C / N-Channel QFET® MOSFET / 600 V, 2 A, 4.7 Ω  
  https://www.farnell.com/datasheets/1785349.pdf  
  
  
  
600v npn transistor  
600v npn transistor to-92  
  
MJE13001 General Transistor Npn 600V 0.2A TO-92 
MJE13002 in-line triode transistor TO-92 1.2A 400V NPN  
  
MPSA44 DIOTEC SEMICONDUCTOR ; Type of transistor. NPN ; Polarisation. bipolar ; Collector-emitter voltage. 400V ; Collector current. 0.3A ; Power dissipation. 0.625W.  
  
MULTICOMP PRO MPSA44 Bipolar (BJT) Single Transistor, NPN, 400 V, 300 mA, 625 mW, TO-92, Through Hole  
  https://hk.element14.com/multicomp/mpsa44/transistor-npn-to-92/dp/1574391  
  
  
  
----------------------------------------  
  
SMPS / 220V AC input / 5V DC output  
  
  
220v circuit 13001(NPN) c94(PNP) S9015(PNP) 
power supply circuit 13001(NPN) MPSA94(PNP) 
  
MJE13001-P NPN SILICON POWER TRANSISTOR  
www.unisonic.com.tw  Unisonic Technologies Co., Ltd QW-R201-088,A  
	* Collector-base voltage: V (BR)CBO =600V  
	* Collector current: I C=0.2A  
  
  
  
PNP Transistor KSP94 = MPSA94 TO-92 Vceo=-400V Ic=-300mA Pd=625mW Fairchild  
  
KSP94 PNP Epitaxial Silicon Transistor / Fairchild Semiconductor (onsemi) / 1. Emitter 2. Base 3. Collector  
  https://www.mouser.com/datasheet/2/149/KSP94-889491.pdf  
  https://www.sm0vpo.com/_pdf/KS/KSP94.pdf  
	Complement to KSP44  
  
MPSA94 PNP SILICON PLANAR HIGH VOLTAGE TRANSISTOR  
  https://www.mouser.com/datasheet/2/115/mpsa94-1164748.pdf  
  https://www.unisonic.com.tw/uploadfiles/836/part_no_pdf/MPSA94.pdf  
  https://ftp01.cystekec.com/MPSA94.pdf  
	Complementary to MPSA44  
  
MPSA44 NPN SILICON PLANAR HIGH VOLTAGE TRANSISTOR  
  https://www.diodes.com/assets/Datasheets/products_inactive_data/mpsa44.pdf  
  https://www.nxp.com/docs/en/data-sheet/MPSA44.pdf  
  
  
Variable Voltage, Current Power Supply Circuit Using Transistor 2N3055  
  https://www.homemade-circuits.com/how-to-make-versatile-variable-voltage/  
  
  https://www.homemade-circuits.com/50v-adjustable-transformerless-power/  
  
  
4 Simple Transformerless Power Supply Circuits Explained  
  https://www.homemade-circuits.com/cheap-yet-useful-transformerless-power/  
  
  
  
  
----------------------------------------  
  
Efficient Switch Mode Power Supply 1.5-12V 5A / ElectroBUFF /  Mar 10, 2019  
https://youtu.be/ZxNoG_-ks9A  
27.4K subscribers / 1,899 views  // 
	Hey guys, and welcome all to my channel. Today I'll show you how to make an efficient switch mode power supply without using any IC. The output can be tailored to be completely adjustable from 1.5-12V, and the Current is rated for 5A which of course can be upgraded by using more powerful Mosfets. 
  
  
  
BC547 NPN V(CBO)=50V V(CEO)=45V V(BEO)=6V hFE=110-800 I(C)=100mA  
Switching and Applications  
  https://www.sparkfun.com/datasheets/Components/BC546.pdf  
  
Difference Between BC547 Transistor vs 2N2222 Transistor? 
  https://community.ibm.com/community/user/ai-datascience/discussion/what-is-the-difference-between-bc547-transistor-vs-2n2222-transistor  
BC547 Equivalents  
	The BC series, such as BC549 and BC639, are the finest recommendations for the BC547 transistor equivalent, followed by the 2N2222 transistor. BC636 replaces BC547, 2N2369, 2N3055, 2N3904, 2N3906, and 2SC5200 in the PNP.  
  
  
2N3904 NPN V(CBO)=60V V(CEO)=40V V(BEO)=6V hFE=60-200 I(C)=200mA  
  https://cpc.farnell.com/on-semiconductor/2n3904/transistor-npn-to-92/dp/SC10960  
  https://www.farnell.com/datasheets/2298261.pdf  
  
  
SS9013 NPN V(CBO)=40V V(CEO)=20V V(BEO)=5V hFE=60-200 
1W Output Amplifier of Potable Radios in Class B Push-pull Operation.  
  https://www.mouser.com/datasheet/2/149/SS9013-1012678.pdf  
  
  
S8050 NPN V(CBO)=40V V(CEO)=25V V(BEO)=5V hFE=85-400 
  https://www.jscj-elec.com/gallery/file/S8050%20TO-92%20V1.pdf  
  
  
插件三极管2N5401 5551 3904 3906 4401 4403功率晶体管TO92 / 深圳市讯华微电子有限公司 广东深圳 / ¥1.7起 约 HKD 1.86起  
  https://item.taobao.com/item.htm?id=592576848028  
颜色分类：  
	2N5551 插件 NPN（50只）,  
	2N5401 插件 PNP（50只）,  
	2N3904 插件 NPN（50只）,  
	2N3906 插件 PNP（50只）,  
	2N4401 插件 NPN（50只）,  
	2N4403 插件 PNP（50只）  
  
直插贴片三极管S8050/S8550/S9012/S9014/2N5551/5401/3906/3904 / 电子爱好者之家元器件 电子元器件套件元件 广东深圳 / ¥1.8起 约 HKD 1.97起  
  https://item.taobao.com/item.htm?id=4259039763  
颜色分类：  
	(50个)直插S8050 NPN 0.5A/40V,  
	(50个)直插S8550 PNP 0.5A/40V,  
	(50个)直插SS8050 NPN 1.5A/40V,  
	(50个)直插SS8550 PNP 1.5A/40V,  
	(50个)直插S9012 PNP 0.5A/40V,  
	(50个)直插S9013 NPN 0.5A/40V,  
	(50个)直插S9014 NPN 0.1A/50V,  
	(50个)直插2N5551 NPN 0.6A/180V,  
	(50个)直插2N5401 PNP 0.6A/180V,  
	(50个)直插2N3904 NPN 0.2A/60V,  
	(50个)直插2N3906 PNP 0.2A/50V,  
	(50个)2SA1015 PNP 0.15A/50V,  
	(50个)2SC1815 PNP 0.15A/50V,  
	(50个)贴片S8050 NPN 0.5A/40V,  
	(50个)贴片S8550 PNP 0.5A/40V,  
	(50个)贴片SS8050 NPN 1.5A/40V,  
	(50个)贴片SS8550 PNP 1.5A/40V,  
	(50个)贴片S9012 PNP 0.5A/40V,  
	(50个)贴片S9013 NPN 0.5A/40V,  
	(50个)贴片S9014 NPN 0.1A/50V,  
	(50个)贴片2N5551 NPN 0.6A/180V,  
	(50个)贴片2N5401 PNP 0.6A/160V,  
	(50个)贴片2N3904 NPN 0.2A/60V,  
	(50个)贴片2N3906 PNP 0.2A/40V  
  
  
常用24种480个三极管盒装直插to-92晶体管npn/PnP小功率维修元件 / 昊轩电子元件 广东深圳 / ¥25 约 HKD 27.32  
  https://item.taobao.com/item.htm?id=771239734732  
颜色分类：24种480个三极管盒装  
  
  
7种1500个二极管三极管电阻电容常用元件混装实验维修DIY常备套件 / 昊轩电子元件 广东深圳 / ¥44 约 HKD 48.07  
  https://item.taobao.com/item.htm?id=771779302677  
  
  
SS8550/8050 2N3904/2222/3906 MPS2222A 2SA1015 BC547直插TO-92 / 酷米仕科技官方店 广东深圳 / ¥0.23起 约 HKD 0.25起  
  https://item.taobao.com/item.htm?id=556359081370  
颜色分类：  
	2SA1015 TO-92 (100只) 国芯,大批量更优惠联系客服,  
	MPS2222A TO-92(100只)国芯,  
	SS8550 TO-92(100只)国芯,  
	SS8050 TO-92(100只)国芯,  
	2N3904 TO-92(10只)国芯,  
	BC547 TO-92(10只)国芯,  
	2N2222 TO-92(100只)国芯,  
	2N3906 TO-92(10只)国芯  
  
  
2N2222A 2N3904 2N3906 2N4403 2N5551 2N5401 TO92 直插三极管 / 特加特数码专营店 广东深圳 / ¥2.03起 约 HKD 2.22起  
  https://detail.tmall.com/item.htm?id=618129999745  
颜色分类：  
	2N5401A 直插三极管 封装TO-92(30个) 
	2N2222A 直插三极管 封装TO-92(30个) 
	2N2907A 直插三极管 封装TO-92(30个) 
	2N3904 直插三极管 封装TO-92（30个） 
	2N3906 直插三极管 封装TO-92(30个) 
	2N4401 直插三极管 封装TO-92(30个) 
	2N4403 直插三极管 封装TO-92(30个) 
	2N5401B 直插三极管 封装TO-92(30个) 
	2N5551A 直插三极管 封装TO-92(30个)  
  
  
  
----------------------------------------  
  
  
  
----  
  
DC-DC Boost Converters / ElectroBUFF  
28 videos 7,454 views Last updated on Jun 23, 2023  
  https://www.youtube.com/playlist?list=PLoR9wyeLoQOSjK6AVbreKK2AGjvH6pC5T  
  
  
How a Switching Power Supply Works and How to Make One / ElectroBUFF /  Jan 31, 2020  DC-DC Boost Converters  
https://youtu.be/ldz6DXbNho8  
27.4K subscribers / 98,115 views  // 
	Circuit Link:  
	https://electrobuff.blogspot.com/2024/02/how-switching-power-supply-works-with.html  
	In today's video I'll be showing you how to make a Switching Power Supply with a detailed description about the working of a practical Circuit. It's a simple yet very capable Self-Oscillating Flyback Switch Mode Power Supply which has a Regulated output of 12Volts and a Current capacity of up to 10Amps.  
  
  
How a DC-DC Buck Converter Works and formulas / ElectroBUFF /  Dec 2, 2017  DC-DC converters  
https://youtu.be/28_8BXs0icI  
27.4K subscribers / 3,010 views  // 
	This tutorial explains how a dc-dc buck converter works and simple voltage, current and inductor calculations formulas.  
  
  
How a DC-DC boost converter works + Voltage formulae / ElectroBUFF /  Dec 2, 2017  DC-DC converters  
https://youtu.be/tVbGylEJxkg  
27.4K subscribers / 782 views  // 
	This simple tutorial expounds on the operation of a DC-DC boost converter for powering small to medium loads. In the last bit, a simple complete circuit is provided and discussed.  
  
  
How a Joule Thief works | SciencePlanations / ElectroBUFF /  Dec 2, 2017  DC-DC converters  
https://youtu.be/2lRvAcnXrZk  
27.4K subscribers / 716 views  // 
	This simple tutorial explains the working of a joule thief circuit that can be used to power devices which operate at a higher voltage than the battery powering them can deliver.  
  
  
Simple selfswitching 12Volt power supply 220 VAC to 12 VDC / ElectroBUFF /  Dec 15, 2017  
https://youtu.be/QXrePRWNjRU  
27.4K subscribers / 460 views  // 
	this video depicts a very simple switching power supply with a low component count that can be assembled easily. with the given winding specifications, the output will be about 12 volts, however, feel free to modify the number of secondary turns to obtain the desired voltage. please like and share the video and don't forget to subscribe to my channel. cheers.  
  
  
Tutorial: Switched Mode Power Supplies Explained / ElectroBUFF /  Nov 17, 2018  
https://youtu.be/gk_wClKk5Iw  
27.4K subscribers / 336 views  // 
	how smps work  
  
  
+++++ +++++ +++++ +++++ +++++ 
  
***** ***** {528} How To Repair SMPS || SMPS Repair Step By Step || Switch Mode Power Supply / Haseeb Electronics /  Jan 2, 2022  HASEEB ELECTRONICS  
https://youtu.be/OwmN-N8kgHw  
117K subscribers / 308,983 views  // 
rectifier cut mark => +ve  
  https://youtu.be/OwmN-N8kgHw?t=698  
NTC 5D11 5D9 10D11  
  https://youtu.be/OwmN-N8kgHw?t=700  
coil RCD circuit  
  https://youtu.be/OwmN-N8kgHw?t=1700  
FET in series with Current Sensing Resistor 0.xx ohm 
  https://youtu.be/OwmN-N8kgHw?t=1820  
switching IC  
  https://youtu.be/OwmN-N8kgHw?t=1960  
	How To Repair SMPS || SMPS Repair Step By Step || Switch Mode Power Supply .  because a smps circuit is electronic components based power converter, which takes line voltage, then converts it into dc voltage. afterwards these DC voltage are chopped in high frequency based pulse width modulation PWM based IC and the power mosfet, which are passed through a power transformer, after transformer, it will rectified into dc voltage. a feedback circuit is incorporated to maintain the voltage regulation. some circuits have a current limiting / current regulation circuit. 
	#howto  #repair #smps 
	this video is  DEDICATED TO MANSOUR MASHAQBEH Al-Zarqa Jordan منصور  المشاقبہ۔  
	Download UC3842 SMPS circuit diagram https://bit.ly/3uc8wB0  
	https://bit.ly/3a3KukQ  
	https://bit.ly/3NwZqFA  
	BOM https://bit.ly/3OiSTjJ  
	in this tutorial i shared very easy & step by step practical troubleshooting / circuit tracing and fault finding techniques to find the faults in any switching mode power supply. i explained basics of smps working and understanding repair switching mode power supply. also i discussed smps basics. after watching this video you can capable to:-  
	how to repair smps (switch /switching mode power supply), either it is industrial power supply, laptop charger, adapter, computer atx power supply, server power supply, mobile charger, battery charger, inverter ac board, inverter of solar system, inverter welding machine, led / lcd tv power supply, UPS uninterruptible power supply, washing machine control board, sewing machine circuit board, power supply of dth / digital satellite receiver, switching mode regulator, 
	how to repair smps (switch / switching mode power supplies), very easy, step by step repair and practical troubleshooting & circuit tracing tutorial using smps circuit diagram & block diagram. i discussed how to test smps switching frequency, how PWM pulse width modulator work, what is filter and protection circuit,  bridge rectifier circuit & how bridge rectifier circuit work. what is PWM pulse width modulator, how to test pwm signal. what is optocoupler or opto-isolator and what is its function in feedback circuit. what is voltage regulation and how it works in SMPS. switching mode power supply repair  tutorial, 
	how to repair / fix switch mode power supply / supplies. dead laptop charger repairing, 
	electrical engineering,  basic working of SMPS, basic working concept of SMPS switch / switching mode power supply, how switching mode power supply works, function of FET, MOSFET, BJT, IGBT or switching modules, how switching mode power supply works, most common faults in SMPS. smps output voltage fluctuation, SMPS is fluctuating output or output voltage unregulated , switch mode power supply have no output. smps input short circuit, fuse keeps blowing, smps startup circuit, smps switching frequency testing, rcd snubber circuit, secondary side, feedback circuit, TL431 adjustable reference, optocoupler, auxiliary voltage, vcc or bias voltage, current sense circuit, output fluctuation, voltage regulation. it is uc3842 / uc3843 / uc3844 / uc3845 current mode smps circuit. fuse keeps blowing. current sense in smps & short circuit protection, smps short circuit in output,  SMPS dead or no output voltage or have low output voltage. smps ic have no switching frequency,  smps no output voltage, how to troubleshoot PWM SMPS  controller when there is no switching from MOSFET. if SMPS have a whistle sound or excessive noise or excessive heat, how to repair smps in cpu, 
	this video is translated in french, spanish, italian, telugu, hindi, bengali, portuguese, how to repair smps malayalam, tamil  
  
  
{772} How To Repair SMPS Step By Step / Haseeb Electronics /  Premiered Nov 16, 2022  HASEEB ELECTRONICS  
https://youtu.be/G4hSbwk1czY  
117K subscribers / 59,871 views  // 
	in this video number {772} i explained and demonstrated How To Repair SMPS Step By Step. How To Repair SMPS || SMPS Repair Step By Step || Switch Mode Power Supply . it is UC1842, UC2842, UC3842,  UC1843, UC2843, UC3843, UC1844, UC2844, UC3844, UC1845, UC2845, UC3845, based current mode controller switch mode power supply circuit. these ics are most commonly used in battery charger, power supply circuits, laptop charger adapters and tv power supplies. i demonstrated how to troubleshoot using multimeter and oscilloscope.  because a smps circuit is electronic components based power converter, which takes line voltage, then converts it into dc voltage. afterwards these DC voltage are chopped in high frequency based pulse width modulation PWM based IC and the power mosfet, which are passed through a power transformer, after transformer, it will rectified into dc voltage. a feedback circuit is incorporated to maintain the voltage regulation. some circuits have a current limiting / current regulation circuit. 
	#howto  #repair #smps 
	Download UC3842 SMPS circuit diagram  
	http://bit.ly/3V6gYNk  
	https://bit.ly/3uc8wB0  
	https://bit.ly/3a3KukQ  
	https://bit.ly/3NwZqFA  
	BOM https://bit.ly/3OiSTjJ  
	i shared very easy & step by step practical troubleshooting, circuit tracing and fault finding techniques to find the faults in any switching mode power supply. i explained basics of smps working and understanding repair smps.  how to repair smps (switch /switching mode power supply) either it is industrial power supply, laptop charger, adapter, computer atx power supply, server power supply, mobile charger, battery charger, inverter ac board, inverter of solar system, inverter welding machine, led / lcd tv power supply, UPS uninterruptible power supply, washing machine control board, sewing machine circuit board, power supply of dth / digital satellite receiver, switching mode regulator,  
	step by step repair & practical troubleshooting & circuit tracing tutorial using smps circuit diagram & block diagram. how to test smps switching frequency, what is PWM pulse width modulator, how to test pwm signal. what is optocoupler or opto-isolator and its function in feedback circuit. how to repair / fix switch mode power supply / supplies. basic working of SMPS, basic working concept of SMPS switch / switching mode power supply, how switching mode power supply works, most common faults in SMPS. smps output voltage fluctuation, SMPS is fluctuating output or output voltage unregulated , switch mode power supply have no output. smps input short circuit, fuse keeps blowing, smps startup circuit, smps switching frequency testing, rcd snubber circuit, secondary side, feedback circuit, TL431 adjustable reference, optocoupler, auxiliary voltage, vcc or bias voltage, current sense circuit, output fluctuation, voltage regulation. fuse keeps blowing.  smps short circuit in output,  SMPS dead or no output voltage or have low output voltage. smps ic have no switching frequency,  smps no output voltage, how to troubleshoot PWM SMPS  controller when there is no switching from MOSFET  
	00:00 How to repair UC384x KA384x SMPS controller based Power SUpply CIrcuit step by step  
	01:42 how to download circuit diagram of any SMPS power supply circuit 
	02:45 3842 smps circuit explained and how to trace the circuit 
	03:41 Inrush current protection NTC circuit  
	05:42 fuse keeps blowing in smps, input short circuit  
	08:07 how to perform cold testing for power supply circuit 
	08:16 how to find short circuit in smps input circuit 
	09:36 How to Test NTC negative Temperature Coefficient resistor  
	13:58 UC384x Startup circuit explained  
	15:04 How to Test SMPS Controller IC  
	15:43 how to test MOSFET gate drive signal using multimeter and oscilloscope  
	21:06 how to check capacitor charging discharging  
	25:46 How to Measure switching frequency of uc 384x PWM ic  
	33:13 SMPS output have very low output voltage  
  
  
{775} LCD TV Power Supply No Power ON, Not Turning ON / Haseeb Electronics /  Nov 22, 2022  HASEEB ELECTRONICS  
https://youtu.be/ia7UOY2LBZg  
117K subscribers / 36,831 views  // 
	in this video number {775} i demonstrated how to repair LCD TV Power Supply No Power ON, SMPS Is Not Working || SMPS Not Turning ON. this power supply board AY250P-4HF01 or AY250P-4HF02 or 3BS0028914, SUNNY TV,  SN040LI181-T1FM MODEL LCD TV 40" POWER BOARD, for model, SUNNY SN040LI181-T1FM, SUNNY , AXEN , WOON,  ZD-95(G)F , AXEN LCD power board,  Tablero de energía del LCD AY250P-4HF01 3BS0028914  
	You are Invited to Join Haseeb Electronics  
	 / @haseebelectronics  
	#howtorepair  #lcdtv #powersupply 
	LCD TV Power Supply No Power ON, SMPS Is Not Working, SMPS Not Turning ON, lcd tv not turning on, smps is not working how will you check, how to check smps is working or not, smps, how to repair smps, how to repair, switch mode power supply, haseeb electronics, switch mode power supply tutorial, switching mode regulator, switching mode power supply, very easy repair of smps, switching power supply repair, smps no output voltage, lcd tv smps repair, lcd tv power supply repair, smps not turning on, how to know if smps is not working, how to repair switch mode power supply, switching mode power supply tutorial, how to repair switching mode power supply, smps tutorial, how to repair switch mode power supplies, how smps work, how switching mode power supply works, power supply, smps repair, smps repair step by step, basic working of switching mode power supply  
	00:00 AY250P-4HF01, 3BS0028914 LCD power Supply board not powering on 
	00:36 how to power up power supply circuit for bench test  
	01:40 how to troubleshoot lcd tv power supply circuit  
  
  
+++++ +++++ +++++ +++++ +++++ 
  
#711 Basics: Power Supply (part 1 of 5) / IMSAI Guy /  Feb 20, 2021  
https://youtu.be/ndDZVUKL30E  
101K subscribers / 37,265 views  // 
	Episode 711  
	Back to basics: Power Supply  
	AC to DC conversion, bridge rectifier  
  
#712 Basics: Power Supply (part 2 of 5) / IMSAI Guy /  Feb 21, 2021  
https://youtu.be/Kui4HRGizUw  
101K subscribers / 13,568 views  // 
	Episode 712  
	Back to basics: Power Supply  
	AC to DC conversion, -5V supply 
  
  
  
#772 Basics: Switching Power Supplies (part 1 of 2) / IMSAI Guy /  Apr 22, 2021  
https://youtu.be/9bFVTa8FEM4  
101K subscribers / 380,726 views  // 
	Episode 772  
	Let's look at a switch mode power supply. Reverse engineer and draw schematic. Then look at the design. A basic introduction to switching supplies. 
  
  
#773 Basics: Switching Power Supplies (part 2 of 2) / IMSAI Guy /  Apr 23, 2021  
https://youtu.be/Epn7RmmcoTQ  
101K subscribers / 22,039 views  // 
	Episode 773  
	Measurements of the power supply showing PWM and load regulation  
  
  
  
+++++ +++++ +++++ +++++ +++++ 
  
Howto repair switch mode power supplies #6: Basics of Linear Regulators and voltage references / Donkey Learning IT /  Jul 25, 2017  Switch mode Power Supply repair basics  
https://youtu.be/MkwuofJZm_I  
37.6K subscribers / 171,889 views  // 
	In the sixt video of the Switch Mode Power Supply (SMPS) repair series we look at the basic ideas and priciples of operation of linear serial regulators. Serial regulators are used in every power circuit in order to generate stable supply voltages. Even in SMPS we will rely on linear regulator circuits to get stable voltages in order to feed integrated circuits like the APFC controller, the Pulse Width Modulation (PWM) controller chip, or the supervisor chip. Furthermore, these integrated circuits will contain highly precise reference-voltage generators, which are also based on linear regulators. 
	The video is built up such, that we start from a simple circuit with an incandescent lamp, and we introduce step-by-step new elements into the circuit to get a high power linear regulator. First the functionality of the series drop resistor is discussed. Next, we look into the case when the input voltage is fluctuating over time. In such cases for low power applications we can use a Zener diode in series with a fixed resistor. The functionality and the main property of the Zener diode is briefly introduced (without going into detail about avalanche current, etc.).  
	Next, we focus on medium and high power applications, where a bipolar power transistor is being used as a variable resistor, where the equivalent resistance between the Collector and the Emitter can be adjusted through a driver signal fed into the Base electrode. 
	In real-life circuits, most often a voltage reference circuit formed by a Zener diode and a fixed resistor is used to provide a stable voltage. This reference voltage is than fed into the Base of a power transistor, which in turn is able to provide stable output voltage even for medium and high power applications. Thus, practical circuits are combining Zener reference diodes with power transistors. For example, serial regulators available in three pin power packages, like the LM317, or the classical 7805, they use a similar inner circuit, where the three pins correspond to the power input, power output, and to the ground for the reference diode.  
	One major drawback of linear regulators is, that they dissipate a large portion of the input power in form of heat. This makes linear regulators rather inefficient. Due to the low efficiency, one also need to design linear series regulators with large heatsinks and even with active fans to extract the waste heat. To reduce the amount of power wasted, and to make more efficient power supplies, SMPS use instead a technique called Pulse Width Modulation.  
  
  
  
SMPS repair series #10: Temperature compensated Zener diode in linear regulators / Donkey Learning IT /  Jan 13, 2019  Switch mode Power Supply repair basics  
https://youtu.be/yD5QOu9GgIg  
37.6K subscribers / 35,320 views  // 
	We will cover the topic of the positive thermal coefficient of Zener diodes and the negative thermal coefficient of standard forward biased Silicon diodes. Namely, when Zener diodes with Zener voltages above 6V are being heated up with one Centigrade, their Zener voltage will increase with about 3mV. In contrast to this behavior, when we heat up a Silicon diode with one Centigrade, its forward voltage will go down with about 2mV. 
	Therefore, it was a traditional design trick to put a Zener diode in series with a Silicon diode, and have the two diodes located close to each other on the printed circuit board. Namely, this way the positive temperature coefficient of the Zener will be partially compensated by the negative temperature coefficient of the Silicon diode. This way the drift of the output voltage will be considerably lower, and the power supply will provide a more stable output voltage for a wider temperature range. With modern components like the TL431 precision voltage reference nowadays one can build even more stable power supplies without paying much attention to temperature compensation. However, temperature compensation for old designs was often based on the solution of a Zener put in series with a Silicon diode. Some older equipment might have even used oven stabilized Zeners.  
	There is an other ramification of adding the series Silicon diode to the circuit. Namely, when we use a power transistor in an emitter follower configuration, the output voltage will be now almost the same as the Zener voltage. This is because the reference voltage will increase with about 0.75V (drop on the Silicon diode). This will be lost due to forward drop on the Base-Emitter junction of the bipolar transistor operating in the emitter follower configuration.  
	One has to point out, that Zener diodes which have Zener voltages below 6V will most often have a negative thermal coefficient, since in these diodes the "Avalanche Effect" is very small. Therefore, combining Zener diodes with lower voltages below 6V with a series Silicon diode will not help with the temperature compensation, in fact it might make the situation worse. Thus, one has to check the data-sheet of the given Zener before trying to apply thermal compensation.  
  
  
  
  
  
  
Building a Linear Power Supply, Part 1 The Transformer / Vocademy - Electronics Technology /  May 27, 2023  Building a Linear Power Supply - Solid-state Devices and Analog Circuits Day 1  
https://youtu.be/YiK_fD_WggE  
12.3K subscribers / 5,177 views  // 
	The first stage of a linear power supply is a transformer to step the mains/grid voltage down to a reasonable level.  
  
  
  
  
  
  
  
----------------------------------------  
  
Single Transistor Mobile Phone Charger 
  https://www.electrothinks.com/2020/06/Single-transistor-mobile-phone-charger.html  
  
  
  
  
----------------------------------------  
  
  
220V-AC to 12V-DC, 18W Switching Power Supply / MyVanitar /  Nov 28, 2022  
https://youtu.be/PJDZu1ktJrc  
6.05K subscribers / 5,648 views  // 
	Flyback is the most common circuit topology to build galvanically isolated AC to DC or DC to DC converters. Flyback circuit is cheap and relatively easy to manufacture, therefore nowadays the majority of home or industrial appliances are powered using AC to DC Flyback converters. In general, a Flyback converter is suitable for low-power applications, mostly below 100W.  
	In this article/video, I designed a cheap AC-to-DC flyback converter using a DK124 IC that can deliver up to 18W continuously. I calculated the transformer to handle 12V at the output which can be easily modified to reach other output voltages as well. The DK124 chip does not need any auxiliary winding or even an external startup resistor. The 220V Mains input has been protected using a MOV, an NTC, and a Fuse. The PCB board is single-layer and all components are through-hole.  
	To design the schematic and PCB, I used Altium Designer 22. The fast component search engine (octopart) allowed me to quickly consider components’ information and also generate the BOM. To get high-quality fabricated boards, I sent the Gerber files to PCBWay. To test the power supply, I used Siglent an SDL1020X-E DC Load, an SDM3045X Multimeter, and an SDS1104X-E/SDS2102X Plus oscilloscope.  
	Specifications  
	Input Voltage Range: 85 to 265V-AC  
	Output Power: 18W Continuous  
	Output Voltage: 12VDC  
	Switching Frequency: 65KHz  
  https://www.pcbway.com/blog/technology/220V_AC_to_12V_DC_18W_Switching_Power_Supply_81665a6c.html  
  https://www.pcbway.com/project/shareproject/220V_AC_to_12V_DC_18W_Switching_Power_Supply_d406ac5a.html  
  
  
220V to 12V 20A / Awesome Tech /  Oct 27, 2021  #Inverter #Altium #JLCPCB  
https://youtu.be/xyaa8eaQ7hE  
  269K subscribers / 562,400 views  // 
  
  
Make Buck CC-CV-MPPT 60A | JLCPCB / Awesome Tech /  Feb 22, 2024  #MPPT #Inverter #JLCPCB  
https://youtu.be/XkhfMjIZElU  
  269K subscribers / 8,403 views  // 
	MPPT stands for Maximum Power Point Tracking, a technique to regulate the charge of your battery bank. 
  
  
  
  
  
  
----------------------------------------  
  
220VAC to 8VDC 24W Flyback Switching Power Supply / MyVanitar /  Jun 30, 2023  
https://youtu.be/jQCt8_i_UbU  
6.06K subscribers / 4,537 views  // 
	220VAC to 8VDC 24W Flyback Switching Power Supply  
	======================================  
	Altium Designer + License (Free): https://www.altium.com/yt/myvanitar  
	======================================  
	Altium 365: https://www.altium.com/altium-365  
	======================================  
	OctoPart: https://octopart.com  
	======================================  
	Article: https://www.pcbway.com/blog/technolog...  
	======================================  
	Gerber/PCB Order: https://www.pcbway.com/project/sharep...  
	======================================  
	Other Videos: http://bit.ly/2N9OlPa  
	======================================  
	The most important part of any electronic device is the power supply section. Any instability or malfunction in this part causes the device to stop its operation or show weird behavior. In this article/video, I introduced an AC to DC Flyback Switching power supply that converts 220V-AC to 8V-DC, which can be used in a variety of applications. The 8V selection for the output makes this supply friendly for any type of linear regulator.  
	The maximum power delivery of this power supply is 24W, which means it can handle 3A at 8V output. The controller chip is DK124, which does not need any external supply, a startup resistor, or even an auxiliary winding on the transformer. The transformer's ferrite core is RM8, which is different from most supplies that use EE or EI cores. A small potentiometer allows you to adjust the output voltage and set it to 7.5 to 8V.  
	For the schematic and PCB design, I utilized Altium Designer 23 and shared the project with my friends for feedback and updates using Altium-365. The fast component search engine, Octopart, proved invaluable in quickly obtaining component information and generating the Bill of Materials (BOM). To ensure high-quality fabricated boards, I sent the Gerber files to PCBWay.  
	I tested the board for voltage drop and current delivery, output noise, and load step response. I used the Siglent SDL1020X-E DC Load, Siglent SDS2102X Plus oscilloscope, Siglent SDM3045X multimeter, and Siglent CP4020 current probe to perform all tests. I am confident that this circuit will meet your requirements for a compact and efficient power supply, providing reliable performance on your electronics bench.  
  
  
Temperature, Air Pressure, and Altitude on a GUI using Raspberry Pi Pico, Bosch BMP280, and LVGL / MyVanitar /  Feb 29, 2024  
https://youtu.be/_8rEjUcEoCU  
6.06K subscribers / 975 views  // 
	Temperature, Air Pressure, and Altitude on a GUI using Raspberry Pi Pico, Bosch BMP280, and LVGL  
  
  
  
Switch mode Power Supply repair basics / Donkey Learning IT  
11 videos 87,573 views Last updated on Jan 18, 2019  
  https://www.youtube.com/playlist?list=PLUTV_UMnJSciYeKoJLuQ6jxYsMEeWET3f  
  
  
  
  
----------------------------------------  
  
Switch Mode Power Supply Repair, SMPS / Mr Carlson's Lab /  Apr 13, 2016  
https://youtu.be/NoGl7oeh7eU  
  380K subscribers / 727,217 views  // 
	How to repair a switching "switch mode" power supply. See what's involved. Also a brief explanation about the difference between Linear and switch mode power supplies.  
  
  
  
  
  
  
  
  
  
  
  
----------------------------------------  
  
  
USB-C PD power supply circuit  
  
  
100W USB Type-C Power Delivery Source: Getting Started  
  https://community.element14.com/technologies/power-management/b/blog/posts/100w-usb-type-c-power-delivery-source-getting-started  
Power Delivery (PD) Source Function - MP5031 Power Delivery Controller chip 
MP2491C DC-DC converter chip 
  
  
TPS25740B USB Type-C™ and USB PD Source Controller  
  https://www.ti.com/lit/gpn/TPS25740B  
  
  
  
Infineon’s EZ-PD™ USB-C Power Delivery Controllers  
  https://www.infineon.com/cms/en/product/universal-serial-bus/usb-c-power-delivery-controllers/  
  
  
  
  
  
  
USB-PD Hacks / By Phillip Burgess 
  https://learn.adafruit.com/usb-pd-hacks/things-to-know  
  https://learn.adafruit.com/usb-pd-hacks/overview  
  https://learn.adafruit.com/usb-pd-hacks/scaling-up  
  
  
Build a USB-C Power Supply  
  https://circuitcellar.com/research-design-hub/basics-of-design/build-a-usb-c-power-supply/  
  
STUSB4500 is a USB power delivery controller that addresses sink up to 100 W. (20 V; 5 A).  
  
  
  
  
  
  
  
  
  
  
  
  
USB-C Power Delivery Hardware Design - Phil's Lab #104 / Phil’s Lab /  Apr 23, 2023  PCB Design  
https://youtu.be/W13HNsoHj7A  
  142K subscribers / 79,293 views  // 
USB Type C Power Delivery (PD) basics, part selection, schematic and PCB design, and test implementation. Learn how easy it is to incorporate USB-C PD into your own hardware designs!  
  
  
  
  
  
  
  
  
----------------------------------------  
  
  
  
  
  
  
  
----------------------------------------  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
--------------------------------------------------  
  
FNIRSI DSO-TC3 Digital Oscilloscope Transistor Tester Function Signal Generator 3 in 1 Multifunction Electronic Component Tester  
  
3in1 electronic device tester + DSO + SigGen  
https://www.aliexpress.com/item/1005006067753213.htm  
  
  
FNIRSI DSO-TC3 Digital Oscilloscope, Transistor Tester and Signal Generator in 1  
https://youtu.be/ZNlCieQwIZI  
	#ErCanEverything #Transistor #Tester📌FNIRSI DSO-TC3 Official Store: https://s.click.aliexpress.com/e/_opraiJoYou can find Featured products here👇📌FNIRSI D...  
  
  
All component Tester with mini Oscilloscope, FNIRSI DSO TC3, LCR meter  
https://youtu.be/kb1yx4oIKT8  
	All component Tester with mini Oscilloscope, FNIRSI DSO TC3, LCR meter DSO-TC3 👉 https://s.click.aliexpress.com/e/_oE5eMkbThis is a very good 3 in 1 Tester. ...  
  
  
  
--------------------------------------------------  
  
  
  
--------------------------------------------------  
  
  
  
  
----  
  
  
  
----  
  
  
  
----  
  
  
  
----  
End of File.  
