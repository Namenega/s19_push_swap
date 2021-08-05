SRCNAME 	=	srcs/push_swap.c				\
				srcs/big_algo.c					\
				srcs/first_sort.c				\
				srcs/parsing.c					\
				srcs/print_manip.c				\
				srcs/small_algo.c				\
				srcs/sort_b.c					\
				srcs/utils_0.c					\
				srcs/utils_1.c					\
				srcs/tab_manip/pa_pb.c			\
				srcs/tab_manip/sa_sb.c			\
				srcs/tab_manip/ra_rb_rra_rrb.c

SRCS 		= ${SRCNAME}

OBJS 		= ${SRCS:.c=.o}

CHECKER		= checker
PUSH_SWAP	= push_swap

CC 			= gcc #-g -fsanitize=address
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -I -I./libft

CGREEN		= \033[38;2;0;153;0m
CRED		= \033[0;31m
CYELLOW		= \033[0;33m
CGREY		= \033[38;2;128;128;128m
CEND		= \033[0m


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${PUSH_SWAP}:	${OBJS}
		@echo
		@echo "$(CYELLOW)Compilation of Libft$(CEND)"
		@echo "$(CGREY)"
		make -C ./libft
		@echo
		${CC} -o ${PUSH_SWAP} ${OBJS} -L./libft -lft
		@echo "$(CEND)"
		@echo "$(CGREEN)Compilation done !$(CEND)"
		@echo

all:		${PUSH_SWAP}

clean:
		@echo
		@echo "$(CYELLOW)Deleting .o files$(CEND)"
		@echo "$(CGREY)"
		make -C ./libft clean
		${RM} ${OBJS}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

fclean:		clean
		@echo "$(CYELLOW)Deleting .o files, libft.a and push_swap$(CEND)"
		@echo "$(CGREY)"
		${RM} ${PUSH_SWAP} ./libft/libft.a
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

re: 		fclean all

c: 			all clean

.PHONY: 	clean fclean all re