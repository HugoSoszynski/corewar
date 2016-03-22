/*
** error.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 13:40:34 2016 Grégoire Loens
** Last update Mon Mar 21 22:59:18 2016 
*/

#include	<unistd.h>
#include	"parser.h"
#include	"asm.h"

int		error_message_parser(char *message, int nbr)
{
  write (2, message, my_strlen(message));
  my_putnbr(nbr);
  return (-1);
}

int		error_message(char *message)
{
  write(2, message, my_strlen(message));
  return (-1);
}
