NAME			=	so_long

SRCS			=	main.c \
					parser.c \
					parser_utils.c \
					error.c \
					engine.c \
					utils.c \
					window.c \
					window_utils.c \
					hooks.c \
					cube_utils.c \
					draw_utils.c \

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					@${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
					printf "$(GREEN)█"

$(NAME)			:	compile ${OBJS} done
					make -C libft
					make -C mlx
					@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

val				:	${NAME}
					valgrind \
					--leak-check=full --tool=memcheck \
					--show-reachable=yes \
					--track-fds=yes \
					--errors-for-leak-kinds=all \
					--show-leak-kinds=all ./${NAME}

clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re

.SILENT:

BLUE	= \033[1;34m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
DEFAULT = \033[0m

compile	:
			echo "\n$(YELLOW)[X] Compiling $(BLUE)So_long$(DEFAULT)\n"
done	:
			echo "$(GREEN) => 100%$(DEFAULT)\n"
