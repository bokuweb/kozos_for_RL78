This demo flashes an LED on the RPB board for RL78/G13. Note this will not work on RSK. The
purpose of this demo is to provide simple code that can be clearly seen to be running on 
the RPB hardware using the GNURL78 compiler.

The make command will generate the mot file, RL78G13_led_flasher.mot needs to be flashed
onto the target hardware

Export the toolchain path,
Windows
set PATH=$toolchain_path\bin;%PATH%
Linux
export PATH=/usr/share/gnutoolchain/bin/:$PATH

Run the make file using make command and download the code using WriteEZ5 tool.

The WriteEZ5 tool is accessible from Start ->  Programs -> Renesas Electronics Tools -> YRPRL78G13 -> WriteEZ5. 
This tool  is able to erase, flash and verify and S-Record file.

While flashing the code(RL78G13_led_flasher.mot), connect the jumpers 
J6,J7,J8 and J9 in 1-2 position.
After flashing, unplug the RPB and move the jumpers to  the 2-3 position and 
reconnect the power, you should be able to see the  user LED flashing
The blue user LED, D2, should flash after downloading the code.

Alternatively, the file 'RL78G13_LED_SAMPLE.x' can also be downloaded and then debugged using e2studio.