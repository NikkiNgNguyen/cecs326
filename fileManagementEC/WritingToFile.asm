section .data
	file_name	db 'myfile.txt', 0
	fn_len			equ $ - file_name
	msg			db 'Welcome to Tutorials Point'
	msg_len			equ $ - msg
	msg_done	db 'Written to file:', 0x9
	len_done	equ $ - msg_done
	cr	db 0x0a

section .bss
	fd_out	resb 1
	fd_in		resb 1
	info		resb 30

section .text
	global _start	;must be declared for using gcc
	_start:		;tell linker entry point
;create the file
	mov eax, 8
	mov ebx, file_name
	mov ecx, 0o666		; read and write by all
	mov edx, fn_len 
	int 0x80				; call kernel
	mov [fd_out], al	; filedescriptor is returned in the A register
	
; write into the file
	mov edx,msg_len			; number of bytes
	mov ecx, msg		; message to write
	mov ebx, [fd_out]	; file descriptor of the created file
	mov eax,4			; system call number (sys_write)
	int 0x80				; call kernel
	
; close the file
	mov eax, 6
	mov ebx, [fd_out]
	int 0x80
	
; announce that the file has been written to
	mov eax, 4
	mov ebx, 1
	mov ecx, msg_done
	mov edx, len_done
	int 0x80
	
;open the file for reading
	mov eax, 5
	mov ebx, file_name
	mov ecx, 0			;for read only access
	mov edx, 0o666		;read, write and execute by all
	int 0x80
	mov [fd_in], eax
	
;read from file
	mov eax, 3
	mov ebx, [fd_in]
	mov ecx, info
	mov edx, 26
	int 0x80
	
; close the file
	mov eax, 6
	mov ebx, [fd_in]
	int 0x80
	
; print the info
	mov eax, 4
	mov ebx, 1
	mov ecx, info
	mov edx, 26
	int 0x80
	
; write into the file
	mov edx,1			; number of bytes
	mov ecx, cr		; message to write
	mov ebx, 1	; file descriptor of the created file
	mov eax,4			; system call number (sys_write)
	int 0x80				; call kernel

; terminate program execution	
	mov eax,1			;system call number (sys_exit)
	int 0x80			;call kernel

