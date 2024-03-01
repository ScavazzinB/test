/*
** EPITECH PROJECT, 2024
** test
** File description:
** seg.c
*/

#include "../include/my.h"


void handle_child_status(int sig)
{
    int status;
    int child_sig;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        if (WIFSIGNALED(status)) {
            child_sig = WTERMSIG(status);
            if (child_sig == SIGSEGV) {
                my_fprintf(stderr, "Child process %d terminated with segmentation fault\n", pid);
            }
            if (child_sig == SIGABRT) {
                my_fprintf(stderr, "Child process %d terminated with abort signal\n", pid);
            }
        }
    }
}

void setup_child_signal_handler(void)
{
    if (signal(SIGCHLD, handle_child_status) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }
}
