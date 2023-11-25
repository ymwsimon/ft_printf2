NAME	= libftprintf.a

SRCS = ft_printf.c ft_pf_print_asc.c ft_pf_utils.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

LIBFT_DIR = ./libft

LIBFT_A = libft.a

LIBFT_H = libft.h

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus : $(NAME)

$(OBJS) : $(LIBFT_DIR)/$(LIBFT_H) $(LIBFT_DIR)/$(LIBFT_A) $(SRCS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_A) ./$(NAME)
	cp $(LIBFT_DIR)/$(LIBFT_H) ./
	$(CC) $(FLAGS) -c $(SRCS) -I$(LIBFT_DIR)

all : $(NAME)

re : clean $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

.PHONY : clean fclean all re bonus
