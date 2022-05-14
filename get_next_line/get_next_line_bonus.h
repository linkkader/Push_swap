/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:54:39 by acouliba          #+#    #+#             */
/*   Updated: 2022/05/14 18:54:41 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:55:03 by acouliba          #+#    #+#             */
/*   Updated: 2021/11/17 20:11:45 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# define GET_NEXT_LINE_BONUS_H

int		ft_strlen_gnl(const char *s);
char	*ft_subst_gnlr(char const *s, int start, int len, char **temp);
int		ft_strchar(char *haystack, char c, int len);
char	*ft_strjoin_gnl(char const *s1, char const *s2, int end, char **temp);
char	*get_next_line(int fd);

#endif
