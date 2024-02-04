 bits 32
 
 global start
 extern exit
 import exit msvcrt.dll
 
 segment data use32 class = data
    s db 1, 2, 3, 4
    l equ $-s
    d resb l-1

 segment code use32 class = code
    start:
        mov ecx, l-1
        mov esi, 0
        jecxz sfarsit
        repeta:
            mov al, [s+esi]
            mul byte [s+esi+1]
            mov [d+esi], al
            inc esi
        loop repeta
        sfarsit:
            push dword 0
            call [exit]