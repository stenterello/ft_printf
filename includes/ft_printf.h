#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_print
{
	int		flags;
	int		width;
	int		space;
	int		dot;
	int		plus;
	int		minus;
	int		hash;
	int		percent;
	int		zero;
	int		prec;
	char	type;
}	t_print;

int		ft_printf(const char *s, ...);
int		ft_ispercent(char c);
int		ft_deep_elaborate(const char *s, int *i, va_list args);
t_print	ft_init_flags(void);
int		ft_isflag(const char c);
int		ft_istype(char c);
void	ft_take_flag(const char c, t_print *arg);
void	ft_take_parameters(const char *s, int *i, t_print *arg);
void	ft_take_type(const char c, t_print *arg);
int		ft_treat_d(va_list args, t_print *arg);
int		ft_treat_c(va_list args, t_print *arg);
int		ft_treat_s(va_list args, t_print *arg);
int		ft_treat_ptr(va_list args, t_print *arg);
int		ft_treat_percent(void);
int		ft_treat_hex(va_list args, t_print *arg);
int		ft_treat_HEX(va_list args, t_print *arg);
int		ft_treat_u(va_list args, t_print *arg);
int		synthesis(va_list args, t_print *arg);
int		ft_putnbr_u_base(unsigned long long nbr, char *base);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_u_fd(unsigned int n, int fd);
int		ft_puthex(int n, const char *base);
char	*ft_int_to_bin(int data);
char	*ft_reverse_bin(char *convert);
char	*ft_add_one_to_bin(char *convert, int pos);
int		ft_power(int base, int esp);
char	*ft_bin_to_hex(char *convert, char *base);
int		ft_atoi_char(char c);
char	*ft_dec_to_hex(int *values, char *base);
char	*ft_get_hex(int data, char *base);
int		ft_abs_val(int data);
int		ft_long_to_hex(long data);
int		ft_unbrlen(unsigned int n);
int		ft_int_nbrlen(int n);
int		ft_ptrnbrlen(size_t data);
int		ft_putnbr_base_ptr(size_t nbr, char *base);
void	ft_fill_write_start_free(t_print *arg, char *str, char c);
void	ft_fill_write_end_free(t_print *arg, char *str, char c);
char	*ft_utoa(unsigned int n);
void	ft_u_putnbr(unsigned int n, char *str, int *i);

#endif
