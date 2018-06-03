CC		=	gcc
FLAGS   =   -Wall -Wextra -Werror
LIB_DIR =   libft/
NAME1	=	checker
NAME2	=	push_swap
SRCS_1	=   checker.c
SRCS_2	=	push_swap.c

OBJS1    =   $(SRCS_1:.c=.o)
OBJS2	=	$(SRCS_2:.c=.o)

all:	$(CHECKER) $(PUSH_SWAP)

$(LIB):
	make -C libft/

$(CHECKER): $(OBJS1)
	$(CC) $(FLAGS) $(OBJS1) -L libft/ -lft -o $(NAME1)

$(PUSH_SWAP): $(OBJS2)
	$(CC) $(FLAGS) $(OBJS2) -L libft/ -lft -o $(NAME2)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I includes/
	@echo "file =" $(C_BLUE){ $< } $(C_BASE)

clean:
	make -C libft/ clean
	rm -f $(OBJS1) $(OBJS2)

fclean:     clean
	make -C libft/ fclean
	rm -f $(NAME1) $(NAME2)

re:         fclean all

.PHONY: all clean fclean re
