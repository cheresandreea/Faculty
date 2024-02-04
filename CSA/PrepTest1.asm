bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
   import scanf msvcrt.dll                       ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    ;Sa se citeasca de la tastatura un numar n, apoi sa se citeasca mai multe cuvinte,
    ;pana cand se citeste cuvantul/caracterul "#". Sa se scrie intr-un fisier text toate
    ;cuvintele citite care incep si se termina cu aceeasi litera si au cel putin n litere.
    n dd 0
    l db 0
    file_name db "test1.txt", 0
    file_descriptor dd -1 
    access_mode db "r", 0
    format db "%c", 0
    prima db 0
    okpl db 0
   
; our code starts here
segment code use32 class=code
    start:
        ;citire numar si numere
        push dword n
        push dword format
        call [scanf]

        repeta: 
            
            push dword l
            push dword format
            cmp okpl, 0
            je 
            
            call [scanf]
            mov eax, [l]
            cmp byte [l], '#'
            je final
            
            
        loop repeta
        final:
        
        
        
        
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
