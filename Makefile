##
## Makefile for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar
## 
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
## 
## Started on  Mon Mar 21 11:56:58 2016 Hugo SOSZYNSKI
## Last update Tue Mar 22 10:55:58 2016 
##

CC			=	gcc

RM			=	rm -f

CFLAGS			+=	-W -Wextra -Wall
CFLAGS			+=	-Werror
#CFLAGS			+=	-ansi
CFLAGS			+=	-pedantic
CFLAGS			+=	-ggdb3
CFLAGS			+=	-Iasm/includes
CFLAGS			+=	-Icorewar/includes

ASM			=	asm/asm

ASM_SRCS		=	asm/sources/cor_header.c \
				asm/sources/my_endianess.c \
                                asm/sources/get_next_line.c \
				asm/sources/init_stockage_functions.c \
				asm/sources/my_strdup.c \
				asm/sources/parser.c \
				asm/sources/cor_header.c \
				asm/sources/gst_str.c \
				asm/sources/my_getnbr.c \
				asm/sources/gst_type.c \
				asm/sources/error.c \
				asm/sources/my_str_to_wordtab.c \
				asm/sources/op.c \
				asm/sources/parser.c \
				asm/sources/parser_cmd.c \
				asm/sources/check_arg.c \
				asm/sources/check_cmd.c \
				asm/sources/check_dot_code.c \
				asm/sources/check_dot_comment.c \
				asm/sources/check_dot_extend.c \
				asm/sources/check_dot_name.c \
				asm/sources/check_exist_cmd.c \
				asm/sources/check_label.c \
				asm/sources/check_label_cmd.c \
				asm/sources/my_getword.c \
				asm/sources/tab_cmd.c \

ASM_OBJS		=	$(ASM_SRCS:.c=.o)

COREWAR			=	corewar/corewar

COREWAR_SRCS		=	corewar/sources/main.c \
				corewar/sources/initialisation/init_champ.c \
				corewar/sources/initialisation/init_corewar.c \
				corewar/sources/initialisation/init_options.c \
				corewar/sources/initialisation/champ_incomp.c \
				corewar/sources/my_endianess.c \
				corewar/sources/error.c \
				corewar/sources/my_getnbr.c \
				corewar/sources/my_putnbr.c \
				corewar/sources/my_strcmp.c

COREWAR_OBJS		=	$(COREWAR_SRCS:.c=.o)


all:		$(ASM) $(COREWAR)

$(ASM):		$(ASM_OBJS)
		$(CC) $(ASM_OBJS) -o $(ASM) -Iasm/includes

$(COREWAR):	$(COREWAR_OBJS)
		$(CC) $(COREWAR_OBJS) -o $(COREWAR) -Icorewar/includes

clean:
		$(RM) $(ASM_OBJS) $(COREWAR_OBJS)

fclean:		clean
		$(RM) $(ASM) $(COREWAR)

re:		fclean all

.PHONY:		all clean fclean re
