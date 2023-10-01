#include "main.h"

/**
 * rd_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int rd_history(info_t *info)
{
	int line_count = 0, last = 0, i;
	ssize_t fd, readlen, filesize = 0;
	char *filename = get_history(info), *buff = NULL;
	struct stat st_t;

	if (!filename) // checks if the filename is not NULL
		return (0);
	fd = open(filename, O_RDONLY); // the history file is opened
	free(filename);				   // the buffer is freed yet fd still maintains reference to file
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st_t))		 // fstat returns 0 if successful, therefore 0 is converted to truthy value
		filesize = st_t.st_size; // size of file in bytes
	if (filesize < 2)
		return (0);
	buff = malloc(sizeof(char) * (filesize + 1)); // allocates space for the read function
	if (!buff)
		return (0);
	readlen = read(fd, buff, filesize);
	buff[filesize] = 0;			// it terminates the file with the null byte
	if (readlen <= 0)			// if read returns 0 or less than 0
		return (free(buff), 0); // comma allows for multiple expression to be evaluated within single statement, it returns 0 finally
	close(fd);
	for (i = 0; i < filesize; i++) // loops through the filesize
		if (buff[i] == '\n')
		{													// the address of buff is not moved or changed
			buff[i] = 0;									// replacing "\n" with 0, set the current position "\n" to "\0", which effectively terminates the string
			build_history(info, buff + last, line_count++); // buff + last adds the value of last to the pointer to move the buff address forward
			last = i + 1;									// increment the last with the value of i + 1 to point buff to the new address
		}
	if (last != i) // means if the buff + last that was updated before the loop terminated has not been passed to buid_history, it will be passed.
		build_history(info, buff + last, line_count++);
	free(buff);
	info->histcount = line_count; // stores the number of times the build_history func. was called to account for the num of commands.
	while (info->histcount-- >= MAX_HISTORY)
		del_node_at_index(&(info->history), 0);
	renum_history(info);
	return (info->histcount);
}

/**
 * get_history - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME="); // takes the info struct and HOME env. as an argument
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2)); // this obtains the string length of dir and the HIST_FILE macro, allocates space for it and returns the address to the allocate space to buff.
	if (!buf)
		return (NULL);
	buf[0] = 0;				 // sets the first character of buf to NULL, effectively initializing it as an empty string
	_strcpy(buf, dir);		 // copies the HOME environment to buf
	_strcat(buf, "/");		 // concatenate "/" to the HOME environment
	_strcat(buf, HIST_FILE); // concatenates the history file to the HOME environment
	return (buf);			 // returns buf
}

/**
 * build_history - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	// for the first time info->history will be null because it was first initialized to null in the struct.
	if (info->history) // if its not null, the newnode is added at the end.
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renum_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renum_history(info_t *info)
{
	list_t *node = info->history;
	int i;

	i = 0;
	while (node)
	{
		node->num = i++; // re-numbers the nodes
		node = node->next;
	}

	return (info->histcount = i);
}

/**
 * wrt_history - creates and writes to file, or appends to existing file
 * @info: parameter struct
 *
 * Return: 1 when successful, and -1 otherwise
 */
int wrt_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->dir, fd);
		_putcharfd('\n', fd);
	}
	_putcharfd(BUFFER_FLUSH, fd);
	close(fd);
	return (1);
}
