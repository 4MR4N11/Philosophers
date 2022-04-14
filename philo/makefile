SRCS =	philo.c\
		parser.c\
		ft_atoi.c\
		executor.c

NAME = philo

HEADER = includes.h

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECT)
			gcc $(FLAGS) $(OBJECT) -o $(NAME)

%.o : %.c $(HEADER)
			gcc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)

fclean : clean
			rm -rf $(NAME)

re : fclean all