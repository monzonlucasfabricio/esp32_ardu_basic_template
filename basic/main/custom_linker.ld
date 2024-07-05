SECTIONS
{
    /* Define tu sección personalizada en una ubicación específica dentro de la RAM */
    .my_section :
    {
        . = ALIGN(4);
        _my_section_start = .;
		*(.my_section)
        . = ALIGN(4);
        _my_section_end = .;
    } > dram0_0_seg
}