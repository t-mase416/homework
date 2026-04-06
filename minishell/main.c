#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

void	test_token(t_token *token)
{
	while (token->kind != TK_EOF)
	{
		printf("%s\n", token->str);
		token = token->next;
	}
}

int main(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break;
		if (*line)
			add_history(line);
		test_token(tokenize(line));
		free(line);
	}
	exit(0);
}
