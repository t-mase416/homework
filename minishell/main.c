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
		printf("%u:%s\n", token->kind, token->str);
		token = token->next;
	}
}

void	test_parse(t_cmd *cmds)
{
	while (cmds)
	{
		int i = 0;
		while(cmds->args[i])
		{
			printf("%s\n", cmds->args[i]);
			i++;
		}
		cmds = cmds->next;
	}
}

void	free_all_token(t_token *token)
{
	t_token	*temp;

	while (token != NULL)
	{
		temp = token->next;
		if (token->str)
			free(token->str);
		free(token);
		token = temp;
	}
	return;
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
		t_token *token = tokenize(line);
		test_parse(parse_pipeline(&token));
	}
	exit(0);
}
