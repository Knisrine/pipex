CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = mypipex
MFILES = main.c ft_strdup.c ft_strlen.c ft_strstr.c count_word.c get_path.c close_fd.c utils.c ex_error.c exit_state.c ft_split.c free_data.c ft_strjoin.c
OFILES = $(MFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c pipex.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean