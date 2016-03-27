##
## Makefile for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar
##
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
##
## Started on  Mon Mar 21 11:56:58 2016 Hugo SOSZYNSKI
## Last update Sun Mar 27 15:40:24 2016 Sylvain Corsini
##

CC			=	gcc

RM			=	rm -f

LIB			=	-L/home/${USER}/.froot/lib/ -llapin \
-L/usr/local/lib \
-lsfml-audio \
-lsfml-graphics \
-lsfml-window \
-lsfml-system \
-lstdc++ -ldl \
-lm

CFLAGS			+=	-W -Wextra -Wall
CFLAGS			+=	-Werror
CFLAGS			+=	-Iincludes
CFLAGS			+=	$(LIB)
CFLAGS			+=	-g

COREWAR			=	corewar

COREWAR_SRCS		=	sources/main.c \
				sources/mainloop.c \
				sources/keys.c \
				sources/initialisation/init_champ.c \
				sources/initialisation/init_corewar.c \
				sources/initialisation/init_options.c \
				sources/initialisation/champ_incomp.c \
				sources/initialisation/fill_champions.c \
				sources/initialisation/init_graphics.c \
				sources/preparation/prepare_corewar.c \
				sources/preparation/prepare_mem.c \
				sources/preparation/prepare_process_list.c \
				sources/preparation/prepare_op_tab.c \
				sources/game/launch_corewar.c \
				sources/game/execute_process.c \
				sources/game/check_instruction.c \
				sources/game/check_reg.c \
				sources/game/verif_pc.c \
				sources/game/init_instruction.c \
				sources/game/op/add.c \
				sources/game/op/aff.c \
				sources/game/op/and.c \
				sources/game/op/fork.c \
				sources/game/op/ld.c \
				sources/game/op/ldi.c \
				sources/game/op/lfork.c \
				sources/game/op/live.c \
				sources/game/op/lld.c \
				sources/game/op/lldi.c \
				sources/game/op/or.c \
				sources/game/op/st.c \
				sources/game/op/sti.c \
				sources/game/op/sub.c \
				sources/game/op/xor.c \
				sources/game/op/zjmp.c \
				sources/graphics/launch_graphics.c \
				sources/graphics/tekblit.c \
				sources/graphics/tekpixel.c \
				sources/graphics/tekgetcolor.c \
				sources/graphics/tekreset.c \
				sources/graphics/tektext.c \
				sources/graphics/show_interface.c \
				sources/graphics/show_cycle.c \
				sources/graphics/show_mem.c \
				sources/graphics/show_champ.c \
				sources/my_endianess.c \
				sources/process_list_utils.c \
				sources/error.c \
				sources/my_getnbr.c \
				sources/my_putnbr.c \
				sources/my_strcmp.c \
				sources/aff_help.c \
				sources/my_init_tab.c

COREWAR_OBJS		=	$(COREWAR_SRCS:.c=.o)


all:		$(COREWAR)

$(COREWAR):	$(COREWAR_OBJS)
		$(CC) $(COREWAR_OBJS) -o $(COREWAR) -Icorewar/includes $(LIB)

clean:
		$(RM) $(COREWAR_OBJS)

fclean:		clean
		$(RM) $(COREWAR)

re:		fclean all

.PHONY:		all clean fclean re
