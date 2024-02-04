; The following code will create an empty file called "ana.txt" in the current folder.

; The program will use:
; - the function fopen() to open/create the file
; - the function fclose() to close the created file.

; Because the program uses the file access mode "w", if a file with the same name already
; exists, its contents will be discarded and the file will be treated as a new empty file.
; For details about the file access modes see the section "Theory".

bits 32

global start

; declare external functions needed by our program
extern exit, fopen, fclose, fread
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll

;• A text file is given. The text contains letters, spaces and points. 
;Read the content of the file, determine the number of words and display 
;the result on the screen. (A word is a sequence of characters separated by space or point)

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file db "Week8.3.txt", 0
    access_mode db "r", 0
    descriptor dd -1
    len equ 100
    text times len db 0

; our code starts here
segment code use32 class=code
    start:
        ; call fopen() to create the file
        ; fopen() will return a file descriptor in the EAX or 0 in case of error
        ; eax = fopen(file_name, access_mode)
        push dword access_mode
        Push dword file
        Call [fopen]
        Add esp, 4*2
        Mov [descriptor], eax
        Cmp eax, 0
        Je final
        mov bx, 0
        loop1:
            Push dword [descriptor]
            Push dword 1
            Push dword 1
            Push dword text
            Call [fread]
            Add esp, 4*4
            Cmp eax, 0
            Je final
            Cmp byte [text], " "
            Jz creste
            cmp byte [text], "."
            jz creste
            jmp loop1
        creste:
            add bx, 1
            jmp loop1

        final:
        Push dword [descriptor]
        Call [fclose]
        Add esp, 4*1
            
        
   
        Push dword 0
                
                ; exit(0)
                push dword 0      
                call [exit]