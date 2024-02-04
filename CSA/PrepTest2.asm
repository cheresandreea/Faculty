bits 32

global start        

extern exit, printf, scanf , fopen, fprintf, fclose, fread      
import exit msvcrt.dll    
import printf msvcrt.dll   
import scanf msvcrt.dll   
import fopen msvcrt.dll   
import fprintf msvcrt.dll 
import fclose msvcrt.dll 
import fread msvcrt.dll 

;Se da un fisier text, Sa se citeasca continutul fisierului, 
;sa se contorizeze numarul de cifre impare si sa se afiseze 
;aceasta valoare (Numele fisierului text este definit in segmentul 
;de date)

segment data use32 class=data
    file_name db "in.txt", 0
    access_mode db "w", 0
    file_descriptor dd -1
	n dd 0
    formatn db "%d", 0
    len equ 100
    sir times len db 0
    cont dd 0
        
segment code use32 class=code   
    start:
        ;fopen(nume_fisier, mod access)
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je sfarsit
        
        ;fread(string, size, len, file desc)
        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword sir
        call [fread]
        add esp, 4*4
        
        push eax
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4*1
        
        pop eax
        
        mov ecx, eax
        jecxz sfarsit
        cld
        mov esi, sir
        repeta:
            lodsb
            cmp al, '0'
            jb not_cifra
            cmp al, '9'
            jg not_cifra
            sub al, '0'
            test al, 0000_0001b
            jz e_par
            inc dword [cont]
            
            not_cifra:
            e_par:
         loop repeta
         
         push dword [cont]
         push dword formatn
         call [printf]
         add esp, 4*2
            
            
            
            
            
            
            
            
            
            
            
            
            
        
        sfarsit:
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program