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

// t_cmd	*parse_simple_command(t_token	*token)
// {
// 	t_cmd	*cmd;
// 	int		i;
// 	t_token	*t;
// 	t_token	*tmp;
// 	int		count;

// 	cmd	= malloc(sizeof(t_cmd));
// 	if (!cmd)
// 		return (NULL);
// 	count = 0;
// 	tmp = token;
// 	while (tmp && tmp->kind == TK_WORD)
// 	{
// 		count++;
// 		tmp = tmp->next;
// 	}
// 	cmd->args = malloc(sizeof(char *) * (count + 1));
// 	if (!cmd->args)
// 		return (NULL);
// 	i = 0;
// 	while ((t = consume_token(&token, token, TK_WORD)))
// 	{
// 		cmd->args[i] = strdup(t->str);
// 		i++;
// 	}
// 	cmd->args[i] = NULL;
// 	cmd->next = NULL;
// 	return (cmd);
// }

t_cmd	*parse_simple_command(t_token **rest, t_token *token)
{
	t_cmd	*cmd;
	int		count = 0;
	t_token	*tmp = token;

	while (tmp && tmp->kind == TK_WORD)
	{
		count++;
		tmp = tmp->next;
	}
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = malloc(sizeof(char *) * (count + 1));
	if (!cmd->args)
		return (NULL);
	int	i = 0;
	while (token && token->kind == TK_WORD)
	{
		cmd->args[i++] = strdup(token->str);
		token = token->next;
	}
	cmd->args[i] = NULL;
	cmd->next = NULL;
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
		ft_strncmp(cur_token->str, "|", 1) == 0)
	{
		cur_token = cur_token->next;
		cur_cmd->next = parse_simple_command(&cur_token, cur_token);
		cur_cmd = cur_cmd->next;
	}
	*token_list = cur_token;
	return (head_cmd);
}
