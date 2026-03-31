/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"

XGpio sw_gpio, led_gpio;

void driverInit(){

	int Status;
	print("Initialization of switch gpio\n\r");
	Status = XGpio_Initialize(&sw_gpio,XPAR_GPIO_SW_DEVICE_ID); //XGpio_Initialize(&sw_gpio, XPAR_GPIO_SW_DEVICE_ID);
	if(Status != XST_SUCCESS){
		print("Failed\n\r");
	}
	else{
		print("Success\n\r");
		XGpio_SetDataDirection(&sw_gpio,1,1);
	}

	print("Initialization of led gpio\n\r");
	Status = XGpio_Initialize(&led_gpio,XPAR_GPIO_LED_DEVICE_ID);
	if(Status != XST_SUCCESS){
		print("Failed\n\r");
	}
	else{
		print("Success\n\r");
		XGpio_SetDataDirection(&led_gpio,1,0);
		XGpio_DiscreteWrite(&led_gpio,1,0);
	}
}

int main()
{
    unsigned int sw_val;

	init_platform();

    print("Hello World\n\r");

    driverInit();

    print("Running GPIO\n\r");
   // XGpio DiscreteWrite(&led gpio, 1, 0x8000);
    while(1)
    {
    	sw_val=XGpio_DiscreteRead(&sw_gpio, 1);
    	switch(sw_val) {
    	case 0:
    		XGpio_DiscreteWrite(&led_gpio, 1, 0x0);
    		break;
    	case 1:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x1);
    	    break;
    	case 2:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x2);
    	    break;
    	case 4:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x4);
    	    break;
    	case 8:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x8);
    	    break;
    	case 16:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x10);
    	    break;
    	case 32:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x20);
    	    break;
    	case 64:
    	    XGpio_DiscreteWrite(&led_gpio, 1, 0x40);
    	    break;
    	case 128:
    	   	XGpio_DiscreteWrite(&led_gpio, 1, 0x80);
    	    break;
    	case 256://8 bit
    	   	XGpio_DiscreteWrite(&led_gpio, 1, 0x100);
     		break;
    	default:
    	   // print("default\n\r");
    		break;
    	}
    }
    print("Successfully ran Hello World application\n\r");


    cleanup_platform();
    return 0;
}
