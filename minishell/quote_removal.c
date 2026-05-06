#include "minishell.h"

size_t	get_unquoted_len(char *str)
{
	size_t	i = 0;
	size_t	len = 0;
	char	quote = 0;

	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote - str[i++];
		else if
	}
}
