/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:52:54 by minabe            #+#    #+#             */
/*   Updated: 2022/06/15 00:21:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static void		sep_words(char **split, char *s, char c);
static char		**malloc_error(char **str);
static void		set_word(char *from, char *dest, char c);

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**res;

	n = count_words(s, c);
	res = malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (NULL);
	res[n] = NULL;
	sep_words(res, (char *)s, c);
	return (res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	sep_words(char **split, char *s, char c)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (*(s + i) != c && *(s + i))
				i++;
			split[n] = malloc(sizeof(char) * (i + 1));
			if (!split[n])
			{
				malloc_error(split);
				return ;
			}
			set_word(split[n], s, c);
			s += i;
			n++;
		}
	}
	return ;
}

static char	**malloc_error(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	set_word(char *dest, char *from, char c)
{
	size_t	i;

	i = 0;
	while (from[i] != c && from[i] != '\0')
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}
