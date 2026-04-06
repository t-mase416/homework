#include "minishell.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);

int is_space(char c)
{
    // スペース(' ')、タブ('\t')、改行('\n')などをチェック
    // 一般的なシェルではこれらが区切り文字となります
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

int is_special_char(char c)
{
    // SPECIAL_CHAR で定義された文字の中に c が含まれているかを確認
    if (c == '\0')
        return (0);
    return (ft_strchr(SPECIAL_CHAR, c) != NULL);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
}

t_token	*new_token(t_TokenKind kind, char *start, size_t len)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = (char *)malloc(sizeof(char) * (len + 1));
	if (!token->str)
	{
		free(token);
		return (NULL);
	}
	ft_strlcpy(token->str, start, len + 1);
	token->kind = kind;
	token->str_len = len;
	token->next = NULL;
	return (token);
}

size_t	get_operator_len(char *line)
{
	if (ft_strncmp(line, "<<", 2) == 0 || ft_strncmp(line, ">>", 2) == 0 ||
        ft_strncmp(line, "&&", 2) == 0 || ft_strncmp(line, "||", 2) == 0)
        return (2);
	return (1);
}

size_t	get_word_len(char *line)
{
	size_t	i = 0;
	char	quote;

	while(line[i] && !is_space(line[i]) && !ft_strchr(SPECIAL_CHAR, line[i]))
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				i++;
			if (line[i])
				i++;
		}
		else
			i++;
	}
	return (i);
}

t_token	*tokenize(char *line)
{
	t_token	head;
	t_token	*cur;
	int		len;

	head.next = NULL;
	cur = &head;
	while (*line)
	{
		while ((*line) && (*line == ' ' || *line == '\t'))
			line++;
		if (*line == '\0')
			break;
		if (is_special_char(*line))
		{
			len = get_operator_len(line);
			cur->next = new_token(TK_OPERATOR, line, len);
		}
		else
		{
			len = get_word_len(line);
			cur->next = new_token(TK_WORD, line, len);
		}
		cur = cur->next;
		line += len;
	}
	cur->next = new_token(TK_EOF, line, 0);
	return (head.next);
}
