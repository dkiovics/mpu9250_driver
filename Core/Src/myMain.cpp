/*
 * myMain.cpp
 *
 *  Created on: May 8, 2024
 *      Author: dkiovics
 */


#include "main.h"
#include "mpu9250.h"
#include "i2c.h"
#include "tim.h"
#include "usb_device.h"
#include <string.h>
#include "usbd_cdc_if.h"

Mpu9250* imu;

extern "C" {

void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c){
	imu->i2cReceiveCpltCallback(hi2c);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim == &htim1){
		imu->timPeriodEllapsedCallback();
	}
}

int __io_putchar(int ch)
{
	while(CDC_Transmit_FS((uint8_t*)&ch, 1) == USBD_BUSY){}
	return 0;
}

void myMain(){
	imu = new Mpu9250(&hi2c1, 0x68, 0x0C, DMA1_Stream0_IRQn);
	//imu = new Mpu9250(&hi2c1, 0x68, 0x0C);

	HAL_TIM_Base_Start_IT(&htim1);

	if(imu->detectImu() && imu->detectMagnetometer()){
		printf("IMU and MAG detected\n");
	}else{
		printf("IMU or MAG not detected\n");
	}

	imu->setDefaultSettings();
	HAL_Delay(1000);

	while(true){
		Mpu9250::Vec3 gyro = imu->readGyroData();
		Mpu9250::Vec3 acc = imu->readAccData();
		Mpu9250::Vec3 mag = imu->readMagData();
		float temp = imu->readTempData();

		printf("%f;%f;%f;%f;%f;%f;%f;%f;%f;%f\n", gyro.x, gyro.y, gyro.z, temp, acc.x, acc.y, acc.z, mag.x, mag.y, mag.z);

		HAL_Delay(100);
	}
}


}

