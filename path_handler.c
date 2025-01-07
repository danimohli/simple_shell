/* path_handler.c */
#include "shell.h"

/**
 * get_path_directories - Retrieves directories in the PATH environment variable.
 *
 * Return: A NULL-terminated array of directory strings, or NULL on failure.
 */
char **get_path_directories(void)
{
    char *path_env = getenv("PATH");
    char **path_list = NULL;
    int i = 0;

    if (!path_env)
        return (NULL);

    path_list = malloc(sizeof(char *) * 1024);
    if (!path_list)
        return (NULL);

    char *dir = strtok(path_env, ":");
    while (dir)
    {
        path_list[i++] = strdup(dir);
        dir = strtok(NULL, ":");
    }
    path_list[i] = NULL;
    return (path_list);
}

/**
 * find_executable - Finds the full path of a command in the PATH directories.
 * @command: The command to locate.
 *
 * Return: The full path to the executable, or NULL if not found.
 */
char *find_executable(char *command)
{
    char **dirs = get_path_directories();
    char *full_path = NULL;

    if (!dirs)
        return (NULL);

    for (int i = 0; dirs[i]; i++)
    {
        full_path = malloc(strlen(dirs[i]) + strlen(command) + 2);
        if (!full_path)
            continue;

        sprintf(full_path, "%s/%s", dirs[i], command);
        if (access(full_path, X_OK) == 0)
        {
            free_path_list(dirs);
            return (full_path);
        }
        free(full_path);
    }
    free_path_list(dirs);
    return (NULL);
}

/**
 * free_path_list - Frees a NULL-terminated array of strings.
 * @path_list: The array to free.
 */
void free_path_list(char **path_list)
{
    if (!path_list)
        return;
    for (int i = 0; path_list[i]; i++)
        free(path_list[i]);
    free(path_list);
}
