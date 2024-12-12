# DIY MiSTer Handheld - Model 01 (DMH-01)
Warning: Before jumping into this project, review the list of known issues and the recommended skillset.

## What is the DMH-01?
This project aspires to be a freely available, open source handheld MiSTer that can be built as a DIY project. I decided to build the initial version of this handheld after acquiring the QMTech Cyclone V dev board with built-in SDRAM module. While running some tests on the board for my QMTech review video, I realized that this dev board is particularly suitable for a handheld MiSTer, due to its inclusion of 128MB of SDRAM and its lower power consumption profile.

On of my main design goals for this project was to be able to use the QMTech Cyclone V dev board _without modifying it_. This decision was the primary constraint driving the overall thickness of the device. I feel like a good balance was struck through that process - the handheld is about the same size and thickness as an Anbernic Win600 and feels good to hold.

## Current Capabilities
* Fully playable handheld MiSTer FPGA gaming system
* SNES-style buttons (D-Pad, Start, Select, A, B, X, Y, L, and R)
* Front-facing User, OSD, and Reset buttons
* USB-C charging port
* Approximately 2.5 hours of battery life
* Stereo speakers with physical volume dial
* TapTo support
* 2 external USB ports (for additional controllers, a wifi adapter, bluetooth adapter, etc.)

## Opportunities for Improvement
The DMH-01 is fully functional and playable. It should be noted, however, that there are many things that can and should be improved upon. I would encourage everyone who builds a DMH-01 to contribute any improvements they make back into this project.

### Known Issues
* **Device resets when unplugging the charger**: This is the biggest issue currently, and perhaps the most frustrating. You can plug the device into a USB-C power adapter so it will charge while you're playing it. However, when you unplug the charger, the handheld will reboot. This is due to a momentary interruption in power while the charge controller switches from USB power to the LiPo battery pack. I assume that this is happening due to the large current requirements of the Cyclone V board. I've tried decoupling the power source with a 3F capacitor, and even that wasn't enough to keep the device running during the power switch over. Lately, I've been thinking that the best solution might be a small backup battery in parallel with the main battery pack, to provide power for that split second during the switchover. If anyone else has any ideas and wants to tackle this problem, please do!

### High Priority Improvements
* **Battery Indicator**: There is currently no external indicator to give the user the status of the battery. Therefore, when the battery dies, the device just powers off. The charge controller inside the handheld does have LEDs and a status pin for gathering this information, which could be broken out to an LED that's externally facing.
* **Screen Brightness**: There is currently not a way to adjust the brightness of the display. The HDMI display does have brightness adjustment buttons, but they are only accessible when opening up the handheld. The best solution would probably be to just port those buttons out to a set of buttons externally available on the shell.

### Other Improvements
* **Headphone Jack**: There is currently no externally accessible headphone jack. I think one could be easily added by porting out the 3.5mm jack on the HDMI display.
* **Battery Life**: The battery currently used in the device is a 5000mAH Lithium Polymer battery pack, which provides approximately 2.5 hours of gameplay. I do believe that with some redesign of the case, a larger battery pack could be used. Before I added the shoulder buttons, I was able to fit an 8000mAH battery and was getting around 4 hours of play time on a single charge. I also experimented with a 10,000mAH battery pack, but could not make it fit and keep the device footpring reasonable.
* **Active Cooling**: The current design uses copper heatsinks as a passive cooling solution. I don't have any concern over the device getting hot enough to cause damage, but it does get a bit warm when playing certain cores (such as PSX) for more than 30 minutes. A more efficient heatsink solution or even a fan might be something to consider.

## Required Tools and Equipment
- [ ] 3D Printer
- [ ] Soldering Iron
- [ ] Wire Strippers
- [ ] Small phillips screwdriver
- [ ] Xacto/hobby knife
- [ ] Abrasive Pen for scraping off solder mask (I prefer steel, but fiberglass will also work)
- [ ] Hot Glue Gun

## Consumables
- [ ] Double-sided tape
- [ ] VHB Tape
- [ ] 30 AWG solid core wire
- [ ] 28 AWG stranded wire
- [ ] Hot glue stick
- [ ] Solder
- [ ] Kapton Tape

## Parts
Work in progress... links coming soon
- [ ] QMTech Cyclone V Dev Board w/ built-in SDRAM
- [ ] 5.5" HDMI Display ([Amazon](https://www.amazon.com/gp/product/B0CP3DH3LN))
- [ ] Sacrificial SFC Controller
- [ ] ATMega Pro Micro microcontroller
- [ ] 3A Charge Controller / Boost Converter
- [ ] LiPo Battery
- [ ] Stereo Audio Amplifier
- [ ] 1W 8Ohm Speakers ([Amazon](https://www.amazon.com/gp/product/B0BMB195SX))
- [ ] USB Hub ([Amazon](https://www.amazon.com/dp/B09M3TVSTF))
- [ ] Female block headers
- [ ] JST connectors ([Amazon](https://www.amazon.com/gp/product/B0B2D9ZV3P))
- [ ] USB-C male connector
- [ ] USB-A male connector
- [ ] NFC Reader
- [ ] 3 Tact Switches
- [ ] Power Switch
- [ ] Screws

## Build Instructions
Working progress... Details coming soon


1. Print the case and all the pieces
2. Cut down the SFC controller
3. Prep the controller PCBs
4. Program the Pro Micro
4. Assemble the right controller


2. Install the screen
3. Install the speakers
4. Trim down the sacrificial SNES controller
5. Program the Arduino Pro Micro
8. Install the QMTech bracket
9. Install and wire up the USB hub
10. Install and wire up the audio amplifier
11. Install and wire up the charge controller and power switch
12. Install the NFC reader
13. Install the battery
14. Close up the device
