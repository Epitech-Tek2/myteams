##
## EPITECH PROJECT, 2021
## teams
## File description:
## Makefile
##

LIB 				=	liblist.a

SRC					=	list.c	\
						push.c	\
						pushl.c	\
						size.c	\
						valueof.c	\
						dispose.c	\
						copy.c	\
						end.c

CFLAGS 				=	-DDEBUG -Wextra -LIST

LDFLAGS				=	-Iinclude/

AR 					=	ar rc

MV					=	mv

LIB_OBJ 			=	$(SRC:.c=.o)

all:					$(LIB)
						$(MV) $(LIB) ../../bin/

$(LIB):					$(LIB_OBJ)
						$(AR) $(LIB) $(LIB_OBJ)

clean_lib:
						$(RM) $(LIB)

clean:
						$(RM) $(LIB_OBJ)

fclean:					clean
						$(RM) $(LIB)
						$(RM) ../../bin/$(LIB)

re:						fclean all

.PHONY:					all clean fclean re