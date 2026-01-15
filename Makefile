NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER_M = includes/push_swap.h
HEADER_B = includes/checker_bonus.h
INCLUDES = -I includes

DIR_MAN = mandatory
DIR_BNS = bonus
DIR_OBJ = obj
		
SRC_MAN =	push_swap.c utils/ft_atoi.c utils/ft_isspace.c utils/ft_numlen.c \
			utils/ft_split.c utils/ft_strjoin.c utils/lst_create.c utils/my_isdigit.c \
			utils/ft_strlen.c utils/assign_indexes.c utils/utils.c utils/lst_size.c \
			utils/assign_positions.c utils/free_stuff.c utils/lst_addback.c \
			algorithm/push_stack_b.c algorithm/rules/swap.c \
			algorithm/rules/rotate.c algorithm/rules/rrotate.c \
			algorithm/push_back_a.c algorithm/last_sort_a.c \
			algorithm/rules/push.c algorithm/set_target.c utils/is_sorted.c

SRC_BNS =	checker_bonus.c gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c \
			rules/swap_bonus.c rules/rotate_bonus.c rules/rrotate_bonus.c \
			rules/push_bonus.c utils/ft_atoi_bonus.c utils/ft_isspace_bonus.c \
			utils/ft_numlen_bonus.c utils/ft_split_bonus.c utils/lst_create_bonus.c \
			utils/my_isdigit_bonus.c utils/ft_strlen_bonus.c utils/utils_bonus.c \
			utils/lst_size_bonus.c utils/assign_positions_bonus.c utils/free_stuff_bonus.c \
			utils/ft_strjoin_bonus.c utils/assign_indexes_bonus.c utils/lst_addback_bonus.c \
			utils/parse_stack_bonus.c 

OBJ_SRC = $(SRC_MAN:%.c=$(DIR_OBJ)/%.o)
OBJ_BNS = $(SRC_BNS:%.c=$(DIR_OBJ)/%.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)
	@echo "Done."

$(DIR_OBJ)/%.o: $(DIR_MAN)/%.c $(HEADER_M) | $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(OBJ_BNS)
	@$(CC) $(CFLAGS) $(OBJ_BNS) -o $(CHECKER)
	@echo "Done."

$(DIR_OBJ)/%.o: $(DIR_BNS)/%.c $(HEADER_B) | $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)/utils
	@mkdir -p $(DIR_OBJ)/algorithm
	@mkdir -p $(DIR_OBJ)/algorithm/rules
	@mkdir -p $(DIR_OBJ)/gnl
	@mkdir -p $(DIR_OBJ)/rules

clean:
	@echo "Removed object files."
	@$(RM) $(OBJ_SRC) $(OBJ_BNS)
	@$(RM) -rf $(DIR_OBJ)

fclean: clean
	@echo "Removed the executable files."
	@$(RM) $(NAME) $(CHECKER)
	@echo "Done."

re: fclean all

.PHONY: clean


