CC		=	gcc
FLAGS   =   -Wall -Wextra -Werror
LIB_DIR =   libft/
NAME1	=	checker
NAME2	=	push_swap

SRCS_1	=   srcs/checker.c

SRCS_2	=	srcs/push_swap.c		\
			srcs/solver.c			\
			srcs/swap.c				\
			srcs/rotate.c			\
			srcs/push.c				\
			srcs/reverse_rotate.c	\
			srcs/check_list.c		\
			srcs/printlist.c		\
			srcs/push_in_b.c		\
			srcs/push_back_in_a.c

LIBFT	=	libft/libft.a

C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"

OBJS1    =   $(SRCS_1:.c=.o)
OBJS2	=	$(SRCS_2:.c=.o)

all:	lib checker push_swap

lib:
	make -C libft/

checker: $(OBJS1)
	$(CC) $(FLAGS) $(OBJS1) -L libft/ -lft -o $(NAME1)

push_swap: $(OBJS2)
	$(CC) $(FLAGS) $(OBJS2) -L libft/ -lft -o $(NAME2)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I includes/
	@echo "file =" $(C_BLUE){ $< } $(C_BASE)

clean:
	make -C libft/ clean
	rm -f $(OBJS1) $(OBJS2)

fclean:     clean
	rm -f $(NAME1) $(NAME2) $(LIBFT)

re:         fclean all

.PHONY: all checker push_swap clean fclean re
