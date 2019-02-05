null equ 0x00
MAXARGS equ 2
sys_exit equ 1
sys_read equ 3
sys_write equ 4
stdin equ 0
stdout equ 1
stderr equ 3

%macro print_char 1
  mov eax, 4
  mov ebx, stdout
  mov ecx, %1
  mov edx, 1
  int 0x80
%endmacro

%macro pushRegisters 0
  push eax
  push ebx
  push ecx
  push edx
%endmacro

%macro popRegisters 0
  pop edx
  pop ecx
  pop ebx
  pop eax
%endmacro

%macro exit0 0
  mov ebx, 0
  mov eax, sys_exit
  int 0x80
%endmacro

section .data
var1: db 0xff
var2: db 0xee
nl: db 0x0a, 0x0d
msg_EQ: db  ' is equal to ', 0x00
msg_lessThan: db ' is less than ', 0x00
msg_greaterThan: db  ' is greater than ', 0x00
msg_prompt1: db 'Please enter a digit: ', 0x00
msg_prompt2: db 'please enter a second digit: ', 0x00

section .text
  GLOBAL _start
  _start:
    mov edi, msg_prompt1
    call print_string
    mov eax, 3
    mov ebx, 2
    mov ecx, var1
    mov edx, 1
    int 0x80
    call print_nl

    mov edi, msg_prompt2
    call print_string
    mov eax, 3
    mov ebx, 2
    mov ecx, var2
    mov edx, 1
    int 0x80
    call print_nl

    print_char var1
    mov al, [var1]
    cmp al, byte [var2]
    
  je var1_eq_var2
  jl var1_le_var2
  jg var1_ge_var2
  
  var1_eq_var2:
    mov edi, msg_EQ
    call print_string
    print_char var2
    call print_nl
    jmp end_main
    
  var1_le_var2:
    mov edi, msg_lessThan
    call print_string
    print_char var2
    call print_nl
    jmp end_main
    
  var1_ge_var2:
    mov edi, msg_greaterThan
    call print_string
    print_char var2
    call print_nl
    jmp end_main
    
  jmp end_main
    end_main:
    exit0


print_nl:
  pushRegisters
  mov eax, 4
  mov ebx, 1
  mov ecx, nl
  mov edx, 2
  int 0x80
  popRegisters
  ret

print_string:
  pushRegisters
  mov ecx, edi
  checknull:
  cmp byte [ecx], null
  jz endstring
    print_char ecx
    inc ecx
    jmp checknull
  endstring:
  popRegisters
      ret