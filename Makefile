##
## Makefile for allum1 in /home/soszyn_h/rendu/CPE/CPE_2015_Allum1/
##
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
##
## Started on  Mon Feb  8 17:48:10 2016 Hugo SOSZYNSKI
## Last update Wed Feb 24 11:46:23 2016 loens_g
##

CC			=	gcc

RM			=	rm -f

CFLAGS			+=	-W -Wextra -Wall
CFLAGS			+=	-Werror
#CFLAGS			+=	-ansi
CFLAGS			+=	-pedantic
CFLAGS			+=	-ggdb3

ASM			=	asm

ASM_SRCS		=	asm/sources/main.c \
				asm/sources/cor_header.c

ASM_OBJS		=	$(ASM_SRCS:.c=.o)



all:		$(ASM)

$(ASM):		$(ASM_OBJS)
		$(CC) $(ASM_OBJS) -o $(ASM) -Iinclude

clean:
		$(RM) $(ASM_OBJS)

fclean:		clean
		$(RM) $(ASM)

re:		fclean all

.PHONY:		all clean fclean re
