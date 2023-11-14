sourcefiles = 	get_next_line_utils.c get_next_line.c

objects =		$(sourcefiles:.c=.o)

NAME =			get_next_line.a

all:			$(NAME)

$(NAME):		$(objects)
	@ar rcs get_next_line.a $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(objects)

fclean:
	@rm -f $(objects) $(NAME)

re: 			fclean all