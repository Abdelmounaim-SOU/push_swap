NAME	:= push_swap

SRCS	:= array_utils.c ft_split.c input_parsing.c instructions.c \
	   main.c mini_ops.c mini_ops2.c sort_utils.c sort_utils2.c sorting.c tools.c \
	   utils1.c utils2.c

OBJS	:= $(addprefix objs/, $(SRCS:.c=.o))

CFLAGS	:= -Wall -Werror -Wextra -g

objs/%.o:	%.c push_swap.h
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@ 

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)	-o $(NAME)

clean	:
	rm -rf objs

fclean	: clean
	rm -f $(NAME) $(BNAME)

re	: fclean all

.PHONY : clean
