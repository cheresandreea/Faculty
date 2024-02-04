bits 32

global start        

; declare extern functions used by the programme
extern exit, printf, scanf ; add printf and scanf as extern functions            
import exit msvcrt.dll    
import printf msvcrt.dll    ; tell the assembler that function printf is found in msvcrt.dll library
import scanf msvcrt.dll     ; similar for scanf
;Two natural numbers a and b (a, b: dword, defined in the data segment) are given.
;Calculate their sum and display the result in the following format:
; "<a> + <b> = <result>". Example: "1 + 2 = 3"
;The values will be displayed in decimal format (base 10) with sign.                          
segment data use32 class=data
	a dd 100       ; in this variable we'll store the value read from the keyboard
    b dd 25
    s dd 0
    format db "%d + %d = %d", 0
    
    
segment code use32 class=code
    start:
        mov eax, [s]
        add eax, [a]
        add eax, [b]
        mov [s], eax
        push dword [s]       ; ! addressa of a, not value
        push dword [b]
        push dword [a]
        push dword format
        call [printf]       ; call function scanf for reading
        add esp, 4 * 4     ; free parameters on the stack
                           ; 4 = size of a dword; 2 = no of perameters
        
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program