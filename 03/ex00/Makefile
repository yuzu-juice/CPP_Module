NAME	= ClapTrap
SRCS	= main.cpp ClapTrap.cpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic

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

format:
	clang-format -i -style=Google *.cpp *.hpp

.PHONY: all clean fclean re run valgrind format
