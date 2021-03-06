
#include "embARC.h"
#include "embARC_debug.h"

#include "dev_gpio.h" //GPIO API头文件
#include "../../../board/emsk/drivers/mux/mux.h"	// Pmod端口配置API`
#include "../../../board/emsk/drivers/mux/mux_hal.h"

#define BUTTON_MASK 						0x7


void LEDRGB (int8_t buf, int8_t cro)
{
	DEV_GPIO *			gpio_write_port;									//或者声明为DEV_GPIO_PTR  gpio_write_port; 

	set_pmod_mux (PM1_UR_UART_0 | PM1_LR_GPIO_A | PM2_GPIO_AC | PM3_GPIO_AC | PM4_GPIO_AC | PM5_UR_GPIO_C | PM5_LR_UART_2 | PM6_UR_SPI_M0 | PM6_LR_GPIO_A);
	int32_t 				ercd;

	gpio_write_port 		= gpio_get_dev (DW_GPIO_PORT_C);
	ercd								= dw_gpio_open (gpio_write_port, 0xfffffff);
	EMBARC_PRINTF ("%d %d\r\n", ercd, E_OK);

	if (ercd == E_OK)
		EMBARC_PRINTF ("gpio open successfully！\r\n");
	else if (ercd == E_OPNED)
		dw_gpio_control (gpio_write_port, GPIO_CMD_SET_BIT_DIR_OUTPUT, 0xfffffff);
	else 
		;

	if (buf == 1) //小车到达站点1，第一个LED等点亮，其他熄灭
		{
			dw_gpio_write (gpio_write_port, 0x0000000, 0xfff0000); //默认常关掉站2，站3，站4的LED
			board_delay_ms (10, 1);

			if (cro == 1)
				{
					dw_gpio_write (gpio_write_port, 0x0007000, 0xffffff); //拥挤程度较低，绿灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 2)
				{
					dw_gpio_write (gpio_write_port, 0x0005000, 0xffffff); //拥挤程度适中，黄灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 3)
				{
					dw_gpio_write (gpio_write_port, 0x000d000, 0xffffff); //拥挤程度较高，红灯亮
					board_delay_ms (10, 1);
				}
			else 
				{
					dw_gpio_write (gpio_write_port, 0x0000000, 0xffff000); //其他数据默认常关
					board_delay_ms (10, 1);
				}

		}

	else if (buf == 2) //小车到达站点2，第二个LED等点亮，其他熄灭
		{
			dw_gpio_write (gpio_write_port, 0x0000000, 0xff0f000); //默认常关掉站1，站3，站4的LED
			board_delay_ms (10, 1);

			if (cro == 1)
				{
					dw_gpio_write (gpio_write_port, 0x0070000, 0xfffffff); //绿灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 2)
				{
					dw_gpio_write (gpio_write_port, 0x0050000, 0xfffffff); //黄灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 3)
				{
					dw_gpio_write (gpio_write_port, 0x00d0000, 0xfffffff); //红灯亮
					board_delay_ms (10, 1);
				}
			else 
				{
					dw_gpio_write (gpio_write_port, 0x0000000, 0xffff000); //其他数据默认常关
					board_delay_ms (10, 1);
				}
		}

	else if (buf == 3) //小车到达站点3，第三个LED等点亮，其他熄灭
		{
			dw_gpio_write (gpio_write_port, 0x0000000, 0xf0ff000); //默认常关掉站1，站2，站4的LED
			board_delay_ms (10, 1);

			if (cro == 1)
				{
					dw_gpio_write (gpio_write_port, 0x0700000, 0xfffffff); //绿灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 2)
				{
					dw_gpio_write (gpio_write_port, 0x0500000, 0xfffffff); //黄灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 3)
				{
					dw_gpio_write (gpio_write_port, 0x0d00000, 0xfffffff); //红灯亮
					board_delay_ms (10, 1);
				}
			else 
				{
					dw_gpio_write (gpio_write_port, 0x0000000, 0xffff000); //其他数据默认常关
					board_delay_ms (10, 1);
				}
		}

	else if (buf == 4) //小车到达站点3，第三个LED等点亮，其他熄灭
		{
			dw_gpio_write (gpio_write_port, 0x0000000, 0x0fff000); //默认常关掉站1，站2，站3的LED
			board_delay_ms (10, 1);

			if (cro == 1)
				{
					dw_gpio_write (gpio_write_port, 0x7000000, 0xfffffff); //绿灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 2)
				{
					dw_gpio_write (gpio_write_port, 0x5000000, 0xfffffff); //黄灯亮
					board_delay_ms (10, 1);
				}
			else if (cro == 3)
				{
					dw_gpio_write (gpio_write_port, 0xd000000, 0xfffffff); //红灯亮
					board_delay_ms (10, 1);
				}
			else 
				{
					dw_gpio_write (gpio_write_port, 0x0000000, 0xffff000); //其他数据默认常关
					board_delay_ms (10, 1);
				}
		}

	else 
		{
			dw_gpio_write (gpio_write_port, 0x0000000, 0xffff000); //其他数据默认常关
			board_delay_ms (10, 1);
		}

	return;
}


/** @} */