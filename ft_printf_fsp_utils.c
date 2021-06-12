#include "ft_printf.h"

void	zeroing_fsp(t_fs *fsp)
{
	fsp->minus = 0;
	fsp->zero = 0;
	fsp->width = 0;
	fsp->prec = -1;
	fsp->star = 0;
	fsp->base = 16;
	fsp->hexup = 0;
}

t_fs	ft_type_writer(t_fs fsp, char x)
{
	fsp.type = x;
	if (x == 'X')
		fsp.hexup = 1;
	return (fsp);
}

int	ft_isprecflag(const char *format, int x, t_fs *fsp, va_list ap)
{
	x++;
	if (format[x] == '*')
	{
		fsp->prec = va_arg(ap, int);
		x++;
	}
	else
	{
		fsp->prec = 0;
		while (ft_isdigit(format[x]))
		{
			fsp->prec = fsp->prec * 10 + (format[x] - '0');
			x++;
		}
	}
	return (x);
}

t_fs	ft_isstarflag(t_fs fsp, va_list ap)
{
	fsp.star = 1;
	fsp.width = va_arg(ap, int);
	if (fsp.width < 0)
	{
		fsp.minus = 1;
		fsp.zero = 0;
		fsp.width = -fsp.width;
	}
	return (fsp);
}

t_fs	ft_iswidthflag(t_fs fsp, char x)
{
	if (fsp.star == 1)
		fsp.width = 0;
	fsp.width = fsp.width * 10 + (x - '0');
	return (fsp);
}
