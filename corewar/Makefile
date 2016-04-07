##
## Makefile for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/
##
## Made by corsin_a
## Login   <sylvain.corsini@epitech.eu>
##
## Started on  Sun Mar 27 23:29:29 2016 corsin_a
## Last update Mon Apr  4 21:02:24 2016 Hugo SOSZYNSKI
##

CC			=	gcc

RM			=	rm -f

CFLAGS			+=	-W -Wextra -Wall
#CFLAGS			+=	-Werror
CFLAGS			+=	-Iincludes
CFLAGS			+=	-ggdb3

COREWAR			=	corewar

COREWAR_SRCS		=	sources/main.c \
				sources/check_h.c \
				sources/initialisation/init_champ.c \
				sources/initialisation/init_corewar.c \
				sources/initialisation/init_options.c \
				sources/initialisation/champ_incomp.c \
				sources/initialisation/fill_champions.c \
				sources/preparation/prepare_corewar.c \
				sources/preparation/prepare_mem.c \
				sources/preparation/prepare_process_list.c \
				sources/preparation/prepare_op_tab.c \
				sources/game/launch_corewar.c \
				sources/game/execute_process.c \
				sources/game/check_instruction.c \
				sources/game/check_reg.c \
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
				sources/my_endianess.c \
				sources/process_list_utils.c \
				sources/error.c \
				sources/my_getnbr.c \
				sources/my_putnbr.c \
				sources/my_strcmp.c \
				sources/aff_help.c \
				sources/my_init_tab.c \
				sources/game/print_champions_states.c \
				sources/initialisation/set_address_many.c \
				sources/game/verif_pc.c

COREWAR_OBJS		=	$(COREWAR_SRCS:.c=.o)

all:	$(COREWAR)

$(COREWAR):	$(COREWAR_OBJS)
	$(CC) $(COREWAR_OBJS) -o $(COREWAR) -Iincludes

clean:
	$(RM) $(COREWAR_OBJS)

fclean: clean
	$(RM) $(COREWAR)

re: fclean all

.PHONY:		all clean fclean re	
