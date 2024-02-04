bits 32

global start        

; declare extern functions used by the programme
extern exit, fopen, fclose, fread         
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll

segment data use32 class=data
    file_name db "test.txt", 0
    access_mode db "r", 0
    file_descriptor dd -1
    len equ 100 
           
segment code use32 class=code   
    start:
        push dword access_mode
        push dword file_descriptor
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je final
        
        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        
     final:
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program