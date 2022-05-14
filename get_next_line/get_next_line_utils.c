/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:45:25 by acouliba          #+#    #+#             */
/*   Updated: 2021/11/17 17:01:33 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_subst_gnlr(char const *s, int start, int len, char **temp)
{
	int		i;
	char	*str;
	int		len_str;

	if (temp != NULL)
	{
		free(temp[0]);
		temp[0] = NULL;
	}
	if (s == NULL || len == 0)
		return (NULL);
	len_str = ft_strlen_gnl(s);
	i = 0;
	while (s[start + i])
		i++;
	if (len > i)
		len = i;
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < (len) && start < len_str)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_strchar(char *haystack, char c, int len)
{
	int		i;

	i = 0;
	if (len == -1)
	{
		while (haystack[i])
		{
			if (haystack[i] == c)
				break ;
			i++;
		}
		if (c == haystack[i])
			return (i);
		return (-1);
	}
	while (haystack[i] && i < len)
	{
		if (haystack[i] == c)
			break ;
		i++;
	}
	if (c == haystack[i])
		return (i);
	return (-1);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, int end, char **temp)
{
	char	*str;
	int		i;
	int		a;

	if (temp != NULL)
	{
		free(temp[0]);
		temp[0] = NULL;
	}
	str = malloc ((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	a = 0;
	if (s1 != NULL)
		while (s1[i] != '\0')
			str[a++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && i < end)
		str[a++] = s2[i++];
	str[a] = '\0';
	free((void *)s1);
	return (str);
}
