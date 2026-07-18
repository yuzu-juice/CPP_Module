NAME = convert

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ScalarConverter.hpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
RM = rm -f

CLANG_IMAGE := silkeh/clang:19
CLANG_DOCKER := docker run --rm \
	-v $$(pwd):/app \
	-w /app \
	$(CLANG_IMAGE) /bin/sh -c

.DEFAULT: all

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

format:
	$(CLANG_DOCKER) \
	"clang-format -i -style=Google --verbose *.cpp *.hpp"

.PHONY: all clean fclean re run format
