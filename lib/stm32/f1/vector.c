/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#define WEAK __attribute__ ((weak))

/* Symbols exported by the linker script(s). */
extern unsigned _etext, _data, _edata, _ebss, _stack;

void reset_handler(void);
void blocking_handler(void);
void null_handler(void);

void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK SVC_Handler(void);
void WEAK debug_monitor_handler(void);
void WEAK PendSV_Handler(void);
void WEAK sys_tick_handler(void);
void WEAK wwdg_isr(void);
void WEAK pvd_isr(void);
void WEAK tamper_isr(void);
void WEAK rtc_isr(void);
void WEAK flash_isr(void);
void WEAK rcc_isr(void);
void WEAK exti0_isr(void);
void WEAK exti1_isr(void);
void WEAK exti2_isr(void);
void WEAK exti3_isr(void);
void WEAK exti4_isr(void);
void WEAK dma1_channel1_isr(void);
void WEAK dma1_channel2_isr(void);
void WEAK dma1_channel3_isr(void);
void WEAK dma1_channel4_isr(void);
void WEAK dma1_channel5_isr(void);
void WEAK dma1_channel6_isr(void);
void WEAK dma1_channel7_isr(void);
void WEAK adc1_2_isr(void);
void WEAK usb_hp_can_tx_isr(void);
void WEAK usb_lp_can_rx0_isr(void);
void WEAK can_rx1_isr(void);
void WEAK can_sce_isr(void);
void WEAK exti9_5_isr(void);
void WEAK tim1_brk_isr(void);
void WEAK tim1_up_isr(void);
void WEAK tim1_trg_com_isr(void);
void WEAK tim1_cc_isr(void);
void WEAK tim2_isr(void);
void WEAK tim3_isr(void);
void WEAK tim4_isr(void);
void WEAK i2c1_ev_isr(void);
void WEAK i2c1_er_isr(void);
void WEAK i2c2_ev_isr(void);
void WEAK i2c2_er_isr(void);
void WEAK spi1_isr(void);
void WEAK spi2_isr(void);
void WEAK usart1_isr(void);
void WEAK usart2_isr(void);
void WEAK usart3_isr(void);
void WEAK exti15_10_isr(void);
void WEAK rtc_alarm_isr(void);
void WEAK usb_wakeup_isr(void);
void WEAK tim8_brk_isr(void);
void WEAK tim8_up_isr(void);
void WEAK tim8_trg_com_isr(void);
void WEAK tim8_cc_isr(void);
void WEAK adc3_isr(void);
void WEAK fsmc_isr(void);
void WEAK sdio_isr(void);
void WEAK tim5_isr(void);
void WEAK spi3_isr(void);
void WEAK uart4_isr(void);
void WEAK uart5_isr(void);
void WEAK tim6_isr(void);
void WEAK tim7_isr(void);
void WEAK dma2_channel1_isr(void);
void WEAK dma2_channel2_isr(void);
void WEAK dma2_channel3_isr(void);
void WEAK dma2_channel4_5_isr(void);
void WEAK dma2_channel5_isr(void);
void WEAK eth_isr(void);
void WEAK eth_wkup_isr(void);
void WEAK can2_tx_isr(void);
void WEAK can2_rx0_isr(void);
void WEAK can2_rx1_isr(void);
void WEAK can2_sce_isr(void);
void WEAK otg_fs_isr(void);


