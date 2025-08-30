NAME	= phonebook
MAIN = srcs/main.c
SRCS	= main.cpp
HEADERS	= main.hpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

.DEFAULT:	all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADERS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	cmake -S ../.. -B ../../build
	cmake --build ../../build
	../../build/00/ex01/ex01_test

.PHONY: all clean fclean re test
