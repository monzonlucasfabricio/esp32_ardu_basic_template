SECTIONS
{
    /* Define tu sección personalizada en una ubicación específica dentro de la RAM */
    .my_section ALIGN(4) :
    {
        . = ALIGN(4);
        _my_section_start = .;
        KEEP(*(.my_section))
        . = ALIGN(4);
        _my_section_end = .;
    } > dram0_0_seg
    
    my_section_size = _my_section_end - _my_section_start;
    
    /* Asegura que el final de la sección .my_section esté alineado en 4 bytes */
    .my_section_end = ALIGN(4);
    . = ALIGN(4);
}