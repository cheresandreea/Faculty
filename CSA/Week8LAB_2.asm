; The code below will print message ”n=”, then will read from keyboard the value of perameter n.
bits 32

global start        

; declare extern functions used by the programme
extern exit, printf, scanf ; add printf and scanf as extern functions            
import exit msvcrt.dll    
import printf msvcrt.dll    ; tell the assembler that function printf is found in msvcrt.dll library
import scanf msvcrt.dll     ; similar for scanf

;Read a decimal number and a hexadecimal number from the keyboard. 
;Display the number of 1's of the sum of the two numbers in decimal format. Example:
;a = 32 = 0010 0000b
;b = 1Ah = 0001 1010b
;32 + 1Ah = 0011 1010b
;The value printed on the screen will be 4  
         
segment data use32 class=data
	a dd 0
    b dd 0
    x dd 0
    format1 db "%d", 0
    format2 db "%x", 0
    
segment code use32 class=code
    start:
        push dword a
        push dword format1
        call [scanf]
        add esp, 4*2
        push dword b
        push dword format2
        call [scanf]
        add esp, 4*2
        mov eax, [a]
        add eax, [b]
        mov ecx, 32
        loop1:
            rol eax, 1
            adc byte [x], 0
        loop loop1
        push dword [x]
        push dword format1
        call [printf]
        add esp, 4*2
        
       
        
           
        
        
        
        ; exit(0)
        push dword 0      ; place on stack parameter for exit
        call [exit]       ; call exit to terminate the program