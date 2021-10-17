##
## EPITECH PROJECT, 2021
## teams
## File description:
## Makefile
##

LIBRARY_PATH	=	libs/
SERVER_PATH	=	sources/server
CLIENT_PATH	=	sources/client

all:	library server client

library:
	make -C $(LIBRARY_PATH) -s

server:
	make -C $(SERVER_PATH) -s

client:
	make -C $(CLIENT_PATH) -s

clean:
	make clean -C $(LIBRARY_PATH) -s
	make clean -C $(SERVER_PATH) -s
	make clean -C $(LIBRARY_PATH) -s
	make clean -C $(CLIENT_PATH) -s

fclean:
	make fclean -C $(LIBRARY_PATH) -s
	make fclean -C $(SERVER_PATH) -s
	make fclean -C $(LIBRARY_PATH) -s
	make fclean -C $(CLIENT_PATH) -s

re:
	make re -C $(LIBRARY_PATH) -s
	make re -C $(SERVER_PATH) -s
	make re -C $(LIBRARY_PATH) -s
	make re -C $(CLIENT_PATH) -s

.PHONY: all library server client clean fclean re