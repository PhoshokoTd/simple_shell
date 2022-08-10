#include "main.h"

/**
 * test_path - checks whether path is valid
 * @path: tokenized path
 * @command: user entered command
 * Return: path appended with command on success
 * NULL on failure
 */
char *test_path(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = append_path(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}

/**
 * find_path - finds the path from the global enviroment
 * Return: NULL if path is not found or path if path is found.
 */
char *find_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
