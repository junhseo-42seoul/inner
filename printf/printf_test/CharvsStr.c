#include<unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int main()
{
	ft_putstr_fd('s', 1);
}