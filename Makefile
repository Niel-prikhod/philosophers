NAME 	= philo
CC 		= cc

SRC_DIR = srcs
OBJ_DIR = build
INC_DIR = inc
SRCS 	= $(addprefix $(SRC_DIR)/, \
		  philo.c \
		  )

COMP_FLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LINK_FLAGS = -L$(INC_DIR)

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR): 
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(COMP_FLAGS) -c $< -o $@

$(NAME): $(OBJS) | $(OBJ_DIR)
	$(CC) $(LINK_FLAGS) $^ -o $@

clean: 
	rm $(OBJS)

fclean: 
	rm -rf $(OBJ_DIR)

re: fclean all
