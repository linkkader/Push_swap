/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:00:18 by acouliba          #+#    #+#             */
/*   Updated: 2021/11/17 17:10:53 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest(char *temp)
{
	char	*str;
	int		i;
	int		r;

	r = ft_strlen_gnl(temp);
	i = 0;
	str = malloc((r + 1) * sizeof (char));
	if (str == NULL)
		return (NULL);
	while (temp[i] != '\0')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*substr(char **str, int start)
{
	int		i;
	char	*s;

	i = start;
	while (str[0][i])
		i++;
	s = malloc((i - start + 1) * sizeof (char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[0][start])
		s[i++] = str[0][start++];
	s[i] = '\0';
	free(*str);
	return (s);
}

int	check(char **str, char	**temp, int fd)
{
	int		tempr;

	str[0] = NULL;
	if (*temp != NULL)
	{
		tempr = ft_strchar(*temp, '\n', -1);
		if (tempr >= 0)
		{
			*str = ft_strjoin_gnl(*str, *temp, tempr + 1, NULL);
			*temp = substr(temp, tempr + 1);
			return (1);
		}
		if (ft_strlen_gnl(*temp) == 0)
		{
			free(*temp);
			*temp = NULL;
			return (0);
		}
		str[0] = rest(*temp);
		free(*temp);
		*temp = NULL;
	}
	if (fd < 0 || fd >= OPEN_MAX)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*temp = NULL;
	int			r;
	char		buff[BUFFER_SIZE + 1];
	int			tempr;

	if (check(&str, &temp, fd))
		return (str);
	r = read(fd, &buff, BUFFER_SIZE);
	while (r > 0)
	{
		tempr = ft_strchar(buff, '\n', r);
		if (r == BUFFER_SIZE && tempr == -1)
			str = ft_strjoin_gnl(str, buff, r, &temp);
		else if (tempr >= 0)
		{
			r = r - tempr - 1;
			temp = ft_subst_gnlr(buff, tempr + 1, r, &temp);
			return (ft_strjoin_gnl(str, buff, tempr + 1, NULL));
		}
		else
			return (ft_strjoin_gnl(str, buff, r, &temp));
		r = read(fd, &buff, BUFFER_SIZE);
	}
	return (str);
}
/*
int main()
{
    int fd = open("kader.txt",O_CREAT);
    printf("%d\n", fd);
    char *str1 = get_next_line(fd);
    printf("%s", str1);
    int i = 1;
    while (str1 != NULL)
    {
        //if (BUFFER_SIZE == 42)
          ///  printf("yo mec\n");
        printf("line %d\t%s",i, str1);
        str1 = get_next_line(fd);
        i++;
    }
    printf("||||||||last %s\n", str1);
    return 1;
}*/