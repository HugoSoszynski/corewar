##
## Makefile for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar
##
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
##
## Started on  Mon Mar 21 11:56:58 2016 Hugo SOSZYNSKI
## Last update Sun Mar 27 23:34:39 2016 corsin_a
##

all:
	make -C asm/
	make -C corewar/
	make -C bonus/

clean:
	make -C asm/ clean
	make -C corewar/ clean
	make -C bonus/ clean

fclean:
	make -C asm/ fclean
	make -C corewar/ fclean
	make -C bonus/ fclean

re:
	make -C asm/ re
	make -C corewar/ re
	make -C bonus/ re

.PHONY:		all clean fclean re
