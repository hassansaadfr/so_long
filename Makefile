NAME			=	so_long

SRCS			=	main.c \
					parser.c \
					parser_utils.c \
					error.c \
					engine.c \
					utils.c \
					window.c \
					window_utils.c \
					game_utils.c \
					hooks.c \
					cube_utils.c \
					draw_utils.c \
					move_player.c


SRCS_BONUS		=	main_bonus.c \
					parser_bonus.c \
					parser_utils_bonus.c \
					error_bonus.c \
					engine_bonus.c \
					utils_bonus.c \
					window_bonus.c \
					window_utils_bonus.c \
					game_utils_bonus.c \
					hooks_bonus.c \
					cube_utils_bonus.c \
					draw_utils_bonus.c \
					move_player_bonus.c

OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

OBJS_BONUS		=	${addprefix srcs/bonus/,${SRCS_BONUS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C libft
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

bonus			:	${OBJS_BONUS}
					make -C libft
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_BONUS} -o ${NAME} -lft ${MLX_FLAGS}

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
					@rm -rf ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
