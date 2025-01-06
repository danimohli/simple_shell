#include "header.h"

char **get_path_directories(void)
{
	char *path_env = getenv("PATH");
	char **path_list = NULL;
	int i = 0;

	if (!path_env)
		return (NULL);

	path_list = malloc(sizeof(char *) * 1024); /* Adjust as needed */
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

char *find_executable(char *command)
{
	char **dirs = get_path_directories();
	char *full_path = NULL;

	if (!dirs)
		return (NULL);

	for (int i = 0; dirs[i]; i++)
	{
		full_path = join_path(dirs[i], command);
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

char *join_path(char *dir, char *command)
{
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);
	if (!full_path)
		return (NULL);

	sprintf(full_path, "%s/%s", dir, command);
	return (full_path);
}

void free_path_list(char **path_list)
{
	if (!path_list)
		return;
	for (int i = 0; path_list[i]; i++)
		free(path_list[i]);
	free(path_list);
}

void path_error(char *command)
{
	fprintf(stderr, "Error finding %s in PATH\n", command);
}
