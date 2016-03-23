##
## Makefile for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar
## 
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
## 
## Started on  Mon Mar 21 11:56:58 2016 Hugo SOSZYNSKI
## Last update Wed Mar 23 16:32:52 2016 Sylvain Corsini
##

CC			=	gcc

RM			=	rm -f

#CFLAGS			+=	-W -Wextra -Wall
#CFLAGS			+=	-Werror
#CFLAGS			+=	-ansi
CFLAGS			+=	-pedantic
CFLAGS			+=	-ggdb3
CFLAGS			+=	-Iasm/includes
CFLAGS			+=	-Icorewar/includes

ASM			=	asm/asm

ASM_SRCS		=       asm/sources/get_next_line.c \
				asm/sources/my_put_nbr.c \
				asm/sources/my_strdup.c \
				asm/sources/gst_str.c \
				asm/sources/my_strncat.c \
				asm/sources/gst_type_extend.c \
				asm/sources/my_getnbr.c \
				asm/sources/gst_type.c \
				asm/sources/error.c \
				asm/sources/main.c \
				asm/sources/my_str_to_wordtab.c \
				asm/sources/parser_cmd.c \
				asm/sources/cmd_line/check_arg.c \
				asm/sources/base.c \
				asm/sources/cmd_line/check_cmd.c \
				asm/sources/cmd_line/check_dot_code.c \
				asm/sources/cmd_line/check_dot_comment.c \
				asm/sources/cmd_line/check_dot_extend.c \
				asm/sources/cmd_line/check_dot_name.c \
				asm/sources/cmd_line/check_exist_cmd.c \
				asm/sources/cmd_line/check_label.c \
				asm/sources/cmd_line/check_label_cmd.c \
				asm/sources/cmd_line/my_getword.c \
				asm/sources/cmd_line/tab_cmd.c \

ASM_OBJS		=	$(ASM_SRCS:.c=.o)

COREWAR			=	corewar/corewar

COREWAR_SRCS		=	corewar/sources/main.c \
				corewar/sources/initialisation/init_champ.c \
				corewar/sources/initialisation/init_corewar.c \
				corewar/sources/initialisation/init_options.c \
				corewar/sources/initialisation/champ_incomp.c \
				corewar/sources/initialisation/fill_champions.c \
				corewar/sources/preparation/prepare_corewar.c \
				corewar/sources/preparation/prepare_mem.c \
				corewar/sources/preparation/prepare_process_list.c \
				corewar/sources/preparation/prepare_op_tab.c \
				corewar/sources/game/launch_corewar.c \
				corewar/sources/game/execute_process.c \
				corewar/sources/game/copy_instruction.c \
				corewar/sources/game/init_instruction.c \
				corewar/sources/game/op/add.c \
				corewar/sources/game/op/aff.c \
				corewar/sources/game/op/and.c \
				corewar/sources/game/op/fork.c \
				corewar/sources/game/op/ld.c \
				corewar/sources/game/op/ldi.c \
				corewar/sources/game/op/lfork.c \
				corewar/sources/game/op/live.c \
				corewar/sources/game/op/lld.c \
				corewar/sources/game/op/lldi.c \
				corewar/sources/game/op/or.c \
				corewar/sources/game/op/st.c \
				corewar/sources/game/op/sti.c \
				corewar/sources/game/op/sub.c \
				corewar/sources/game/op/xor.c \
				corewar/sources/game/op/zjmp.c \
				corewar/sources/my_endianess.c \
				corewar/sources/error.c \
				corewar/sources/my_getnbr.c \
				corewar/sources/my_putnbr.c \
				corewar/sources/my_strcmp.c \
				corewar/sources/aff_help.c \
				corewar/sources/my_init_tab.c

COREWAR_OBJS		=	$(COREWAR_SRCS:.c=.o)


all:		$(ASM)

$(ASM):		$(ASM_OBJS)
		$(CC) $(ASM_OBJS) -o $(ASM) -Iasm/includes

$(COREWAR):	$(COREWAR_OBJS)
		$(CC) $(COREWAR_OBJS) -o $(COREWAR) -Icorewar/includes

clean:
		$(RM) $(ASM_OBJS) $(COREWAR_OBJS)

fclean:		clean
		$(RM) $(ASM) $(COREWAR)

re:		fclean all

test:		$(ASM_OBJS)
		$(CC) $(ASM_OBJS) -o $(ASM) -I./asm/includes

.PHONY:		all clean fclean re
