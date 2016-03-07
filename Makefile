##
## Makefile for allum1 in /home/soszyn_h/rendu/CPE/CPE_2015_Allum1/
##
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
##
## Started on  Mon Feb  8 17:48:10 2016 Hugo SOSZYNSKI
## Last update Mon Mar  7 16:39:30 2016 Hugo SOSZYNSKI
##

CC			=	gcc

RM			=	rm -f

CFLAGS			+=	-W -Wextra -Wall
CFLAGS			+=	-Werror
#CFLAGS			+=	-ansi
CFLAGS			+=	-pedantic
CFLAGS			+=	-ggdb3
CFLAGS			+=	-Iasm/includes

ASM			=	asm/asm

ASM_SRCS		=	asm/sources/cor_header.c \
				asm/sources/my_endianess.c

ASM_OBJS		=	$(ASM_SRCS:.c=.o)



all:		$(ASM)

$(ASM):		$(ASM_OBJS)
		$(CC) $(ASM_OBJS) -o $(ASM) -Iasm/includes

clean:
		$(RM) $(ASM_OBJS)

fclean:		clean
		$(RM) $(ASM)

re:		fclean all

.PHONY:		all clean fclean re
