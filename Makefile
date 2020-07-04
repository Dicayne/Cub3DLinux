# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2020/06/30 15:44:51 by vmoreau          ###   ########.fr        #
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

#####################################PARTH#####################################

#Main souce
vpath %.c src/

#Native souces
vpath %.c src/native/parsing/
vpath %.c src/native/game/display/
vpath %.c src/native/game/event/
vpath %.c src/native/game/ray_cast/
vpath %.c src/native/game/bmp_save/

#Bonus souces
vpath %.c src/bonus/parsing/
vpath %.c src/bonus/game/display/
vpath %.c src/bonus/game/event/
vpath %.c src/bonus/game/ray_cast/
vpath %.c src/bonus/game/bmp_save/

####################################NATIVE#####################################

#-----------------Main-----------------#
SRCS +=	main.c

#---------------Parsing----------------#
SRCS +=	init_struct_pars.c	parsing.c		parsing_map.c 			\
		utils_parsing.c		check_map.c		check_map2.c			\
		check_sprite.c

#----------------Event-----------------#
SRCS +=	init_struct_ev.c	move_w_s.c		move_a_d.c				\
		rotate_g_dr.c		refresh.c		event.c					\
		hook.c

#---------------Display----------------#
SRCS +=	init_world.c		print_img.c		display.c		 		\
		set_images.c		print_img2.c
#---------------Save_BMP---------------#
SRCS += save_bmp.c

#---------------Ray_cast---------------#
SRCS +=	init_struct_ray.c	ray_cast.c		cub3d.c			 		\
		sprit_cast.c		sprit_cast2.c	check_color.c

#####################################BONUS#####################################

#-----------------Main-----------------#
BONU +=	main.c

#---------------Parsing----------------#
BONU +=	init_struct_pars.c	parsing.c		parsing_map.c	 		\
		utils_parsing.c		check_map2.c  	check_map_bonus.c		\
		check_sprite_bonus.c

#----------------Event-----------------#
BONU +=	init_struct_ev.c	refresh.c		move_a_d_bonus.c		\
		rotate_g_dr.c		event_bonus.c	move_w_s_bonus.c		\
		hook_bonus.c		utils_bonus.c

#---------------Display----------------#
BONU +=	init_world.c		display_bonus.c	put_mini_map_bonus.c	\
		win_lose_bonus.c	print_img2.c	set_images_bonus.c		\
		print_go_bonus.c	print_img.c		print_weap_bonus.c		\
		print_lifbar_bonus.c 

#---------------Save_BMP---------------#
BONU += save_bmp.c

#---------------Ray_cast---------------#
BONU +=	init_struct_ray.c	ray_cast.c		sprit_cast_bonus.c		\
		check_color.c		cub3d.c			sprit_cast2_bonus.c

#####################################BASIC#####################################

DIR_OBJS	= ./objs/
DIR_OBJSB	= ./objs_bonus/
OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))
BONUS		= $(patsubst %.c, $(DIR_OBJSB)%.o, $(BONU))

INCL = ./header/
HEADER = $(INCL)cub3d.h
CC = clang
CFLAGS = -Wall -Wextra -Werror

#####################################LIBFT#####################################

LIB = ./Libft/
OBJLIB = $(LIB)src/*/*.o

####################################MINILIBX###################################

OBJMLX = $(MLX)*.o

MLX = ./minilibx-linux/
LIB_LINK	= -L $(MLX) -lmlx -lX11 -lXext -lbsd -lm -L $(LIB) -lft

#####################################RULES#####################################
ALL_INC	=  -I$(INCL) -I$(LIB)header/ -I$(MLX)

all : $(NAME)

$(OBJS) : $(DIR_OBJS)%.o: %.c $(HEADER) | $(DIR_OBJS)
	$(CC) $(CFLAGS) $(ALL_INC) -c $< -o $@ 
	printf "$(CYAN).$(NC)"

$(BONUS) : $(DIR_OBJSB)%.o: %.c $(HEADER) | $(DIR_OBJSB)
	$(CC) $(CFLAGS) $(ALL_INC) -c $< -o $@ 
	printf "$(CYAN).$(NC)"

$(NAME) : complib echoCLM compmlx echoOK echoCSM echoCL $(OBJS)
	$(CC) -O3 $(CFLAGS) -flto -march=native -o $@ $(OBJS) $(ALL_INC) $(LIB_LINK)
	printf "$(GREEN)OK$(NC)"
	printf "\n$(GREEN)===> Compilation Success $(RED)Cub3D Ready!!$(NC)\n"

bonus : complib echoCLM compmlx echoOK echoCSM echoCL $(BONUS)	
	$(CC) -O3 $(CFLAGS) -flto -march=native -o $(NAME) $(BONUS) $(ALL_INC) $(LIB_LINK)
	printf "$(GREEN)OK$(NC)"
	printf "\n$(GREEN)===> Compilation Success $(RED)Cub3D Ready!!$(NC)\n"

$(DIR_OBJS) :
	mkdir -p $@
	mkdir -p screenshot

$(DIR_OBJSB) :
	mkdir -p $@
	mkdir -p screenshot

complib :
	$(MAKE) -C $(LIB)

compmlx :
	$(MAKE) -C $(MLX)

cleanlibft :
	$(MAKE) clean -C $(LIB)

clean : echoCLEAN
	$(MAKE) clean -C $(LIB)
	$(MAKE) clean  -C $(MLX)
	$(RM) -R $(DIR_OBJS)
	$(RM) -R $(DIR_OBJSB)

fclean: clean echoFCLEAN
	$(MAKE) fclean -C $(LIB)
	$(RM) $(NAME)
	$(RM) -R screenshot
	rm -rf a.out a.out.dSYM


re : fclean all


#####################################ECHO######################################
echoCL:
	echo "$(YELLOW)===> Compiling $(RED)Cub3D$(NC)"
echoOK:
	echo "$(GREEN)OK$(NC)"
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