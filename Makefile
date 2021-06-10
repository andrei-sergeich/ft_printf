NAME		=	libftprintf.a

FL_LIST		=	ft_printf.c			ft_printf_utils.c 	ft_printf_flags.c 	ft_printf_flags_utils.c\
				ft_printf_symbols.c \
				ft_printf_integer.c \
				ft_printf_ptr.c		ft_printf_ptr_utils.c	

LIB_DIR 	= ./libft

OBJS		=	$(patsubst %.c,%.o,$(FL_LIST))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			@cp $(LIB_DIR)/libft.a $(NAME)
			@ar rcs $(NAME) $?
			@echo all done, my Master!

%.o:		%.c ft_printf.h
			@gcc $(CFLAGS) $(OPTFLAGS) -I ft_printf.h -c $< -o $@

clean:
			@rm -f $(OBJS) $(OBJS_B)
			@make clean -C $(LIB_DIR)
			@echo .o files destroyed, my Master!

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C $(LIB_DIR)
			@echo all terminated - wooalya

re:			fclean all

.PHONY:		all clean fclean re bonus

# ЕСТЬ ПРОБЛЕМА ПОСЛЕ ПЕРЕСБОРКИ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!