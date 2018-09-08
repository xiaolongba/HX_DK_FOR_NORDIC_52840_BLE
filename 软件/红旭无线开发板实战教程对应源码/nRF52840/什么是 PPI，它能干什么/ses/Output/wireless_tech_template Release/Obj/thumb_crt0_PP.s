# 1 "E:/Software Application/source/thumb_crt0.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "E:/Software Application/source/thumb_crt0.s"
# 91 "E:/Software Application/source/thumb_crt0.s"
  .syntax unified

  .global _start
  .extern main
  .global exit
  .weak exit


  .extern InitializeUserMemorySections


  .section .init, "ax"
  .code 16
  .balign 2
  .thumb_func

_start:

  ldr r1, =__stack_end__
  ldr r0, =__stack_start__
  subs r2, r1, r0
  beq 1f

  movs r2, #0x7
  bics r1, r2

  mov sp, r1





1:


  ldr r1, =__stack_process_end__
  ldr r0, =__stack_process_start__
  subs r2, r1, r0
  beq 1f

  movs r2, #0x7
  bics r1, r2

  msr psp, r1
  movs r2, #2
  msr control, r2




1:


  ldr r0, =__data_load_start__
  ldr r1, =__data_start__
  ldr r2, =__data_end__
  bl memory_copy
  ldr r0, =__text_load_start__
  ldr r1, =__text_start__
  ldr r2, =__text_end__
  bl memory_copy
  ldr r0, =__fast_load_start__
  ldr r1, =__fast_start__
  ldr r2, =__fast_end__
  bl memory_copy
  ldr r0, =__ctors_load_start__
  ldr r1, =__ctors_start__
  ldr r2, =__ctors_end__
  bl memory_copy
  ldr r0, =__dtors_load_start__
  ldr r1, =__dtors_start__
  ldr r2, =__dtors_end__
  bl memory_copy
  ldr r0, =__rodata_load_start__
  ldr r1, =__rodata_start__
  ldr r2, =__rodata_end__
  bl memory_copy
  ldr r0, =__tdata_load_start__
  ldr r1, =__tdata_start__
  ldr r2, =__tdata_end__
  bl memory_copy
# 202 "E:/Software Application/source/thumb_crt0.s"
  ldr r0, =__bss_start__
  ldr r1, =__bss_end__
  movs r2, #0
  bl memory_set
  ldr r0, =__tbss_start__
  ldr r1, =__tbss_end__
  movs r2, #0
  bl memory_set
# 224 "E:/Software Application/source/thumb_crt0.s"
  ldr r0, = __heap_start__
  ldr r1, = __heap_end__
  subs r1, r1, r0
  cmp r1, #8
  blt 1f
  movs r2, #0
  str r2, [r0]
  adds r0, r0, #4
  str r1, [r0]
1:


  ldr r2, =InitializeUserMemorySections
  blx r2



  ldr r0, =__ctors_start__
  ldr r1, =__ctors_end__
ctor_loop:
  cmp r0, r1
  beq ctor_end
  ldr r2, [r0]
  adds r0, #4
  push {r0-r1}
  blx r2
  pop {r0-r1}
  b ctor_loop
ctor_end:


  movs r0, #0
  mov lr, r0
  mov r12, sp

  .type start, function
start:
# 269 "E:/Software Application/source/thumb_crt0.s"
  movs r0, #0
  movs r1, #0

  ldr r2, =main
  blx r2

  .thumb_func
exit:
# 305 "E:/Software Application/source/thumb_crt0.s"
exit_loop:
  b exit_loop

  .thumb_func
memory_copy:
  cmp r0, r1
  beq 2f
  subs r2, r2, r1
  beq 2f
1:
  ldrb r3, [r0]
  adds r0, r0, #1
  strb r3, [r1]
  adds r1, r1, #1
  subs r2, r2, #1
  bne 1b
2:
  bx lr

  .thumb_func
memory_set:
  cmp r0, r1
  beq 1f
  strb r2, [r0]
  adds r0, r0, #1
  b memory_set
1:
  bx lr



.macro HELPER helper_name
  .section .text.\helper_name, "ax", %progbits
  .balign 2
  .global \helper_name
  .weak \helper_name
\helper_name:
  .thumb_func
.endm

.macro JUMPTO name







  b \name

.endm

HELPER __aeabi_read_tp
  ldr r0, =__tbss_start__-8
  bx lr
HELPER abort
  b .
HELPER __assert
  b .
HELPER __aeabi_assert
  b .
HELPER __sync_synchronize
  bx lr
HELPER __getchar
  JUMPTO debug_getchar
HELPER __putchar
  JUMPTO debug_putchar
HELPER __open
  JUMPTO debug_fopen
HELPER __close
  JUMPTO debug_fclose
HELPER __write
  mov r3, r0
  mov r0, r1
  movs r1, #1
  JUMPTO debug_fwrite
HELPER __read
  mov r3, r0
  mov r0, r1
  movs r1, #1
  JUMPTO debug_fread
HELPER __seek
  push {r4, lr}
  mov r4, r0
  bl debug_fseek
  cmp r0, #0
  bne 1f
  mov r0, r4
  bl debug_ftell
  pop {r4, pc}
1:
  ldr r0, =-1
  pop {r4, pc}

  .section .bss.__user_locale_name_buffer, "aw", %nobits
  .global __user_locale_name_buffer
  .weak __user_locale_name_buffer
  __user_locale_name_buffer:
  .word 0x0
# 412 "E:/Software Application/source/thumb_crt0.s"
  .section .stack, "wa", %nobits
  .section .stack_process, "wa", %nobits
  .section .heap, "wa", %nobits
