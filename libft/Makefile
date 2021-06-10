NAME		=	libft.a

FT_LIST		=	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c\
				ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_memccpy.c	ft_memchr.c\
				ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_strchr.c\
				ft_strdup.c		ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		ft_strncmp.c\
				ft_strnstr.c	ft_strrchr.c	ft_tolower.c	ft_toupper.c\
				ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c\
				ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c\
				ft_strcpy.c		ft_strclr.c

FT_LIST_B	= 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
				ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

OBJS		=	$(patsubst %.c,%.o,$(FT_LIST))
OBJS_B		=	$(patsubst %.c,%.o,$(FT_LIST_B))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $?

%.o:		%.c libft.h
			@gcc $(CFLAGS) $(OPTFLAGS) -c $< -o $@

bonus:
			@make OBJS="$(OBJS_B)" all

clean:
			@rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus