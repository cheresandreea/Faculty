bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fclose, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;Se da in data segment numele unui fisier. Acesta contine cifre separate prin spatiu 
    ;(cifrele sunt din multimea cifrelor bazei 16 separate).
    ;Sa se afiseze prima si ultima cifra para din fisier si numarul de biti 1 din reprezentarea binara a acesteia.
    file_name db "test.txt", 0
    access_mode db "r", 0
    file_descriptor dd -1
    format db "%x", 0
    cifra db 0
    len equ 100
    sir times len db 0
    okcif db 0
    prima db 0
    ultima db 0
    format2 db "c", 0

; our code starts here
segment code use32 class=code
    start:
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0 
        je final
        
        ;int fread(void * str, int size, int count, FILE * stream)
      
        push dword [file_descriptor]
        push dword len
        push dword 1
        push dword sir
        call [fread]
        add esp, 4*4
        
        cld
        mov esi, sir
        
        repeta:
            lodsb
            ;cifra para
            cmp byte [cifra], '9'
            ja litera
            
            sub byte [cifra], '0'
            test byte [cifra], 0000_0001b
            jne impar
            cmp byte [okcif], 1
            je afisare
            mov byte [okcif], 1
            mov byte [prima], al
            mov byte [ultima], al
            impar:
            litera:
            sub byte [cifra], 'a'
            test byte [cifra], 0000_0001b
            jne impar
           
        loop repeta
        
        
        
        
        
        
        afisare:
        push dword [prima]
        push dword format2
        call [printf]
        add esp, 4*2
        
        
        push dword[file_descriptor]
        call [fclose]
        add esp, 4*1
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
