LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCSFLS = ft_printf.c \
			ft_ispercent.c \
			ft_deep_elaborate.c \
			ft_init_flags.c \
			ft_isflag.c \
			ft_istype.c \
			ft_take_flag.c \
			ft_take_parameters.c \
			ft_take_type.c \
			ft_treat_d.c \
			ft_treat_c.c \
			ft_treat_percent.c \
			ft_treat_s.c \
			ft_treat_hex.c \
			ft_treat_HX.c \
			ft_treat_u.c \
			ft_treat_ptr.c \
			ft_putnbr_base.c \
			ft_putnbr_u_base.c \
			ft_putnbr_u_fd.c \
			ft_puthex.c \
			ft_int_to_hex.c \
			ft_unbrlen.c \
			ft_utoa.c \
			synthesis.c 

SRCS =  $(addprefix srcs/, $(SRCSFLS))

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)
OBJSD = $(addprefix objs/, $(OBJS))

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	mv *.o objs
	ar rcs $(NAME) objs/*.o

all: $(NAME)

bonus: all

clean:
	$(MAKE) clean -C ./libft
	rm -rf objs/*.o
	rm -rf srcs/*.o

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
