NAME	= polymorphism
SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

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
	$(MAKE) clean
	./$(NAME)

valgrind: re
	$(MAKE) clean
	valgrind --leak-check=full ./$(NAME)

format:
	clang-format -i -style=Google *.cpp *.hpp

.PHONY: all clean fclean re format
