/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

/* Generic linker script for STM32 targets using libopencm3. */

/* Memory regions must be defined in the ld script which includes this one. */

/* Enforce emmition of the vector table. */
EXTERN (vector_table)

/* Define the entry point of the output file. */
ENTRY(reset_handler)

/* The size of the stack used by the application. NOTE: you need to adjust  */
STACK_SIZE = 4096;

/* The size of the heap used by the application. NOTE: you need to adjust   */
HEAP_SIZE = 0;

/* Define sections. */
SECTIONS
{

	.text : {                                         /* code and constants */
		. = ALIGN(4);
		*(.vectors)		/* Vector table */
		*(.text)                                   /* .text sections (code) */
		*(.text*)                                 /* .text* sections (code) */
		*(.rodata)           /* .rodata sections (constants, strings, etc.) */
		*(.rodata*)         /* .rodata* sections (constants, strings, etc.) */

		KEEP (*(.init))
		KEEP (*(.fini))

		. = ALIGN(4);
		_etext = .;                        /* global symbols at end of code */
	} >rom

	.preinit_array : {
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array*))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	} >rom

	.init_array : {
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array*))
		PROVIDE_HIDDEN (__init_array_end = .);
	} >rom

	.fini_array : {
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP (*(.fini_array*))
		KEEP (*(SORT(.fini_array.*)))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} >rom


	.data : {
		__data_load = LOADADDR (.data);
		__data_start = .;
		_data = .;
		*(.data)                                          /* .data sections */
		*(.data*)                                        /* .data* sections */
		. = ALIGN(4);
		__data_end__ = .;
		_edata = __data_end__;
	} >ram AT>rom

	.bss : {
		__bss_start__ = . ;
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;                     /* define a global symbol at bss end */
		__bss_end__ = .;
	} >ram

	PROVIDE ( end = _ebss );
	PROVIDE ( _end = _ebss );
	PROVIDE ( __end__ = _ebss );

	.heap : {
		__heap_start__ = . ;
		. = . + HEAP_SIZE;
		. = ALIGN(4);
		__heap_end__ = . ;
	} >ram

	.stack : {
		__stack_start__ = . ;
		. = . + STACK_SIZE;
		. = ALIGN(4);
		__c_stack_top__ = . ;
		__stack_end__ = . ;
	} >ram

	PROVIDE(_stack = __stack_end__ );

	/*
	 * The .eh_frame section appears to be used for C++ exception handling.
	 * You may need to fix this if you're using C++.
	 */
	/DISCARD/ : { *(.eh_frame) }

	/*
	 * Another section used by C++ stuff, used for C++ exception handling ..
	 */
	/DISCARD/ : { *(.ARM.exidx) }

	/* Remove information from the standard libraries */
	/DISCARD/ : {
		*(.note.GNU-stack)
		libc.a ( * )
		libm.a ( * )
		libgcc.a ( * )
	}
}


