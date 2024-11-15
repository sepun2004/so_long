GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(SRC))
NAME = push_swap

CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra 

RM = rm -f

SRC = ./source/so_long.c\
		./source/check_map.c\
	  

OBJ = $(SRC:.c=.o)

all: show_progress $(NAME)

$(NAME): $(OBJ)
	@make bonus -s -C libft
	@make -s -C libft
# @make bonus -s -C ft_printf
	@make -s -C ft_printf
# @$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ../libft/libft -lft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ../ft_printf/ft_printf -lft
	@echo "$(GREEN)It has been compiled, have a nice day.👍$(NC)";

%.o: %.c
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "Compiling $<... $(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES))))%%\r"
	@$(CC) $(CFLAGS) -c $< -o $@ 

show_progress:
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)The compiled code is already updated.$(NC)"; \
	fi


git:
	git add *
	git commit
	git push

clean: 
	@$(RM) $(OBJ)
	@make  clean -s -C libft
	@make  clean -s -C ft_printf

fclean: clean
# rm -f $(NAME)
	@rm -f $(NAME)
	@make fclean -s -C libft
	@make fclean -s -C ft_printf
	@echo "$(RED)Full Cleaning...$(NC)"
	@echo "$(RED)Full Cleaned!$(NC)"

re: fclean all
