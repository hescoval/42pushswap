NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SOURCE = *.c
SOURCE_OBJS = $(SOURCE:.c=.o)

# Variáveis de texto
GREEN = \033[92m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(SOURCE_OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(SOURCE_OBJS) $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Compilation successful."

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SOURCE_OBJS) : $(SOURCE)
	$(CC) $(FLAGS) -c $(SOURCE)

clean:
	rm -rf $(SOURCE_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "[$(GREEN)SUCCESS$(RESET)]Objects removed."

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Static Library and Executables removed."

re: fclean all

.SILENT:

.PHONY: all clean fclean re
