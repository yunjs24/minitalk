CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
NAME			=	minitalk

FT_PRINTF_DIR	=	./ft_printf
LIBFTPRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a
			
all:
	@make -C ./ft_printf
	@$(CC) $(CFLAG) server.c utils.c $(LIBFTPRINTF) $^ -o server
	@$(CC) $(CFLAG) client.c utils.c $(LIBFTPRINTF) $^ -o client 

clean:
	@make -C $(FT_PRINTF_DIR) clean
	@rm -f server
	@rm -f client

fclean: clean
	@make -C $(FT_PRINTF_DIR) fclean

re: 
	@make -C $(FT_PRINTF_DIR fclean)
	make fclean
	make all

bonus:
	make fclean
	@make -C $(FT_PRINTF_DIR)
	@$(CC) $(CFLAG) server_bonus.c utils.c $(LIBFTPRINTF) $^ -o server
	@$(CC) $(CFLAG) client_bonus.c utils.c $(LIBFTPRINTF) $^ -o client

.PHONY:	all clean fclean bonus re