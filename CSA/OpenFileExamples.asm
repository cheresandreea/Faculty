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
extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "an.txt", 0   ; filename to be created
    access_mode db "r", 0       ; file access mode:
    format db "%d", 0                       
    file_descriptor dd -1       ; variable to hold the file descriptor
    a_content db 0
    x db 0
;A text file is given. Read the content of the file, count the number 
;of even digits and display the result on the screen. The name of text file is defined in the data segment.
; our code starts here
segment code use32 class=code
    start:
        ; call fopen() to create the file
        ; fopen() will return a file descriptor in the EAX or 0 in case of error
        ; eax = fopen(file_name, access_mode)
        

        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        jz final
        mov [file_descriptor], eax
        mov ebx, 0
       
        loop1:
            push dword [file_descriptor]
            push dword 1
            push dword 1
            push dword a_content
            call [fread]
            add esp, 4*4
            cmp eax, 0
            jz final
            sub byte [a_content], '0'
            shr byte [a_content], 1
            jc nu_adauga
            add bx, 1
            nu_adauga:
        jmp loop1
        
        push dword bx
        push dword format
        call [printf]
        add esp, 4*2
        ; call fclose() to close the file
        ; fclose(file_descriptor)
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        final:
        push dword ebx
        push dword format
        call [printf]
        add esp, 4*2
        ; exit(0)
        push dword 0      
        call [exit]