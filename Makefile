NAME	= libftprintf.a

SRCS = ft_printf.c ft_pf_print_asc.c ft_pf_utils.c ft_libft_utils.c ft_libft_utils2.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus : $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS) 

all : $(NAME)

re : clean $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

.PHONY : clean fclean all re bonus
