NAME	= philo
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

HEADER	= philo.h

SRC		= activities.c philo.c init_philo.c start_philo.c utils.c

all: $(NAME)
$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	$(RM) $(NAME)

re : fclean all
