NAME	= megaphone
MAIN = srcs/main.c
SRCS	= main.cpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Werror -Wextra
CSTD	= -std=c++98
GTEST	= -lgtest_main -lgtest

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

re: fclean all

test:
	$(CC) $(CSTD) ./gtest.cpp $(GTEST)

.PHONY: all clean fclean re
