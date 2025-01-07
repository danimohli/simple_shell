#include "shell.h"

/**
 * execute_command - Executes a command by searching for its path.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
    char *cmd_path = find_executable(command);
    if (!cmd_path)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return;
    }
    fork_and_execute(cmd_path, command);
    free(cmd_path);
}

/**
 * fork_and_execute - Forks a process and executes the command.
 * @cmd_path: The full path to the command.
 * @command: The original command entered by the user.
 */
void fork_and_execute(char *cmd_path, char *command)
{
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        perror("fork");
        return;
    }
    if (pid == 0)
    {
        char *argv[] = {command, NULL};
        if (execve(cmd_path, argv, environ) == -1)
            perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
