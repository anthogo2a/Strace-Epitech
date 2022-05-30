/*
** EPITECH PROJECT, 2021
** include_strace
** File description:
** strace_tech2
*/

#ifndef tech2
#define tech2

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <elf.h>
#include <fcntl.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/user.h>
#include <sys/reg.h>

typedef struct
{
    FILE *file;
    char name[20];
    pid_t pid;
    size_t array[6];
    char flag;
}struc_s;

enum type {
	CHAR_STR,
    ARG,
	NOTHING
};


void strace(char *name, struc_s *structu);
void error(int ac, char **av);
int main (int ac, char **av);
int check_display(struct user_regs_struct regs, pid_t pid);
void display(struct user_regs_struct *regs, struc_s *structu);
char *name_file(unsigned long long rax, struc_s *structu);
int check(struct user_regs_struct *regs);
void arg_print(char sys, size_t rdi, struc_s *structu);
void put_arg(struct user_regs_struct *regs, struc_s *structu);
void args(struct user_regs_struct *regs, struc_s *structu);

#endif /* !tech2 */