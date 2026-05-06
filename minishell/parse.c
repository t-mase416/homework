#include "minishell.h"
#include <string.h>

int	consume_pipe(t_token **token_list)
{
	t_token	*cur = *token_list;
	if (cur == NULL || cur->kind != TK_OPERATOR)
		return (0);
	if (ft_strncmp(cur->str, "|", cur->str_len) == 0 && cur->str_len == 1)
	{
		*token_list = cur->next;
		return (1);
	}
	return (0);
}

t_token	*consume_token(t_token **rest, t_token *token, t_TokenKind kind)
{
	if (!token || token->kind != kind)
		return (NULL);
	t_token *target = token;
	*rest = token->next;
	return (target);
}


char	**add_arg(char **args, char *new_str)
{
	int i = 0;
	char	**new_args;

	while (args && args[i])
	i++;
	new_args = malloc(sizeof(char *) * (i + 2));
	if (!new_args)
	return(NULL);
	int	j = 0;
	while (j < i)
	{
		new_args[j] = args[j];
		j++;
	}
	new_args[j] = strdup(new_str);
	new_args[j + 1] = NULL;
	free(args);
	return (new_args);
}

void	handle_redirect(t_cmd *cmd, t_token **token)
{
	t_token *op = *token;
	t_token	*file = op->next;

	if (!file || file->kind != TK_WORD)
	{
		printf("syntax error near redirection\n");
		return;
	}
	if (strcmp(op->str, ">") == 0 || strcmp(op->str, ">>") == 0)
	{
		if (cmd->filename_out)
		free(cmd->filename_out);
		cmd->filename_out = strdup(file->str);
		cmd->append_mode = (strcmp(op->str, "<<") == 0);
	}
	else if (strcmp(op->str, "<") == 0)
	{
		if (cmd->filename_in)
		free(cmd->filename_in);
		cmd->filename_in = strdup(file->str);
	}
	*token = file->next;
}


t_cmd	*parse_simple_command(t_token **rest, t_token *token)
{
	t_cmd	*cmd = calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	while (token && token->kind != TK_EOF)
	{
		if (token->kind == TK_WORD)
		{
			cmd->args = add_arg(cmd->args, token->str);
			token = token->next;
		}
		else if (token->kind == TK_OPERATOR)
		{
			if (strcmp(token->str, "|") == 0)
				break;
			handle_redirect(cmd, &token);
		}
	}
	*rest = token;
	return (cmd);
}

t_cmd	*parse_pipeline(t_token **token_list)
{
	t_cmd	*head_cmd;
	t_cmd	*cur_cmd;
	t_token	*cur_token = *token_list;

	head_cmd = parse_simple_command(&cur_token, cur_token);
	cur_cmd = head_cmd;
	while(cur_token && cur_token->kind == TK_OPERATOR &&
		strcmp(cur_token->str, "|") == 0)
		{
			cur_token = cur_token->next;
			cur_cmd->next = parse_simple_command(&cur_token, cur_token);
			cur_cmd = cur_cmd->next;
	}
	*token_list = cur_token;
	return (head_cmd);
}
