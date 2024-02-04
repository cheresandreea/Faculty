bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fprintf, fclose, fscanf, printf            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll                         ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fread msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "input.txt", 0
    access_mode db "r", 0
    file_descriptor dd -1
    sir db 1Ah, 2Bh, 3Ch, 4Dh, 5Eh, 6Fh, 0
    format db '%x ', 0
    n dd 0
    s times len db 0
    len equ 10
    min db -1

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
        
        repeta:
            push dword [file_descriptor]
            push dword len
            push dword 1
            push dword s
            call [fread]
            add esp, 4*4
        
            mov ecx, eax
            mov esi, s
            repeta2:
                lodsb
                
                cmp al, ' '
                jne not_spatiu
                    mov al, [min]
                    stosb
                    mov byte [min], -1
                    jmp not_lower
                
                not_spatiu:
                cmp byte [min], -1
                jne minim_ex
                
                    mov [min], al
                minim_ex:
                cmp [min],al
                jnl not_lower
                    mov [min], al
                not_lower:
             loop repeta2
             cmp eax, len
             jl outside
            jmp repeta
            outside:
            
            
            afisare:
                        
                    
              
              
        
        cmp eax, len
        jl outside
        
        
        
        
        
        
        
        
        
        ;mov ecx, 10
        
        ; repeta:
            ; push ecx
            ; push dword n
            ; push dword format
            ; push dword [file_descriptor]
            ; call [fscanf]
            ; add esp, 4*3
        
        ; push dword [n]
        ; push dword format
        ; call [printf]
        ; add esp, 4*2
        
        ;pop ecx
        ;loop repeta
       
       
      
        outside:
            push dword [file_descriptor]
            call [fclose]
            add esp, 4
        
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
