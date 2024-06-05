MEMORY
{
    ram(RW) 	: ORIGIN = 0x7e900000, 	LENGTH = 0x80000
	/* flash(RWX) 	: ORIGIN = 0x6DB000, 	LENGTH = 0x40000 */
}


SECTIONS
{
	. = 0x7e900000;

	.appRegTable :
	{	
		;PROVIDE_HIDDEN (__appRegTable_start__ = .);
		KEEP(*(.appRegTable))
		;PROVIDE_HIDDEN (__appRegTable_end__ = .);
	} >ram
	.text : 
	{ 
	    *(.text) 
	} >ram
	.rodata : 
	{
	    *(.rodata)
	} >ram
	.data : 
	{
		PROVIDE_HIDDEN (__data_load = LOADADDR(.data));
		PROVIDE_HIDDEN (__data_start = .);
		*(.data)
		PROVIDE_HIDDEN (_edata = .);
	} >ram
	.ARM.exidx :
	{
		PROVIDE_HIDDEN (__exidx_start = .);
		*(.ARM.exidx);
		PROVIDE_HIDDEN (__exidx_end = .);
	} >ram
	.bss :
	{
		PROVIDE_HIDDEN (__bss_start__ = .);
		*(.bss)
		PROVIDE_HIDDEN (__bss_end__ = .);
	} >ram
	
	.preinit_array     :
	{
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array*))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	} >ram
	.init_array :
	{
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array*))
		PROVIDE_HIDDEN (__init_array_end = .);
	} >ram
	.fini_array :
	{
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP (*(SORT(.fini_array.*)))
		KEEP (*(.fini_array*))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} >ram

	end = 0x7e980000;

}