##
## Makefile for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/asm/
##
## Made by corsin_a
## Login   <sylvain.corsini@epitech.eu>
##
## Started on  Sun Mar 27 23:27:48 2016 corsin_a
## Last update Thu Apr  7 22:18:46 2016 Hugo SOSZYNSKI
##

CC			=	gcc

RM			=	rm -f

CFLAGS			+=	-W -Wall -Wextra
CFLAGS			+=	-Iincludes

ASM			=	asm

ASM_SRCS		=	sources/stock_arg/stock_cmd_extend.c \
				sources/parser_cmd_extend.c \
				sources/base_extend.c \
				sources/free_struct.c \
				sources/my_endianess.c \
				sources/label_and_prog_size.c \
				sources/my_getnbr_base.c \
				sources/name_and_comment.c \
				sources/write_cor.c \
				sources/write_file.c \
				sources/stock_arg/calc_octet.c \
				sources/stock_arg/set_octet_label.c \
				sources/stock_arg/stock_cmd.c \
				sources/stock_arg/stock_code.c \
				sources/cor_header.c \
				sources/init_stock.c \
				sources/stock_arg/stock_label.c \
				sources/stock_arg/stock_label_cmd.c \
				sources/stock_arg/stock_pile.c \
				sources/get_next_line.c \
				sources/my_put_nbr.c \
				sources/my_strdup.c \
				sources/gst_str.c \
				sources/my_strncat.c \
				sources/gst_type_extend.c \
				sources/my_getnbr.c \
				sources/gst_type.c \
				sources/error.c \
				sources/main.c \
				sources/my_str_to_wordtab.c \
				sources/parser_cmd.c \
				sources/cmd_line/check_arg.c \
				sources/base.c \
				sources/cmd_line/check_cmd.c \
				sources/cmd_line/check_dot_code.c \
				sources/cmd_line/check_dot_comment.c \
				sources/cmd_line/check_dot_extend.c \
				sources/cmd_line/check_dot_name.c \
				sources/cmd_line/check_exist_cmd.c \
				sources/cmd_line/check_label.c \
				sources/cmd_line/check_label_cmd.c \
				sources/cmd_line/my_getword.c \
				sources/cmd_line/tab_cmd.c \
				sources/my_bzero.c

ASM_OBJS		=	$(ASM_SRCS:.c=.o)

all:	$(ASM)

$(ASM):	$(ASM_OBJS)
	$(CC) $(ASM_OBJS) -o $(ASM) -Iincludes

clean:
	$(RM) $(ASM_OBJS)

fclean: clean
	$(RM) $(ASM)

re: fclean all

.PHONY:		all clean fclean re
