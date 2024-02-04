bits 32

global start        

; declare extern functions used by the programme
extern exit, fopen, fclose, fprintf         
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    file_name db "test.txt", 0
    access_mode db "w", 0
    file_descriptor dd -1
    text db "Ana are mere.", 0
           
segment code use32 class=code   
    start:
        push dword access_mode
        push dword file_descriptor
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je final
        
        push dword text
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4*2
        
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        
     final:
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program