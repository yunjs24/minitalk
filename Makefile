
SERVER	= server
CLIENT	= client

NAME	= $(SERVER) $(CLIENT)

FT_PRINTF_DIR	=	./ft_printf
LIBFTPRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)
		@make -C $(FT_PRINTF_DIR)
# all:	$(SERVER) $(CLIENT)

server: $(if $(findstring bonus, $(MAKECMDGOALS)), server_bonus.c, server.c) utils.c
	cc $(CFLAGS) $^ $(LIBFTPRINTF) -o $@

client: $(if $(findstring bonus, $(MAKECMDGOALS)), client_bonus.c, client.c) utils.c
	cc $(CFLAGS) $^ $(LIBFTPRINTF) -o $@

bonus:	$(SERVER) $(CLIENT)

clean:
		rm -rf $(SERVER).o $(CLIENT).o

fclean:	clean
		rm -rf $(SERVER) $(CLIENT) $(SERVER).o $(CLIENT).o

re:		fclean all

.PHONY: all bonus clean fclean re