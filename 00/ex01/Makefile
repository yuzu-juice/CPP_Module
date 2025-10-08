NAME	= phonebook
SRCS	= main.cpp phonebook.class.cpp contact.class.cpp

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
	../../build/00/ex01/ex01_test

format:
	clang-format -i -style=Google $(SRCS)

.PHONY: all clean fclean re test format
