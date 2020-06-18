# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2020/06/18 14:24:09 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

####################################COLOR######################################
#----------------reset----------------#
NC = \033[0m

#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[35m
CYAN = \033[1;36m
WHITE = \033[0;37m

####################################NATIVE#####################################

#-----------------Main-----------------#
SRCS +=	src/native/main.c

#---------------Parsing----------------#
SRCS +=	$(PARS)init_struct_pars.c	$(PARS)parsing.c	$(PARS)parsing_map.c \
		$(PARS)utils_parsing.c		$(PARS)check_map.c	$(PARS)check_map2.c	 \
		$(PARS)check_sprite.c

#----------------Event-----------------#
SRCS +=	$(EVENT)init_struct_ev.c	$(EVENT)move_w_s.c	$(EVENT)move_a_d.c	 \
		$(EVENT)rotate_g_dr.c		$(EVENT)refresh.c	$(EVENT)event.c		 \
		$(EVENT)hook.c

#---------------Display----------------#
SRCS +=	$(DISP)init_world.c			$(DISP)print_img.c	$(DISP)display.c	 \
		$(DISP)set_images.c			$(DISP)print_img2.c
#---------------Save_BMP---------------#
SRCS += $(SAVE)save_bmp.c

#---------------Ray_cast---------------#
SRCS +=	$(RAY)init_struct_ray.c		$(RAY)ray_cast.c	$(RAY)cub3d.c		 \
		$(RAY)sprit_cast.c			$(RAY)sprit_cast2.c $(RAY)check_color.c

#####################################BONUS#####################################

#-----------------Main-----------------#
BONU +=	src/bonus/main.c

#---------------Parsing----------------#
BONU +=	$(PARSB)init_struct_pars.c	$(PARSB)parsing.c	$(PARSB)parsing_map.c \
		$(PARSB)utils_parsing.c		$(PARSB)check_map.c	$(PARSB)check_map2.c  \
		$(PARSB)check_sprite.c

#----------------Event-----------------#
BONU +=	$(EVENTB)init_struct_ev.c	$(EVENTB)move_w_s.c	$(EVENTB)move_a_d.c	 \
		$(EVENTB)rotate_g_dr.c		$(EVENTB)refresh.c	$(EVENTB)event.c	 \
		$(EVENTB)hook.c				$(EVENTB)utils.c

#---------------Display----------------#
BONU +=	$(DISPB)init_world.c		$(DISPB)print_img.c	$(DISPB)display.c	 \
		$(DISPB)put_mini_map.c		$(DISPB)print_go.c	$(DISPB)set_images.c \
		$(DISPB)print_lifbar.c		$(DISPB)win_lose.c	$(DISPB)print_weap.c \
		$(DISPB)print_img2.c

#---------------Save_BMP---------------#
BONU += $(SAVEB)save_bmp.c

#---------------Ray_cast---------------#
BONU +=	$(RAYB)init_struct_ray.c	$(RAYB)ray_cast.c	$(RAYB)cub3d.c		 \
		$(RAYB)sprit_cast.c			$(RAYB)sprit_cast2.c $(RAYB)check_color.c

#####################################PARTH#####################################

PARS	= src/native/parsing/
DISP	= src/native/game/display/
EVENT	= src/native/game/event/
RAY		= src/native/game/ray_cast/
SAVE	= src/native/game/bmp_save/

PARSB	= src/bonus/parsing/
DISPB	= src/bonus/game/display/
EVENTB	= src/bonus/game/event/
RAYB	= src/bonus/game/ray_cast/
SAVEB	= src/bonus/game/bmp_save/
#####################################BASIC#####################################

OBJS = $(SRCS:.c=.o)
BONUS = $(BONU:.c=.o)
INCL = header/
HEADER = $(INCL)cub3D.h
CC = clang
CFLAGS = -Wall -Wextra -Werror

#####################################LIBFT#####################################

LIB = Libft/
OBJLIB = $(LIB)src/*/*.o

####################################MINILIBX###################################

MLX = minilibx-linux/
OBJMLX = $(MLX)*.o

#####################################RULES#####################################
all : $(NAME)

$(OBJS) : %.o: %.c
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@
	printf "$(CYAN).$(NC)"

$(BONUS) : %.o: %.c
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@
	printf "$(CYAN).$(NC)"

$(NAME) : complib echoCLM compmlx echoOK echoCSM echoCL $(OBJS) echoOK echoCS
	$(CC) -O3 $(CFLAGS) -flto -march=native -o $@ $(OBJS) $(OBJLIB) $(MLX)libmlx.a -lm -lXext -lX11
	# $(CC) -O3 $(CFLAGS) -flto -march=native -o $@ $(OBJS) $(OBJLIB) $(MLX)libmlx.a -lm -lXext -lX11 -g3 -fsanitize=address

bonus : complib echoCLM compmlx echoOK echoCSM echoCL $(BONUS) echoOK echoCS
	$(CC) -O3 $(CFLAGS) -flto -march=native -o Cub3D $(BONUS) $(OBJLIB) $(MLX)libmlx.a -lm -lXext -lX11
	# $(CC) -O3 $(CFLAGS) -flto -march=native -o Cub3D $(BONUS) $(OBJLIB) $(MLX)libmlx.a -lm -lXext -lX11 -g3 -fsanitize=address

complib :
	$(MAKE) -C $(LIB)

compmlx :
	$(MAKE) -C $(MLX)

cleanlibft :
	$(MAKE) -C $(LIB) clean

fcleanlibft :
	$(MAKE) -C $(LIB) fclean

cleanmlx :
	$(MAKE) -C $(MLX) clean

fcleanmlx :
	$(MAKE) -C $(MLX) clean

cleancub : echoCLEAN
	$(RM) $(OBJS) $(BONUS)

clean : echoCLEAN cleanlibft cleanmlx
	$(RM) $(OBJS) $(BONUS)

fclean : clean echoFCLEAN fcleanlibft fcleanmlx
	$(RM) $(NAME)
	rm -rf a.out a.out.dSYM

re : fclean all

#####################################ECHO######################################
echoCL:
	echo "$(YELLOW)===> Compiling $(RED)Cub3D$(NC)"
echoOK:
	echo "$(GREEN)OK$(NC)"
echoCS :
	echo "\n$(GREEN)===> Compilation Success $(RED)Cub3D Ready!!$(NC)"
echoCLEAN :
	echo "$(PURPLE)===> Cleanning OBJ Cub3D$(NC)"
echoFCLEAN :
	echo "$(PURPLE)===> Cleanning Exec$(NC)"
echoCLM:
	echo "$(YELLOW)===> Compiling MLX$(NC)"
echoCSM :
	echo "$(GREEN)===> Compilation Success$(NC)"

.PHONY : all clean fclean re complib exec cleanlibft fcleanlibft
.SILENT :
