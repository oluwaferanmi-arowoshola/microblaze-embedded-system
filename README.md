# MicroBlaze Embedded System (Nexys DDR)

Embedded FPGA system built with a Xilinx MicroBlaze soft-core processor on the Nexys DDR board.  
The design integrates UART, GPIO-controlled LEDs, and switch inputs, with C firmware developed in Vitis to map switch states directly to LEDs.

---

## Project Overview

This project implements a MicroBlaze-based embedded system on the Nexys DDR FPGA board.  
The objective was to build a hardware/software system in which slide switch inputs are read by the MicroBlaze processor and corresponding LED outputs are driven in real time.

The design includes:

- MicroBlaze soft-core processor
- UART interface for serial output
- GPIO input peripheral for board switches
- GPIO output peripheral for board LEDs

The firmware continuously reads switch values through memory-mapped GPIO and writes the corresponding values to the LED GPIO, enabling direct switch-to-LED hardware interaction.

---

## System Architecture

Although the original Vivado block design image is not included in this repository, the implemented system architecture consists of:

- MicroBlaze processor
- AXI-connected GPIO for switch input
- AXI-connected GPIO for LED output
- UART interface for runtime messages

The synthesized schematic below represents the implemented hardware structure.

---

## Synthesized System Schematic

![System Schematic](docs/system_schematic.PNG)

---

## Synthesis and Implementation Results

### Post-Synthesis Summary
![Post-Synthesis Summary](docs/post_synthesis_summary.PNG)

### Post-Implementation Summary
![Post-Implementation Summary](docs/post_implementation_summary.PNG)

---

## Firmware

The application was developed in Vitis using Xilinx GPIO drivers.

Main firmware behavior:

- Initialize switch GPIO as input
- Initialize LED GPIO as output
- Initialize platform and UART output
- Continuously read switch state
- Write corresponding value to LED GPIO

The firmware source is included in the `firmware/` directory.

---

## Vitis Build / Runtime View

![Vitis Console](docs/vitis_console.PNG)

The console output confirms:

- platform startup
- successful GPIO initialization
- runtime execution of the GPIO control loop

---

## Hardware Demonstration

A demonstration video is included in the `docs/` folder showing the project running on the Nexys DDR board.

Verified hardware behavior:
- flipping slide switches changes the LED outputs
- MicroBlaze firmware successfully interfaces with board peripherals
- switch-to-LED mapping works on physical hardware

---

## Repository Structure

- `firmware/` – C firmware source files used in Vitis
- `docs/` – synthesis screenshots, implementation screenshots, runtime console image, and demonstration video

## Tools Used

- Xilinx Vivado
- Xilinx Vitis
- C
- MicroBlaze soft processor
- Nexys DDR FPGA board

## Notes

This project was developed as part of FPGA and embedded systems coursework focused on hardware/software integration using a soft-core processor architecture.

---

## Author

Oluwaferanmi Arowoshola  
Electrical & Computer Engineering  
Minnesota State University, Mankato
