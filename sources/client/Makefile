##
## EPITECH PROJECT, 2021
## teams
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC_MAIN	=	main.c	\
				start_client.c	\
				recieve.c	\
				send.c	\
				handle_command.c

COMMAND_PATH	=	commands/
COMMAND_SRC		=	log.c	\
					nop.c	\
					user.c	\
					users.c	\
					logout.c	\
					create.c	\
					error.c	\
					messages.c	\
					message.c	\
					list.c	\
					subscribe.c	\
					unsubscribe.c

UTILS_PATH	=	utils/
UTILS_SRC	=	strctok.c	\
				get_command_parsed.c

SRC	=	$(SRC_MAIN)	\
		$(addprefix $(UTILS_PATH), $(UTILS_SRC)) \
		$(addprefix $(COMMAND_PATH), $(COMMAND_SRC))

NAME	=	../../myteams_cli

CFLAGS	=	-I../../includes -lm -g -L../../bin/ -lstring -lcstring \
	-llist -L../../libs/myteams/ -lmyteams -luuid

LDFLAGS	=

OBJS	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re