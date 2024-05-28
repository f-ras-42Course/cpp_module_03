# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/26 08:28:34 by fras          #+#    #+#                  #
#    Updated: 2024/05/28 14:59:05 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap
CC = c++
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.cpp=%.o))
RM = rm -f

ifdef DEBUG
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -g -fsanitize=address
endif

ifndef CPP98
CFLAGS += -std=c++11
endif

ifdef CPP98
CFLAGS += -std=c++98
endif

ifdef NOUNUSED
CFLAGS += -Wno-unused-value -Wunused-value 
CFLAGS += -Wno-unused-variable -Wno-unused-parameter
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJECTS)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Debugging
debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

CPP98:
	$(MAKE) CPP98=1

NOUNUSED:
	$(MAKE) NOUNUSED=1

# Info Message
message:
	@echo "\033[92m$(EXECUTABLE) is ready for usage!\033[0m"