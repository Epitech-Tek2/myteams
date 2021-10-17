##
## EPITECH PROJECT, 2021
## teams
## File description:
## Makefile
##

LIB 				=	libcstring.a

SRC					=	getline.c	\
						helper.c	\
						issdigit.c	\
						itoa.c	\
						strtok.c	\
						printa.c	\
						ngetline.c

CFLAGS 				=	-DDEBUG -Wextra

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