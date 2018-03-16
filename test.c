#include <unistd.h>
#include <stdlib.h>
#include "buffer/buffer.h"
#include "ft/ft.h"

/*typedef unsigned char *va_list;
#define va_start(list, param) (list = (((va_list)&param) + sizeof(param)))
#define va_arg(list, type)    (*(type *)((list += sizeof(type)) - sizeof(type)))

void	test(int a, ...)
{
	va_list	va;
	int		i;

	va_start(va, a);
	i = va_arg(va, int);
	printf("%d\n", i);
}*/

int	main(void)
{
	t_buffer_fd	out;
	char		*s;

	buffer_fd_init(&out, STDOUT_FILENO);
	buffer_fd_printf(&out, "Test %s %d %% %x !\n", "42", -42, 0xDEAD);
	s = ft_asprintf("Test %s %d %% %x !", "42", -42, 0xDEAD);
	buffer_fd_printf(&out, "'%s'\n", s);
	free(s);
	buffer_fd_flush(&out);
	//test(42, 43, 44, 45);
	return (0);
}
