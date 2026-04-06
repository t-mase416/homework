#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>

# define SPECIAL_CHAR "&|<>()"

typedef enum s_TokenKind
{
	TK_WORD,
	TK_OPERATOR,
	TK_EOF
}	t_TokenKind;

typedef struct s_token
{
	char			*str;
	size_t			str_len;
	t_TokenKind		kind;
	struct s_token	*next;
}	t_token;

t_token	*tokenize(char *line);

#endif
