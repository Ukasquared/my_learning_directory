#include "main.h"

/**
 * create_env_list - creates env linked list
 * @info: Structure containing potential arguments
 *
 * Return: 0
 */
int create_env_list(info_t *info) // recieves the info struct as an argument
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0); // creates a linked list of environment variable
	info->env = node;						// stores the address of the existing environment linked list(address of the first node, which is the first struct) and is connected to subsequent nodes(self recalling structs).
	return (0);
}

/**
 * my_getenv - gets value of name
 * @name: key or name of environment variable
 *
 * Return: pointer to the value
 */
char *my_getenv(const char *name) // custom getenv that gets the environment variable using environ directly.
{
	char **env = environ;
	char *key_token = NULL;
	char *value_token = NULL;
	char *delim = "=";

	if (name == NULL)
	{
		fprintf(stderr, "No value passed to getenv()");
		return (NULL);
	}
	while (*env)
	{
		char *current_var = *env;
		char *copy = strdup(current_var);

		if (copy)
		{
			key_token = strtok(copy, delim);
			if (key_token && strcmp(key_token, name) == 0)
			{
				value_token = strtok(NULL, delim);
				if (value_token)
				{
					free(copy);
					return (value_token);
				}
			}
			free(copy);
		}
		env++;
	}
	fprintf(stderr, "Could not find %s in environment", name);
	return (NULL);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name) // here is also a getenv function that gets the environment variable using a custom created environment.
{
	list_t *node = info->env; // from the info struct we obtained the member (env.) which is the enviroment variable
	char *p;

	while (node) // while the first node(struct) is true
	{
		p = start_str(node->dir, name); // this compares the name argument to the start of the env variable (node->dir)
		if (p && *p)					// an extra error check if is not NULL and if the first character pointed to by p is not null byte
			return (p);					// returns p if true
		node = node->next;				// returns next node, if false
	}
	return (NULL);
}

/**
 * get_env - returns string array of our environment variables
 * @info: Structure containing potential arguments
 *
 * Return: 0
 */
char **get_env(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _setenv - sets a new environment variable or modifies existing one
 * @info: Structure containing potential arguments
 * @var: string environment variable property
 * @val: string environment variable value
 *
 *  Return: 0
 */
int _setenv(info_t *info, char *var, char *val)
{
	char *buffer = NULL;
	list_t *list;
	char *p;

	if (!var || !val)
		return (0);

	buffer = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, val);

	list = info->env;
	while (list)
	{
		p = start_str(list->dir, var);
		if (p && *p == '=')
		{
			free(list->dir);
			list->dir = buffer;
			info->env_changed = 1;
			return (0);
		}
		list = list->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;

	return (0);
}
