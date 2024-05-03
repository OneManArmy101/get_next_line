/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:54:57 by almarti3          #+#    #+#             */
/*   Updated: 2024/05/01 14:54:59 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(char *s);


char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*update_str(int sz_s1, int sz_s2, char const *s1, char const *s2)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc (sz_s1 + sz_s2 + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < sz_s1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < sz_s1 + sz_s2)
	{
		new_str[i] = s2[i - sz_s1];
		i++;
	}
	return (new_str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*new_str;

	size_s1 = 0;
	size_s2 = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char)); // he quitado (char *) delante del malloc, si da problemas reponer
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	while (s1[size_s1] != '\0')
		size_s1++;
	while (s2[size_s2] != '\0')
		size_s2++;
	new_str = update_str(size_s1, size_s2, s1, s2);
	if (new_str == NULL)
		return (NULL);
	new_str[size_s1 + size_s2] = '\0';
	free(s1);
	return (new_str);
}