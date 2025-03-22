CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
NAME =	pipex
MFILES = main.c ft_strdup.c ft_strcmp.c ft_strlen.c ft_strstr.c ft_split.c
OFILES = $(MFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c Pipex.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(OFILES) $(NAME)

re: fclean all

.PHONY: clean