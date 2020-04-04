#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct directories
{
	char *direct;
	struct directories *next;
};

struct directories *add_node_end(struct directories **head, const char *str);
void add_dir_to_struct(struct directories **head, char *directories);
char *_getenv(const char *name);
void print_dir_path(char *directories);
size_t print_list(const struct directories *h);

int main()
{
	struct directories *head;
	head = NULL;

	char *directories = _getenv("PATH");
	add_dir_to_struct(&head, directories);
	print_list(head);
	return (0);
}

char *_getenv(const char *name)
{
	extern char **environ;
	char *key;
	char *dup = strdup(name);
	char *value;
	char *token;

	for (size_t i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(dup, environ[i]) == 0)
		{
			key = token;
			token = strtok(NULL, "=");
			value = token;
			break;
		}
	}

	return (value);
}

void add_dir_to_struct(struct directories **head, char *directories)
{
	char *token = strtok(directories, ":");

	while (token != NULL)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}

struct directories *add_node_end(struct directories **head, const char *str)
{
	int len = 0;

	struct directories *new = malloc(sizeof(struct directories));
	struct directories *last = *head;

	if (!new)
		return (NULL);

	new->direct = strdup(str);

	while (str[len] != '\0')
		len++;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new;

	return (new);
}

size_t print_list(const struct directories *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->direct == NULL)
			printf("[0] (nil)\n");
		else
			printf("%s\n", h->direct);

		h = h->next;
		count++;
	}

	return (count);
}