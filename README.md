# MPU9250 STM32 Driver

This repository contains a driver for the MPU9250 sensor on the STM32 platform. The driver is located in the `Drivers/Mpu9250` directory and consists of a `.h` and `.cpp` file.

## Features

- The driver uses the HAL libraries to interface with the I2C, DMA, and Timer peripherals.
- All functions in the driver have Doxygen comments for easy documentation.
- The project includes a small STM32CubeIDE demo project for the Blackpill (STM32F401) development board.
- The demo project sends all 10 axes of data through the onboard USB port, functioning as a Virtual Com Port (VCP).
- The library supports both blocking and asynchronous modes of operation.
- Most settings of the MPU9250 can be changed without needing to refer to the datasheet, using just a couple of function calls.

## Usage

To use the driver, follow these steps:

1. Copy the `Mpu9250.h` and `Mpu9250.cpp` files into your project's source directory.
2. Include the `Mpu9250.h` header file in your source code.
3. Initialize the necessary peripherals (I2C, DMA, Timer) using the HAL library.
4. Create an instance of the `Mpu9250` class.
5. Call the appropriate functions to configure and interact with the MPU9250 sensor.

For detailed usage instructions and function documentation, please refer to the Doxygen comments in the `Mpu9250.h` file.
