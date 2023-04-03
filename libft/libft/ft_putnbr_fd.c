/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:37 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/27 17:17:01 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	write_nbr(int dec, int fd)
{
	char	tmp;

	if (dec < 0)
	{
		write(fd, "-", 1);
		dec *= -1;
	}
	if (dec >= 10)
		write_nbr(dec / 10, fd);
	tmp = (dec % 10) + '0';
	write(fd, &tmp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	write_nbr(n, fd);
}
