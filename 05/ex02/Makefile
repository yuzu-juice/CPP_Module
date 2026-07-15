NAME	= form
SRCS	= main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic

.DEFAULT:	all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
								-w /app \
								$(CLANG_IMAGE) /bin/sh -c

format:
	$(CLANG_DOCKER) \
	"clang-format -i -style=Google --verbose *.cpp *.hpp"

.PHONY: all clean fclean re run valgrind format
