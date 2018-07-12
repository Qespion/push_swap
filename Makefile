.PHONY: all checker push_swap lib minilibx clean fclean re
.SUFFIXES:
CC		=	gcc
FLAGS   =   -Wall -Wextra -Werror
LIB_DIR =   libft/
NAME1	=	checker
NAME2	=	push_swap
MLIBX_DIR	=	minilibx/

SRCS_1	=   srcs/checker.c			\
			srcs/checker_struct.c	\
			srcs/swap.c				\
			srcs/rotate.c			\
			srcs/push.c				\
			srcs/reverse_rotate.c	\
			srcs/printlist.c		\
			srcs/apply_checker.c	\
			srcs/visu.c

SRCS_2	=	srcs/push_swap.c		\
			srcs/solver.c			\
			srcs/swap.c				\
			srcs/rotate.c			\
			srcs/push.c				\
			srcs/reverse_rotate.c	\
			srcs/check_list.c		\
			srcs/printlist.c		\
			srcs/push_in_b.c		\
			srcs/tools.c			\
			srcs/better_in_reverse.c\
			srcs/calc_av.c			\
			srcs/tri_b.c			\
			srcs/divide.c			\
			srcs/backtrack_a.c		\
			srcs/sequence.c			\
			srcs/tri_recursif.c		\
			srcs/swap_both_list.c	\
			srcs/n_push_back_in_a.c

LIBFT	=	libft/libft.a

C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"

OBJS1    =   $(SRCS_1:.c=.o)
OBJS2	=	$(SRCS_2:.c=.o)

all:	lib minilibx checker push_swap

lib:
	@make -C libft/

minilibx:
	@make -C minilibx/

checker: $(OBJS1)
	@echo $(C_GREEN)"----" $(C_BASE)
	@$(CC) $(FLAGS) $(OBJS1) -L libft/ -lft -o $(NAME1) -L$(MLIBX_DIR) -lmlx -framework OpenGL -framework AppKit

push_swap: $(OBJS2)
	@echo $(C_GREEN)"----" $(C_BASE)
	@$(CC) $(FLAGS) $(OBJS2) -L libft/ -lft -o $(NAME2)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I includes/
	@echo "file =" $(C_BLUE){ $< } $(C_BASE)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS1) $(OBJS2)

fclean:     clean
	@rm -f $(NAME1) $(NAME2) $(LIBFT) $(MINILIBX)

re:         fclean all

