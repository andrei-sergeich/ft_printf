#include "ft_printf.h"

int	print_me(t_fs flags, va_list ap)
{
	int	qbw;

	qbw = 0;
	if (flags.type == 'c')
		qbw = print_char(va_arg(ap, int), flags);
	if (flags.type == 's')
		qbw = print_str(va_arg(ap, char *), flags);
	if (flags.type == 'p')
		qbw = print_ptr(va_arg(ap, unsigned long long), flags);
	if (flags.type == 'd' || flags.type == 'i')
		qbw = print_integer(va_arg(ap, int), flags);
	if (flags.type == '%')
		qbw = print_char('%', flags);
	return (qbw);
}

int	flags_checker(const char *format, int x, t_fs *flags, va_list ap)
{
	while (format[x])
	{
		if (!ft_isdigit(format[x]) && !ft_isflag(format[x])
			&& !ft_istype(format[x]))
			break ;
		if (format[x] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[x] == '.')
			x = ft_isprecflag(format, x, flags, ap);
		if (format[x] == '-')
			*flags = ft_isminusflag(*flags);
		if (format[x] == '*')
			*flags = ft_isstarflag(*flags, ap);
		if (ft_isdigit(format[x]))
			*flags = ft_iswidthflag(*flags, format[x]);
		if (ft_istype(format[x]))
		{
			flags->type = format[x];
			break ;
		}
		x++;
	}
	return (x);
}

void	format_string_parser(const char *format, t_fs *flags, va_list ap)
{
	int	x;

	x = 0;
	while (1)
	{
		zeroing_flags(flags);
		if (!format[x])
			break ;
		if (format[x] != '%')
			flags->len += ft_putchar(format[x]);
		if (format[x] == '%' && format[x + 1])
		{
			x = flags_checker(format, ++x, flags, ap);
			if (ft_istype(format[x]))
				flags->len += print_me(*flags, ap);
			else
				flags->len += ft_putchar(format[x]);
		}
		x++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fs		flags;

	flags.len = 0;
	va_start(ap, format);
	format_string_parser(format, &flags, ap);
	va_end(ap);
	return (flags.len);
}
