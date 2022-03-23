SRCS =	philo.c\
		parcer.c\
		ft_atoi.c

NAME = philo

HEADER = includes.h

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECT) $(HEADER)
			gcc $(FLAGS) $(OBJECT) -o $(NAME)

%.o : %.c
			gcc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)

fclean : clean
			rm -rf $(NAME)

re : fclean all