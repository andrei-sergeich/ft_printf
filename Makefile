NAME		=	libftprintf.a

SRCS		=	ft_printf.c			ft_printf_utils.c 	ft_printf_fsp.c 	ft_printf_fsp_utils.c\
				ft_printf_uns_int.c	ft_printf_itoa_long.c\
				ft_printf_integer.c \
				ft_printf_symbols.c \
				ft_printf_ptr.c	\
				ft_printf_hex.c	\

LIB_DIR 	= ./libft
HEADER 		= ./ft_printf.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@make re -C $(LIB_DIR)
			@cp $(LIB_DIR)/libft.a $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo all done, my Master!

%.o:		%.c ft_printf.h
			gcc $(CFLAGS) $(OPTFLAGS) -I $(HEADER) -c $< -o $@

norm:
			norminette .

test:
			@gcc main_ft_printf.c $(NAME) && ./a.out

clean:
			@rm -f $(OBJS)
			@make clean -C $(LIB_DIR)
			@echo .o files destroyed, my Master!

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C $(LIB_DIR)
			@echo all terminated, my Master!

re:			fclean all

.PHONY:		all clean fclean re bonus
