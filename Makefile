SRC =			./src/player_checks.c \
				./src/player_movement.c \
				./src/player_errors.c \
				./src/player_images.c \
				./src/player_maps.c \
				./src/player_objects.c \
				./src/player_utils.c \
				./src/player_impossible_maps.c \
				./src/so_long.c
				
OBJS = $(SRC:.c=.o)
RM = rm -f
NAME = so_long
LMLX = ./minilibx-linux/libmlx.a
LFT = ./ft_printf/libftprintf.a ./libft/libft.a
LIB = -L ./ft_printf -lftprintf -L ./minilibx-linux/ -lmlx -lXext -lX11 -lm -lbsd -L ./libft -lft
CFLAGS = -Wall -Werror -Wextra -fPIE
all : ${LMLX} ${LFT} $(NAME)
${LMLX}:
				@make -s -C ./minilibx-linux/ all
${LFT}:
				make -s -C ./ft_printf/ all
				make -s -C ./libft/ all
###.c.o:
###				@gcc -s -Wall -Werror -Wextra $(LIB) -c $< -o $(<:.c=.o)
$(NAME) :    $(OBJS)
				@gcc -Wall -Werror -Wextra -g ${OBJS} $(LIB) -o ${NAME} -pie
				@echo "\033[32mDone !\033[0m"
clean :
				@$(RM) $(OBJS)
				@make -s -C ./minilibx-linux/ clean
				@make -s -C ./ft_printf/ clean
				@make -s -C ./libft/ clean
fclean :    clean
						$(RM) $(NAME)
						make -C ./ft_printf/ fclean
						make -C ./libft/ fclean
re: fclean all
.PHONY: all clean fclean re
