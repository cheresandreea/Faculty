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

;Two strings containing characters are given. Calculate and display the result of the concatenation 
;of all characters of type decimal number from the second string, and then followed by those from the 
;first string, and vice versa, the result of concatenating the characters from the first string after 
;those from the second string.

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    string1 db "a10bc", 0
    len_string1 db $-string1
    string2 db "de5f", 0
    len_string2 db $-string2
    result1 resb 256
    result2 resb 256
    
;A text file is given. Read the content of the file, count the number 
;of even digits and display the result on the screen. The name of text file is defined in the data segment.
; our code starts here
segment code use32 class=code
    start:
        ;
        mov edi, result1
        mov esi, string1
        mov ecx, len_string1
        loop1:
            lodsb
            cmp al, '0'
            jl next
            cmp dl, '9'
            jg next
            stosb 
            inc edi
        next:
            inc esi
            loop loop1
            
        loop loop1
        
        
        
        push dword 0      
        call [exit]