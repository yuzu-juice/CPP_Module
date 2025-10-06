NAME	= megaphone
MAIN = srcs/main.c
SRCS	= main.cpp megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Werror -Wextra
CSTD	= -std=c++98

.DEFAULT:	all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CSTD) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf ../../build

re: fclean all

test:
	cmake -S ../.. -B ../../build
	cmake --build ../../build
	../../build/00/ex00/ex00_test

.PHONY: all clean fclean re test
