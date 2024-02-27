NAME = easyfind
SRCS = main.cpp
CFLAGS = c++ -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re