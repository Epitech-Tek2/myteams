##
## EPITECH PROJECT, 2021
## teams
## File description:
## Makefile
##

LIB 				=	libstring.a

SRC					=	string.c	\
						find.c	\
						append.c	\
						compare.c	\
						dispose.c	\
						empty.c	\
						erase.c	\
						length.c	\
						set.c

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