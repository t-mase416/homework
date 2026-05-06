#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>


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

typedef struct	s_cmd
{
	char			**args;
	char			*filename_in;
	char			*filename_out;
	int				append_mode;
	struct s_cmd	*next;
}	t_cmd;

t_token	*tokenize(char *line);
t_cmd	*parse_pipeline(t_token **token_list);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
