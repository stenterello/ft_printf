/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:48 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:40:49 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_take_flag(const char c, t_print *arg);
void	ft_take_parameters(const char *s, int *i, t_print *arg);
void	ft_take_type(const char c, t_print *arg);
int		ft_istype(char c);
int		synthesis(va_list args, t_print *arg);
int		ft_treat_c(va_list args, t_print *arg);
int		ft_treated_start_c(va_list args, t_print *arg, char sep);
int		ft_treated_end_c(va_list args, t_print *arg, char sep);
int		ft_treat_s(va_list args, t_print *arg);
void	ft_add_data_s(t_print *arg, char *str, char *data);
int		ft_no_flag_s(t_print *arg, char *data);
char	*ft_create_str_s(t_print *arg, char *data);
int		ft_ptrnbrlen(size_t n, size_t b_len);
char	*ft_utoa_base(size_t n, char *base, int b_len);
char	*ft_get_ptr_str(size_t data, char *base);
char	*ft_create_str_ptr(t_print *arg, char *convert);
void	ft_add_data_ptr(t_print *arg, char *ret, char *convert);
int		ft_treat_ptr(va_list args, t_print *arg);
void	ft_if_add_zero_ptr(t_print *arg, char *str, size_t data);
int		ft_add_minus_ptr(t_print *arg, char *str, size_t data);
int		ft_no_flag_ptr(size_t data);
void	ft_add_zeroes_ptr(t_print *arg, char *ret, size_t data);
int		ft_int_nbrlen(int n);
int		ft_dot_nbrlen(int n);
void	ft_add_data(t_print *arg, char *str, int data);
int		ft_treat_d(va_list args, t_print *arg);
char	*ft_calloc_string_d(t_print *arg, int size, int data, char c);
char	*ft_create_str(t_print *arg, int data);
void	ft_if_add_zero(t_print *arg, char *str, int data);
int		ft_add_minus(t_print *arg, char *str, int data);
int		ft_no_flag(int data);
void	ft_add_zeroes(t_print *arg, char *ret, int data);
void	ft_prec_aux(char *str, int flag, t_print *arg);
void	ft_handle_minus(t_print *arg, char *text, int data, char *str);
void	ft_handle_width(t_print *arg, char *text, int data, char *str);
void	ft_handle_prec(t_print *arg, char *text, int data, char *str);
void	ft_add_data_u(t_print *arg, char *str, unsigned int data);
int		ft_treat_u(va_list args, t_print *arg);
char	*ft_create_str_u(t_print *arg, unsigned int data);
void	ft_if_add_zero_u(t_print *arg, char *str, unsigned int data);
int		ft_add_minus_u(t_print *arg, char *str, unsigned int data);
int		ft_no_flag_u(unsigned int data);
void	ft_add_zeroes_u(t_print *arg, char *ret, unsigned int data);
void	ft_handle_minus_u(t_print *arg, char *text, int data, char *str);
void	ft_handle_width_u(t_print *arg, char *text, int data, char *str);
void	ft_handle_prec_u(t_print *arg, char *text, char *str);
int		ft_treat_x(va_list args, t_print *arg);
void	ft_add_data_hex(t_print *arg, char *ret, unsigned int data);
char	*ft_create_str_hex(t_print *arg, unsigned int data);
char	*ft_utoa_hex(t_print *arg, unsigned int data);
int		ft_no_flag_hex(t_print *arg, unsigned int data);
void	ft_if_add_zero_hex(t_print *arg, char *str, int data);
int		ft_hexnbrlen(unsigned int data);
void	ft_add_zeroes_hex(t_print *arg, char *ret, unsigned int data);
void	ft_set_string(char *ret, char *text, char c, int size);
void	ft_set_string2(char *ret, char *text, t_print *arg);
void	ft_set_string3(char *ret, char *text, char c, int size);
void	ft_handle_min_x(t_print *arg, char *text, char *ret);
void	ft_handle_wid_x(t_print *arg, char *text, char *ret);
void	ft_handle_prec_x(t_print *arg, char *text, char *ret);
void	ft_handle_hash_x(t_print *arg, char *text, char *ret);
void	ft_handle_zero_x(t_print *arg, char *text, char *ret);
void	ft_add_data_percent(char *ret, t_print *arg);
int		ft_no_flag_percent(void);
char	*ft_create_str_percent(t_print *arg);
int		ft_treat_percent(t_print *arg);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_base_ptr(size_t nbr, char *base);
int		ft_putnbr_u_base(unsigned long long nbr, char *base);
int		ft_u_base_len(unsigned long long nbr, char *base);
void	ft_putnbr(long n, char *str, int *i);
int		ft_putnbr_u_fd(unsigned int n, int fd);
int		ft_puthex(int n, const char *base);
int		ft_unbrlen(unsigned int n);
char	*ft_utoa(unsigned int n);

#endif
