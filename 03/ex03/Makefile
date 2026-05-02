NAME	= DiamondTrap
SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Werror -Wextra -Wshadow -std=c++98 -pedantic

.DEFAULT:	all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

valgrind: re
	valgrind --leak-check=full ./$(NAME)

CLANG_IMAGE := silkeh/clang:19

CLANG_DOCKER := docker run --rm \
								-v $$(pwd):/app \
								-v $$(realpath ../../.clang-format):/app/.clang-format \
								-w /app \
								$(CLANG_IMAGE) /bin/sh -c

format:
	$(CLANG_DOCKER)	\
	"clang-format -i -style=file --verbose *.cpp *.hpp" \
	&& rm .clang-format

.PHONY: all clean fclean re run valgrind format
