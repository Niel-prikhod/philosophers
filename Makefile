NAME 		= philo
CC 			= cc
MODE	   ?= debug

SRC_DIR 	= srcs
OBJ_DIR 	= build
INC_DIR		= inc
SRCS 		= $(addprefix $(SRC_DIR)/, \
		  		philo.c \
		  		init.c \
		  		)

COMP_FLAGS 	= -Wall -Wextra -Werror -I$(INC_DIR)
LINK_FLAGS 	= -L$(INC_DIR)
DFLAGS 		= -g -O0 
ADDRESS	= address,undefined
THREADS		= threads
SAN_FLAGS	= -fsanitize=$(ADDRESS)
ifeq ($(MODE),debug)
	DFLAGS += $(SAN_FLAGS)
	COMP_FLAGS += $(DFLAGS)
	LINK_FLAGS += $(SAN_FLAGS)
endif


OBJS 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

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
