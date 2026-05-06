NAME	= replace
SRCS	= main.cpp printError.cpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

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

CLANG_IMAGE := silkeh/clang:19

CLANG_DOCKER := docker run --rm \
								-v $$(pwd):/app \
								-w /app \
								$(CLANG_IMAGE) /bin/sh -c

format:
	$(CLANG_DOCKER) \
	"clang-format -i -style=Google --verbose *.cpp *.hpp"

.PHONY: all clean fclean re format
