# nRF52xxx Template Project

This template project provides a starting point for developing applications for nRF52 series microcontrollers. It supports various development boards and configurations.

## Table of Contents

1. [Prerequisites](#prerequisites)
2. [Environment Setup](#environment-setup)
3. [Project Setup](#project-setup)
4. [Compilation](#compilation)
5. [Creating UF2 File](#creating-uf2-file)
6. [Flashing](#flashing)
7. [Configuration Options](#configuration-options)
8. [Customizing the Project](#customizing-the-project)
9. [Troubleshooting](#troubleshooting)

## Prerequisites

Ensure you have the following installed:
- ARM GCC Toolchain
- nRF5 SDK (v17.1.0 recommended)
- Python 3
- Git

## Environment Setup

1. Install ARM GCC Toolchain:
   ```bash
   wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2
   sudo tar xjf gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2 -C /opt
   ```

2. Download and extract nRF5 SDK:
   ```bash
   wget https://www.nordicsemi.com/-/media/Software-and-other-downloads/SDKs/nRF5/Binaries/nRF5_SDK_17.1.0_ddde560.zip
   unzip nRF5_SDK_17.1.0_ddde560.zip -d ~/nrf_sdk
   ```

3. Install adafruit-nrfutil:
   ```bash
   pip3 install adafruit-nrfutil
   ```

4. Set up environment variables. Add these to your `.bashrc` or `.zshrc`:
   ```bash
   export ARM_GCC_PATH=/opt/gcc-arm-none-eabi-9-2020-q2-update/bin
   export NRF_SDK_PATH=~/nrf_sdk/nRF5_SDK_17.1.0_ddde560
   export PATH=$PATH:$ARM_GCC_PATH
   ```

5. Source your shell configuration:
   ```bash
   source ~/.bashrc  # or source ~/.zshrc
   ```

## Project Setup

1. Clone the template repository:
   ```bash
   git clone https://github.com/tianrking/nRF52xxx_template.git
   cd nRF52xxx_template
   ```

2. Update SDK path in Makefile:
   Edit `pca10056/blank/armgcc/Makefile` (and similar files for other boards) and ensure:
   ```makefile
   SDK_ROOT := $(NRF_SDK_PATH)
   ```

## Compilation

1. Choose your target board and configuration. For example, for nRF52840 DK without SoftDevice:
   ```bash
   cd pca10056/blank/armgcc
   ```

2. Compile the project:

    ```bash
    make GNU_INSTALL_ROOT=/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/
    ```
    
   ```bash
   make
   ```

## Creating UF2 File

Generate a UF2 file for flashing. The command varies based on your configuration:

For nRF52840 without SoftDevice:
```bash
python3 $NRF_SDK_PATH/tools/uf2conv.py _build/nrf52840_xxaa.hex -c -b 0x00000 -f 0xADA52840 -o firmware.uf2
```

For nRF52840 with SoftDevice (e.g., S140 v7.x):
```bash
python3 $NRF_SDK_PATH/tools/uf2conv.py _build/nrf52840_xxaa.hex -c -b 0x27000 -f 0xADA52840 -o firmware.uf2
```

## Flashing

1. Put your nRF52 board into bootloader mode (usually by double-tapping the reset button).
2. The board should appear as a USB drive on your computer.
3. Copy the generated `firmware.uf2` file to this USB drive.
4. The board will automatically flash and restart with the new firmware.

## Configuration Options

- **blank**: Use for projects without SoftDevice. Application starts at address 0x00000.
- **mbr**: Use for projects with SoftDevice. Application start address depends on the SoftDevice version.

SoftDevice versions and corresponding application start addresses:
- S140 v6.x: 0x26000
- S140 v7.x: 0x27000

## Customizing the Project

- Modify `main.c` in the root directory to change the functionality of your project.
- To add new source files:
  1. Add them to the appropriate directory (e.g., `src/`)
  2. Update the Makefile to include these new files

## Troubleshooting

## Development Board Reference

This template supports various Nordic Semiconductor development kits and reference designs. Each is tailored for specific nRF5 series chips. Here's a detailed breakdown of the supported boards:

1. **pca10040**:
   - Chip: nRF52832
   - Development Kit: nRF52 DK (Development Kit)
   - Features: General-purpose development board, suitable for nRF52832 application development and prototyping

2. **pca10040e**:
   - Chip: nRF52810
   - Development Kit: nRF52810 Evaluation Kit
   - Features: "e" stands for "Evaluation", designed for cost-sensitive application evaluation

3. **pca10056**:
   - Chip: nRF52840
   - Development Kit: nRF52840 DK
   - Features: High-end development board in the nRF52 series, supports BLE 5.0, Thread, Zigbee, etc.

4. **pca10056e**:
   - Chip: nRF52811
   - Development Kit: nRF52811 Evaluation Kit
   - Features: Evaluation board for nRF52811, suitable for Direction Finding applications

5. **pca10059**:
   - Chip: nRF52840
   - Development Kit: nRF52840 Dongle
   - Features: USB dongle form factor, ideal for portable applications and rapid prototyping

6. **pca10100e**:
   - Chip: nRF52833
   - Development Kit: nRF52833 Evaluation Kit
   - Features: Evaluation board for nRF52833, supports BLE 5.1 and Direction Finding

### Key Points:
- Boards without an "e" suffix are typically full-featured Development Kits (DK).
- Boards with an "e" suffix are Evaluation Kits, usually with fewer features but sufficient for chip evaluation.
- The numeric code typically corresponds to specific chip series (e.g., 10040 for nRF52832, 10056 for nRF52840).

### Note for nice!nano Users:
If you're using a nice!nano board, which is based on the nRF52840, the closest reference design is pca10056. However, be aware that nice!nano may have its own specific configurations that might differ slightly from the standard nRF52840 DK. When compiling for nice!nano, it's generally recommended to use the pca10056 configuration, but you may need to make some minor adjustments to account for specific hardware design differences.

## Bootloader Information

For some applications, especially when using custom boards like nice!nano, you may need to use a specific bootloader. You can download the bootloader from the following sources:

1. Adafruit nRF52 Bootloader:
   - URL: [https://github.com/adafruit/Adafruit_nRF52_Bootloader/releases](https://github.com/adafruit/Adafruit_nRF52_Bootloader/releases)
   - This is a general-purpose bootloader for nRF52 series chips, maintained by Adafruit.

2. nice!nano Specific Bootloader:
   - URL: [https://nicekeyboards.com/assets/nice_nano_bootloader-0.6.0_s140_6.1.1.zip](https://nicekeyboards.com/assets/nice_nano_bootloader-0.6.0_s140_6.1.1.zip)
   - This bootloader is specifically designed for the nice!nano board.

Choose the appropriate bootloader based on your specific hardware and project requirements. If you're using a standard Nordic development kit, you typically don't need to worry about the bootloader as it comes pre-installed.

```bash
adafruit-nrfutil --verbose dfu serial --package nice_nano_bootloader-0.6.0_s140_6.1.1.zip -p  /dev/ttyACM0 
```


