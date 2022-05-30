/*
** EPITECH PROJECT, 2021
** strace_tech2
** File description:
** epitech
*/

#include "../include/include.h"


void strace(char *name, struc_s *structu)
{
	struct user_regs_struct regs;
    int statue = 0;
    wait(&statue);
    while (!WIFEXITED(statue)) {
        if (ptrace(PTRACE_GETREGS, structu->pid, NULL, &regs) == -1) exit(84);
        if ((int) regs.orig_rax != -1)
            if (check(&regs))
                display(&regs, structu);
		ptrace(PTRACE_SINGLESTEP, structu->pid, NULL, NULL);
        wait(&statue);
    }
}

void error(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "--help") == 0) {
        printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        exit(0);
    }
    else if (ac != 3) {
        printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        exit(84);
    }
}

int main (int ac, char **av)
{
    struc_s *structu = malloc(sizeof(struc_s));
    error(ac, av);
    structu->pid = fork();
    structu->flag = 's';
    switch (structu->pid) {
        case -1:
            printf("Error pid\n");
            return (84);
        case 0:
            ptrace(PTRACE_TRACEME, 0, NULL, NULL);
            execvp(av[2], &av[2]);
        default :
            strace(av[1], structu);
    }
    return (0);
}
