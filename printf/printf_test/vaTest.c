/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaTest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:50:36 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/02 17:36:17 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<unistd.h>
#include<stdint.h>
#include<stdio.h>

void	my_varfunc(char *szFormat, ...)
{
	va_list	lpStart;
	va_list next_arg;
	va_start(lpStart, szFormat);
	next_arg = lpStart;

	int arg1 = va_arg(next_arg, int);
	printf("%d\n", arg1);
	//next_arg = (va_list)((uintptr_t)next_arg - (sizeof(int) * 2));
	int arg2 = va_arg(next_arg, int);
	printf("%d\n", arg2);
	//next_arg = (va_list)((uintptr_t)next_arg - (sizeof(int) * 2));
	int arg3 = va_arg(next_arg, int);
	printf("%d\n", arg3);
	va_end(lpStart);
}

int main()
{
	my_varfunc("\n", 10, 20, 30);
	return 0;
}
