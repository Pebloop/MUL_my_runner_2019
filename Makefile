SRC	=	main.c					\
		parallax.c				\
		parralax_add_layer.c	\
		messages.c				\
		entity_player.c			\
		entity_parallax.c		\
		entity_rail.c			\
		entity_camera.c			\
		entity_map.c			\
		entity_sprite.c			\
		entity_music.c			\
		entity_score.c			\
		entity_progress.c		\
		load_map.c				\
		get_next_line.c			\
		system_hud.c			\
		system_player_control.c	\
		keyboard_is_key_down.c	\
		scene_game.c			\
		scene_lose.c			\
		scene_win.c				\
		component_sprite.c		\
		component_animator.c	\
		component_speed.c		\
		component_stat.c		\
		component_player.c		\
		component_map.c			\
		component_parallax.c	\
		component_camera.c		\
		component_text.c		\
		component_music.c		\
		component_sound.c		\
		component_sheet.c		\
		set_score.c				\
		map.c					\

NAME	=	my_runner

DEBUG	=	my_runner.d

CFLAGS	=	-Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	$(NAME)

$(NAME):
		make -C lib/dragon/
		gcc -g3 -o $(NAME) $(SRC) $(CFLAGS)

debug:
		make -C lib/dragon/
		gcc -g3 -o $(DEBUG) $(SRC)

clean:
		make clean -C lib/dragon/

fclean:	clean
		make fclean -C lib/dragon/
		-rm $(NAME)
		-rm $(DEBUG)

re:	fclean all
