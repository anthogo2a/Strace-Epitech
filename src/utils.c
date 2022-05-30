/*
** EPITECH PROJECT, 2021
** utils
** File description:
** for_dislpay
*/
#include "../include/include.h"

void choose(int i, size_t rax, struc_s *structu, struct user_regs_struct *regs, char sys)
{
    if (rax == structu->array[i])
        arg_print(sys, rax, structu);
}

int check(struct user_regs_struct *regs)
{
    if (regs->orig_rax > 328) {
        printf("Unknow\n");
        return 0;
    }
    return 1;
}

void display(struct user_regs_struct *regs, struc_s *structu)
{
    args(regs, structu);
}