__attribute__ ((section(".vectors")))
void (*const vector_table[]) (void) = {
	(void*)&_stack,		/* Addr: 0x0000_0000 */
	reset_handler,		/* Addr: 0x0000_0004 */
	nmi_handler,		/* Addr: 0x0000_0008 */
	hard_fault_handler,	/* Addr: 0x0000_000C */
	mem_manage_handler,	/* Addr: 0x0000_0010 */
	bus_fault_handler,	/* Addr: 0x0000_0014 */
	usage_fault_handler,	/* Addr: 0x0000_0018 */
	0, 0, 0, 0,		/* Reserved Addr: 0x0000_001C - 0x0000_002B */
	SVC_Handler,		/* Addr: 0x0000_002C */
	debug_monitor_handler,	/* Addr: 0x0000_0030*/
	0,			/* Reserved Addr: 0x0000_00034 */
	PendSV_Handler,		/* Addr: 0x0000_0038 */
	sys_tick_handler,	/* Addr: 0x0000_003C */
	wwdg_isr,		/* Addr: 0x0000_0040 */
	pvd_isr,		/* Addr: 0x0000_0044 */
	tamper_isr,		/* Addr: 0x0000_0048 */
	rtc_isr,		/* Addr: 0x0000_004C */
	flash_isr,		/* Addr: 0x0000_0050 */
	rcc_isr,		/* Addr: 0x0000_0054 */
	exti0_isr,		/* Addr: 0x0000_0058 */
	exti1_isr,		/* Addr: 0x0000_005C */
	exti2_isr,		/* Addr: 0x0000_0060 */
	exti3_isr,		/* Addr: 0x0000_0064 */
	exti4_isr,		/* Addr: 0x0000_0068 */
	dma1_channel1_isr,	/* Addr: 0x0000_006C */
	dma1_channel2_isr,	/* Addr: 0x0000_0070 */
	dma1_channel3_isr,	/* Addr: 0x0000_0074 */
	dma1_channel4_isr,	/* Addr: 0x0000_0078 */
	dma1_channel5_isr,	/* Addr: 0x0000_007C */
	dma1_channel6_isr,	/* Addr: 0x0000_0080 */
	dma1_channel7_isr,	/* Addr: 0x0000_0084 */
	adc1_2_isr,		/* Addr: 0x0000_0088 */
	usb_hp_can_tx_isr,	/* Addr: 0x0000_008C */
	usb_lp_can_rx0_isr,	/* Addr: 0x0000_0090 */
	can_rx1_isr,		/* Addr: 0x0000_0094 */
	can_sce_isr,		/* Addr: 0x0000_0098 */
	exti9_5_isr,		/* Addr: 0x0000_009C */
	tim1_brk_isr,		/* Addr: 0x0000_00A0 */
	tim1_up_isr,		/* Addr: 0x0000_00A4 */
	tim1_trg_com_isr,	/* Addr: 0x0000_00A8 */
	tim1_cc_isr,		/* Addr: 0x0000_00AC */
	tim2_isr,		/* Addr: 0x0000_00B0 */
	tim3_isr,		/* Addr: 0x0000_00B4 */
	tim4_isr,		/* Addr: 0x0000_00B8 */
	i2c1_ev_isr,		/* Addr: 0x0000_00BC */
	i2c1_er_isr,		/* Addr: 0x0000_00C0 */
	i2c2_ev_isr,		/* Addr: 0x0000_00C4 */
	i2c2_er_isr,		/* Addr: 0x0000_00C8 */
	spi1_isr,		/* Addr: 0x0000_00CC */
	spi2_isr,		/* Addr: 0x0000_00D0 */
	usart1_isr,		/* Addr: 0x0000_00D4 */
	usart2_isr,		/* Addr: 0x0000_00D8 */
	usart3_isr,		/* Addr: 0x0000_00DC */
	exti15_10_isr,		/* Addr: 0x0000_00E0 */
	rtc_alarm_isr,		/* Addr: 0x0000_00E4 */
	usb_wakeup_isr,		/* Addr: 0x0000_00E8 */
	tim8_brk_isr,		/* Addr: 0x0000_00EC */
	tim8_up_isr,		/* Addr: 0x0000_00F0 */
	tim8_trg_com_isr,	/* Addr: 0x0000_00F4 */
	tim8_cc_isr,		/* Addr: 0x0000_00F8 */
	adc3_isr,		/* Addr: 0x0000_00FC */
	fsmc_isr,		/* Addr: 0x0000_0100 */
	sdio_isr,		/* Addr: 0x0000_0104 */
	tim5_isr,		/* Addr: 0x0000_0108 */
	spi3_isr,		/* Addr: 0x0000_010C */
	uart4_isr,		/* Addr: 0x0000_0110 */
	uart5_isr,		/* Addr: 0x0000_0114 */
	tim6_isr,		/* Addr: 0x0000_0118 */
	tim7_isr,		/* Addr: 0x0000_011C */
	dma2_channel1_isr,	/* Addr: 0x0000_0120 */
	dma2_channel2_isr,	/* Addr: 0x0000_0124 */
	dma2_channel3_isr,	/* Addr: 0x0000_0128 */
	dma2_channel4_5_isr,	/* Addr: 0x0000_012C */
	dma2_channel5_isr,	/* Addr: 0x0000_0130 */
	eth_isr,		/* Addr: 0x0000_0134 */
	eth_wkup_isr,		/* Addr: 0x0000_0138 */
	can2_tx_isr,		/* Addr: 0x0000_013C */
	can2_rx0_isr,		/* Addr: 0x0000_0140 */
	can2_rx1_isr,		/* Addr: 0x0000_0144 */
	can2_sce_isr,		/* Addr: 0x0000_0148 */
	otg_fs_isr,		/* Addr: 0x0000_014C */
};

void reset_handler(void) __attribute__((__interrupt__));
void reset_handler(void)
{
	extern int main(void);
	extern int __libc_init_array(void);
	extern unsigned __data_start;    /* start of .data in the linker script */
	extern unsigned __data_end__;      /* end of .data in the linker script */
	extern unsigned const __data_load;  /* initialization values for .data  */
	extern unsigned __bss_start__;    /* start of .bss in the linker script */
	extern unsigned __bss_end__;        /* end of .bss in the linker script */
	unsigned const *src;
	unsigned *dst;

	__asm__("MSR msp, %0" : : "r"(&_stack));

	/* copy the data segment initializers from flash to RAM... */
	src = &__data_load;
	for (dst = &__data_start; dst < &__data_end__; ++dst, ++src) {
		*dst = *src;
	}

	/* zero fill the .bss segment... */
	for (dst = &__bss_start__; dst < &__bss_end__; ++dst) {
		*dst = 0;
	}
	/* call all static constructors in C++ (harmless in C programs) */
	__libc_init_array();

	/* Call the application's entry point. */
	main();
}

