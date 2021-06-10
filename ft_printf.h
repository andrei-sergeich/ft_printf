#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_for_spec
{
	int	minus;
	int	zero;
	int	width;
	int	prec;
	// int	st_width;
	// int	st_prec;
	int	star;
	int	type;
	int	base;
	int	len;
}	t_fs;

int		ft_printf(const char *format, ...);
void	format_string_parser(const char *format, t_fs *flags, va_list ap);
int		flags_checker(const char *format, int x, t_fs *flags, va_list ap);
void	zeroing_flags(t_fs *flags);
int		ft_isflag(int x);
int		ft_istype(int x);
int		ft_isprecflag(const char *format, int x, t_fs *flags, va_list ap);
t_fs	ft_isminusflag(t_fs flags);
t_fs	ft_isstarflag(t_fs flags, va_list ap);
t_fs	ft_iswidthflag(t_fs flags, char x);
int		ft_putchar(char x);
int		print_me(t_fs flags, va_list ap);
int		print_width(int wd, int mn, int zr);
int		print_char(char x, t_fs flags);
int		print_str(char *str, t_fs flags);
int		strprinter(t_fs flags, char *str);
int		print_with_prec(int prec, char *str);
int		print_ptr(unsigned long long p, t_fs flags);
int		zero_ptr_print(t_fs flags);
char	*ptr_processing(unsigned long long p, t_fs flags);
char	*ptr_to_str(unsigned long long tmp, int bt, char *str, t_fs flags);
int		ptr_printer(int qbw, int len, char *ptr, t_fs flags);
int		not_zero_ptr_print(int len, char *ptr, t_fs flags);
int		print_integer(int d, t_fs flags);
int		get_integer(char *str, int tmp, t_fs flags);
int		integerprinter(char *str, int tmp, t_fs flags);





int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);

#endif