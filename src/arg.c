/*
** EPITECH PROJECT, 2021
** utils
** File description:
** for_dislpay
*/
#include "../include/include.h"
#include "../include/syscall.h"

void arg_print(char sys, size_t rdi, struc_s *structu)
{
    if (sys == CHAR_STR)
        printf("\"\"");
    else if (sys != NOTHING)
        printf("%1d", rdi);
}

void put_arg(struct user_regs_struct *regs, struc_s *structu)
{
    for (int i = 0; i < my_syscall[regs->orig_rax].nb; i++) {
        choose(i, regs->rdi, structu, regs, my_syscall[regs->orig_rax].ag1);
        choose(i, regs->rsi, structu, regs, my_syscall[regs->orig_rax].ag2);
        choose(i, regs->rdx, structu, regs, my_syscall[regs->orig_rax].ag3);
        choose(i, regs->rcx, structu, regs, my_syscall[regs->orig_rax].ag4);
        choose(i, regs->r8, structu, regs, my_syscall[regs->orig_rax].ag5);
        choose(i, regs->r9, structu, regs, my_syscall[regs->orig_rax].ag6);
        if (i != my_syscall[regs->orig_rax].nb - 1) printf(", ");
    }
}

void args(struct user_regs_struct *regs, struc_s *structu)
{
    structu->array[0] = regs->rdi;
    structu->array[1] = regs->rsi;
    structu->array[2] = regs->rdx;
    structu->array[3] = regs->rcx;
    structu->array[4] = regs->r8;
    structu->array[5] = regs->r9;
    printf("%s(", my_syscall[regs->orig_rax].str);
    put_arg(regs, structu);
    printf(") = ");
    if (regs->orig_rax == 162 || regs->orig_rax == 231)
        printf("?\n");
    else if (structu->flag == 's')
        printf("%11d\n", regs->rax);
    else
        printf("0x%11x\n", regs->rax);
}