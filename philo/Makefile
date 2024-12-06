CC := cc
CFLAGS := -Wall -Werror -Wextra
INCLUDE := -I includes
RM := rm -rf

NAME := philo

OBJ_DIR := obj/
SRC_DIR := src/

DIRS = $(addprefix $(OBJ_DIR),src/ utils/)

HEADER = includes/philosophers.h
SRC_SRCS = $(addprefix src/,check.c clear.c error.c init.c launch.c start.c monitor.c \
destroy.c mtx.c acquire_release.c forks_meals.c) 
UTILS_SRCS = $(addprefix utils/,is_digit.c my_atoi.c my_calloc.c my_usleep.c)

BLUE = $(shell tput -Txterm setaf 6)
RESET = $(shell tput -Txterm sgr0)
BOLD := $(shell tput bold)
SGR0 := $(shell tput sgr0)
SYMB := $(BOLD)$(BLUE)√$(SGR0)

.PHONY: all bonus clean fclean re

SRCS = main.c $(UTILS_SRCS) $(SRC_SRCS)
OBJS = $(addprefix $(OBJ_DIR),$(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $^ $(LIBS) $(LINKS) -o $@

$(OBJ_DIR)%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR) $(DIRS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "\t$(SYMB) $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@\n"

clean:
	@$(RM) $(OBJ_DIR) 
fclean: clean
	@$(RM) $(NAME)
re: fclean all
