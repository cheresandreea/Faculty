bits 32

global start        

; declare extern functions used by the programme
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
    format db "%d", 0
    
        
segment code use32 class=code   
    start:
        
        push dword message1
        call [printf]
        add esp, 4*1
        
        
        push dword a
        push dword format
        call [scanf]
        add esp, 4*2
        
        push dword [a]
        push dword format
        call [printf]
        add esp, 4*2
        
        
  
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program