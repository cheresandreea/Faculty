bits 32 ;assembling for the 32 bits architecture
global start
;Two byte strings S1 and S2 are given. Obtain the 
;string D by concatenating the elements of S1 from 
;the left hand side to the right hand side and the 
;elements of S2 from the right hand side to the left hand side.


; we ask the assembler to give global visibility to the symbol called start 
;(the start label will be the entry point in the program) 
extern exit ; we inform the assembler that the exit symbol is foreign; it exists even if we won't be defining it
import exit msvcrt.dll  ; we specify the external library that defines the symbol
        ; msvcrt.dll contains exit, printf and all the other important C-runtime functions

; our variables are declared here (the segment is called data) 
segment data use32 class=data
; ... 
s1 db 1, 2, 3, 4
l1 equ $ - s1
s2 db 5, 6, 7
l2 equ $ - s2
s3 resb l1 + l2

; the program code will be part of a segment called code
segment code use32 class=code
start:
; ... 
;unsigned
    mov ecx, l1
    mov esi, 0
    jecxz sf
    repeta:
        mov al, [s1+esi] ;al = '01'
        mov [s3+esi], al
        inc esi
    loop repeta
    sf
 
    mov ecx, l2
    jecxz sf1

    executa:
        mov al, [s2+ecx-1]
        mov [s3+esi], al
        inc esi 
    loop executa
    sf1
    

    ; call exit(0) ), 0 represents status code: SUCCESS
    push dword 0 ; saves on stack the parameter of the function exit
    call [exit] ; function exit is called in order to end the execution of
    
    
    