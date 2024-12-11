GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(SRC))
NAME = so_long

CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra 

RM = rm -f

# LIBMLX	= ./mlx/lib/MLX42

# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SOURCES =	so_long.c\
			check_map.c\
			parce_map.c\

SRCS = $(addprefix source/, $(SOURCES))

SRC = $(SRCS)

OBJ = $(SRC:.c=.o)

all: show_progress $(NAME)

$(NAME):  $(OBJ)
	@make -s -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft
	@echo "$(GREEN)It has been compiled, have a nice day.👍$(NC)";

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


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

fclean: clean
# rm -f $(NAME)
	@rm -f $(NAME)
	@make fclean -s -C libft
	@echo "$(RED)Full Cleaning...$(NC)"
	@echo "$(RED)Full Cleaned!$(NC)"

re: fclean all
