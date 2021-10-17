##
## EPITECH PROJECT, 2021
## teams
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC_MAIN	=	main.c	\
				server.c	\
				file.c

UTILS_PATH	=	utils/
UTILS_SRC	=	strctok.c	\
				remove_quotes.c	\
				send_logs_to_client.c	\
				new_mstat.c	\
				check_creation.c

FILE_PATH	=	client/file/
FILE_SRC	=	update_status.c	\
				check_exist.c \
				append_data.c \
				add_new_client.c	\
				load_user.c	\
				get_registered_user.c

COMMAND_PATH	=	commands/
COMMAND_SRC	=	user/uuid.c \
				user/user_exist.c	\
				help.c \
				nop.c	\
				login.c	\
				users.c	\
				user.c	\
				create/create_team.c	\
				create/create_channel.c	\
				create/create.c	\
				messages.c	\
				send.c	\
				use.c	\
				list.c	\
				info.c	\
				subscribe/subscribe.c	\
				subscribe/subscribed.c	\
				subscribe/unsubscribe.c

CLIENT_PATH	=	client/
CLIENT_SRC	=	handle.c	\
				close.c	\
				client.c	\
				logout.c

SRC	=	$(SRC_MAIN)	\
		$(addprefix $(COMMAND_PATH), $(COMMAND_SRC))	\
		$(addprefix $(UTILS_PATH), $(UTILS_SRC))	\
		$(addprefix $(FILE_PATH), $(FILE_SRC))	\
		$(addprefix $(CLIENT_PATH), $(CLIENT_SRC))

NAME	=	../../myteams_server

CFLAGS	=	-I../../includes -lm -g

LDFLAGS	=	-lstring -L../../bin/ -lcstring -L../../bin/ -L../../bin -llist \
	-L../../libs/myteams/ -lmyteams -luuid

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