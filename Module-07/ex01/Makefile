NAME = iter
SRCS = main.cpp
FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)
fclean: clean
re: clean all

.PHONY: all clean fclean re
