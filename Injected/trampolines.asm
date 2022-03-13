PUBLIC game_time_hook_trampoline

push_volatile MACRO
pushf
push   rax
push   rbx
push   rcx
push   rdx
push   r8
push   r9
push   r10
push   r11
ENDM

pop_volatile MACRO
pop    r11
pop    r10
pop    r9
pop    r8
pop    rdx
pop    rcx
pop    rbx
pop    rax
popf
ENDM

fill_hook_data MACRO
push r9
push r8
push rdi
push rsi
push rdx
push rcx
push rbx
push rax
mov rdx, rsp
ENDM

clean_up_hook_data MACRO
add rsp, 040h
ENDM

.data

extrn HookManagerServiceHook : proc

.code

game_time_hook_trampoline PROC

push_volatile

fill_hook_data
mov rcx, 1 ; service hook #1 game time
sub rsp, 020h
call HookManagerServiceHook
add rsp, 020h
clean_up_hook_data

pop_volatile

; Original code
mov rcx, rax
add qword ptr [rbx + 60h], rax
inc dword ptr [rbx + 70h]
movsxd rax, dword ptr [rbx + 0C8h]

; Then return back to the original code
; We can `ret` as long as the calling
; code used a `call` to get here

ret

game_time_hook_trampoline ENDP

session_tick_hook_trampoline PROC
; Get the return address into rax
pop rax

; Original code
mov [rsp + 8h], rbx
push rbp
push rsi
push rdi
push r12
push r13
push r14
push r15

push_volatile

fill_hook_data
mov rcx, 2 ; service hook #2 session tick hook
sub rsp, 020h
call HookManagerServiceHook
add rsp, 020h
clean_up_hook_data

pop_volatile

; push the return 
push rax
ret
session_tick_hook_trampoline ENDP

get_area_from_tls PROC
; Copied directly from some anno
; code that seems to extract the area object from
; tls
push rbx
push rcx
mov rax, gs:[58h]
mov ebx, 1530h
mov rcx, [rax]
mov rbx, [rbx + rcx]
mov rax, rbx
pop rcx
pop rbx
ret
get_area_from_tls ENDP

END