// ---------------- just in case the  C lib version doesn't seem to work, do it here ----------------------
/*extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));
extern void (*__preinit_array_start []) (void) __attribute__((weak));
extern void (*__preinit_array_end []) (void) __attribute__((weak));
extern void _init (void);


__libc_init_array(void)
{
	int count;
	int i;

	count = __preinit_array_end - __preinit_array_start;
	for (i = 0; i < count; i++)
		__preinit_array_start[i] ();

	_init();

	count = __init_array_end - __init_array_start;
	for (i = 0; i < count; i++)
		__init_array_start[i] ();
}*/

// --------------------------------------------------------------------------------------------------------

void blocking_handler(void)
{
	while (1) ;
}

void null_handler(void)
{
	/* Do nothing. */
}

#pragma weak nmi_handler = null_handler
#pragma weak hard_fault_handler = blocking_handler
#pragma weak mem_manage_handler = blocking_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak usage_fault_handler = blocking_handler
#pragma weak SVC_Handler = null_handler
#pragma weak debug_monitor_handler = null_handler
#pragma weak PendSV_Handler = null_handler
#pragma weak sys_tick_handler = null_handler
#pragma weak wwdg_isr = null_handler
#pragma weak pvd_isr = null_handler
#pragma weak tamper_isr = null_handler
#pragma weak rtc_isr = null_handler
#pragma weak flash_isr = null_handler
#pragma weak rcc_isr = null_handler
#pragma weak exti0_isr = null_handler
#pragma weak exti1_isr = null_handler
#pragma weak exti2_isr = null_handler
#pragma weak exti3_isr = null_handler
#pragma weak exti4_isr = null_handler
#pragma weak dma1_channel1_isr = null_handler
#pragma weak dma1_channel2_isr = null_handler
#pragma weak dma1_channel3_isr = null_handler
#pragma weak dma1_channel4_isr = null_handler
#pragma weak dma1_channel5_isr = null_handler
#pragma weak dma1_channel6_isr = null_handler
#pragma weak dma1_channel7_isr = null_handler
#pragma weak adc1_2_isr = null_handler
#pragma weak usb_hp_can_tx_isr = null_handler
#pragma weak usb_lp_can_rx0_isr = null_handler
#pragma weak can_rx1_isr = null_handler
#pragma weak can_sce_isr = null_handler
#pragma weak exti9_5_isr = null_handler
#pragma weak tim1_brk_isr = null_handler
#pragma weak tim1_up_isr = null_handler
#pragma weak tim1_trg_com_isr = null_handler
#pragma weak tim1_cc_isr = null_handler
#pragma weak tim2_isr = null_handler
#pragma weak tim3_isr = null_handler
#pragma weak tim4_isr = null_handler
#pragma weak i2c1_ev_isr = null_handler
#pragma weak i2c1_er_isr = null_handler
#pragma weak i2c2_ev_isr = null_handler
#pragma weak i2c2_er_isr = null_handler
#pragma weak spi1_isr = null_handler
#pragma weak spi2_isr = null_handler
#pragma weak usart1_isr = null_handler
#pragma weak usart2_isr = null_handler
#pragma weak usart3_isr = null_handler
#pragma weak exti15_10_isr = null_handler
#pragma weak rtc_alarm_isr = null_handler
#pragma weak usb_wakeup_isr = null_handler
#pragma weak tim8_brk_isr = null_handler
#pragma weak tim8_up_isr = null_handler
#pragma weak tim8_trg_com_isr = null_handler
#pragma weak tim8_cc_isr = null_handler
#pragma weak adc3_isr = null_handler
#pragma weak fsmc_isr = null_handler
#pragma weak sdio_isr = null_handler
#pragma weak tim5_isr = null_handler
#pragma weak spi3_isr = null_handler
#pragma weak uart4_isr = null_handler
#pragma weak uart5_isr = null_handler
#pragma weak tim6_isr = null_handler
#pragma weak tim7_isr = null_handler
#pragma weak dma2_channel1_isr = null_handler
#pragma weak dma2_channel2_isr = null_handler
#pragma weak dma2_channel3_isr = null_handler
#pragma weak dma2_channel4_5_isr = null_handler
#pragma weak dma2_channel5_isr
#pragma weak eth_isr = null_handler
#pragma weak eth_wkup_isr = null_handler
#pragma weak can2_tx_isr = null_handler
#pragma weak can2_rx0_isr = null_handler
#pragma weak can2_rx1_isr = null_handler
#pragma weak can2_sce_isr = null_handler
#pragma weak otg_fs_isr = null_handler
