section .data
    SIZEOF_T_LIST equ 24
    SIZEOF_PTR equ 8
    SIZEOF_SIZE_T equ 8

    struc t_list
        .content:       resq 1
        .next:          resq 1
        .content_size   resq 1
    endstruc
