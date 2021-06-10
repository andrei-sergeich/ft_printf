#include "ft_printf.h"

void	zeroing_flags(t_fs *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
	// flags->st_width = 0;
	// flags->st_prec = 0;
	flags->star = 0;
	flags->base = 16;
}

int	ft_isprecflag(const char *format, int x, t_fs *flags, va_list ap)
{
	x++;
	if (format[x] == '*')
	{
		flags->prec = va_arg(ap, int);
		x++;
	}
	else
	{
		flags->prec = 0;
		while (ft_isdigit(format[x]))
		{
			flags->prec = flags->prec * 10 + (format[x] - '0');
			x++;
		}
	}
	return (x);
}

t_fs	ft_isminusflag(t_fs flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_fs	ft_isstarflag(t_fs flags, va_list ap)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width = -flags.width;
	}
	return (flags);
}

t_fs	ft_iswidthflag(t_fs flags, char x)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = flags.width * 10 + (x - '0');
	return (flags);
}
