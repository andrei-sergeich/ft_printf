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
	int	star;
	int	type;
	int	hexup;
	int	base;
	int	qbw;
}	t_fs;

int		ft_printf(const char *format, ...);
void	format_string_parser(const char *format, t_fs *fsp, va_list ap);
int		fsp_checker(const char *format, int x, t_fs *fsp, va_list ap);
void	zeroing_fsp(t_fs *fsp);
int		ft_isflag(int x);
int		ft_istype(int x);
int		ft_isprecflag(const char *format, int x, t_fs *fsp, va_list ap);
t_fs	ft_type_writer(t_fs fsp, char x);
t_fs	ft_isminusflag(t_fs fsp);
t_fs	ft_isstarflag(t_fs fsp, va_list ap);
t_fs	ft_iswidthflag(t_fs fsp, char x);
int		ft_putchar(char x);
int		print_me(t_fs fsp, va_list ap);
int		print_width(int wd, int mn, int zr);
int		print_char(char x, t_fs fsp);
int		print_str(char *str, t_fs fsp);
int		strprinter(t_fs fsp, char *str, int len);
int		print_with_prec(int prec, char *str);
int		print_ptr(unsigned long long p, t_fs fsp);
int		zero_ptr_print(t_fs fsp);
char	*nbr_processing(unsigned long long p, t_fs fsp);
char	*convers_to_str(unsigned long long tmp, int bt, char *str, t_fs fsp);
int		ptr_printer(int qbw, int len, char *ptr, t_fs fsp);
int		not_zero_ptr_print(int len, char *ptr, t_fs fsp);
int		print_integer(int d, t_fs fsp);
int		get_integer(char *str, int tmp, t_fs fsp);
int		integerprinter(char *str, int tmp, t_fs fsp);
int		print_uns_int(unsigned int u, t_fs fsp);
char	*ft_itoa_ui(unsigned int u);
int		get_uns_int(int len, char *str, t_fs fsp);
int		uns_int_printer(int len, char *str, t_fs fsp);
int		print_hex(unsigned int hex, t_fs fsp);
int		get_hex(int len, char *str, t_fs fsp);
int		hex_printer(int len, char *str, t_fs fsp);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_toupper(int c);

#endif