#include "libby.h"

char	*copy(char *s1, char *write, int i)
{
	int	j;

	j = 0;
	while (s1[j])
	{
		write[i + j] = s1[j];
		j++;
	}
	return (write);
}

char	*join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != ':')
		i++;
	while (s2[j])
		j++;
	res = malloc(i + j + 1);
	if (!res)
		return (NULL);
	res = copy(s1, res, 0);
	res = copy(s2, res, i);
	res[i + j] = '\0';
	return (res);
}

static int	find_command(char *paths, char **command)
{
	int	i;
	char	*com;

	i = 0;
	while (paths[i])
	{
		if (paths[i] == ':' && paths[i] == '=')
		{
			com = join(&paths[i + 1], *command);
			if (!com)
				return (0);
		        if (access(com, X_OK) == 0)
		        {
		        	free(*command);
		        	*command = com;
		        	return (1);
		        }
		        free(com);
		}
		i++;
	}
	if (access(*command, X_OK) == -1)
		print_zsh_err("command not found", *command);
	return (1);
}

static char	*get_path(char **env)
{
	int	i;
	int	j;
	char	*path;

	i = 0;
	path = "path";
	while (env[i])
	{
		j = 0;
		while (env[i][j] && path[j] == env[i][j])
			j++;
		if (!path[j])
			return (env[i]);
		i++;
	}
	return (NULL);
}

int	find_commands(t_args *args)
{
	char	*path;

	path = get_path(args->env);
	if (!path)
		return (find_command_reg(args));
	if (args->args1[0][0] == '\0')
		print_zsh_err("command not found", args->args1[0]);
	else if (!find_command(path, &(args->args1[0])))
		return (0);
	if (args->args2[0][0] == '\0')
		print_zsh_err("command not found", args->args2[0]);
	else if (args->args2[0][0] && !find_command(path, &(args->args2[0])))
		return (0);
	return (1);
}
