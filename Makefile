NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

#rules

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

#cleaning and rebuild

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re: fclean all
