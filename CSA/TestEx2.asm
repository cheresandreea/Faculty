bits 32

global start        

extern exit, printf, scanf          
import exit msvcrt.dll    
import printf msvcrt.dll   
import scanf msvcrt.dll     

segment data use32 class=data
	a dd 0
    b dd 0
    c dd 0
	message1  db "a=", 0  
    message2  db "b=", 0
    formati db "%d", 0
    formatf db "%d + %d = %d", 0
    
        
segment code use32 class=code   
    start:
        
        push dword message1
        call [printf]
        add esp, 4*1
        
        push dword a
        push dword formati
        call [scanf]
        add esp, 4*2
        
        push dword message2
        call [printf]
        add esp, 4*1
        
        push dword b
        push dword formati
        call [scanf]
        add esp, 4*2
        
        mov eax, [a]
        add eax, [b]
        mov [c], eax
        
        push dword [c]
        push dword [b]
        push dword [a]
        push dword formatf
        call [printf]
        add esp, 4*4
        
        
  
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program