#include "ft_printf.h"

int	print_me(t_fs fsp, va_list ap)
{
	if (fsp.type == 'c')
		fsp.qbw = print_char(va_arg(ap, int), fsp);
	if (fsp.type == 's')
		fsp.qbw = print_str(va_arg(ap, char *), fsp);
	if (fsp.type == 'p')
		fsp.qbw = print_ptr(va_arg(ap, unsigned long long), fsp);
	if (fsp.type == 'd' || fsp.type == 'i')
		fsp.qbw = print_integer(va_arg(ap, int), fsp);
	if (fsp.type == 'u')
		fsp.qbw = print_uns_int((unsigned int)va_arg(ap, unsigned int), fsp);
	if (fsp.type == 'x')
		fsp.qbw = print_hex(va_arg(ap, unsigned int), fsp);
	if (fsp.type == 'X')
		fsp.qbw = print_hex(va_arg(ap, unsigned int), fsp);
	if (fsp.type == '%')
		fsp.qbw = print_char('%', fsp);
	return (fsp.qbw);
}

int	fsp_checker(const char *format, int x, t_fs *fsp, va_list ap)
{
	while (format[x])
	{
		if (!ft_isdigit(format[x]) && !ft_isflag(format[x])
			&& !ft_istype(format[x]))
			break ;
		if (format[x] == '0' && fsp->width == 0 && fsp->minus == 0)
			fsp->zero = 1;
		if (format[x] == '.')
			x = ft_isprecflag(format, x, fsp, ap);
		if (format[x] == '-')
			*fsp = ft_isminusflag(*fsp);
		if (format[x] == '*')
			*fsp = ft_isstarflag(*fsp, ap);
		if (ft_isdigit(format[x]))
			*fsp = ft_iswidthflag(*fsp, format[x]);
		if (ft_istype(format[x]))
		{
			*fsp = ft_type_writer(*fsp, format[x]);
			break ;
		}
		if (x + 1 == (int)ft_strlen(format))
			return (x);
		x++;
	}
	return (x);
}

void	format_string_parser(const char *format, t_fs *fsp, va_list ap)
{
	int	x;

	x = 0;
	while (1)
	{
		zeroing_fsp(fsp);
		if (!format[x])
			break ;
		if (format[x] != '%')
			fsp->qbw += ft_putchar(format[x]);
		if (format[x] == '%')
		{
			if (x + 1 == (int)ft_strlen(format))
				break ;
			x = fsp_checker(format, ++x, fsp, ap);
			if (ft_istype(format[x]))
				fsp->qbw += print_me(*fsp, ap);
			else
				fsp->qbw += ft_putchar(format[x]);
		}
		x++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fs		fsp;

	fsp.qbw = 0;
	va_start(ap, format);
	format_string_parser(format, &fsp, ap);
	va_end(ap);
	return (fsp.qbw);
}
