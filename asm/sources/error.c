/*
** error.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 13:40:34 2016 Grégoire Loens
** Last update Wed Mar 23 05:42:05 2016 
*/

#include	<unistd.h>
#include	"parser.h"
#include	"asm.h"

int		error_message_line(char *message, int nbr, char *line)
{
  write (2, message, my_strlen(message));
  my_put_nbr_base(nbr, "0123456789"); 
  write (2, " cause of \"", 11);
  write (2, line, my_strlen(line));
  write (2, "\"\n", 2);
  return (-1);
}

int		error_message_parser1(char *message, int nbr)
{
  write (2, message, my_strlen(message));
  my_put_nbr_base(nbr, "0123456789");
  return (-1);  
}

int		error_message_parser(char *message, int nbr)
{
  write (2, message, my_strlen(message));
  my_put_nbr_base(nbr, "0123456789");
  write (2, "\n", 1);
  return (-1);
}

int		error_message_nonb(char *message)
{
  write(2, message, my_strlen(message));
  write(2, "\n", 1);
  return (-1);
}

int		error_message(char *message)
{
  write(2, message, my_strlen(message));
  write (2, " ", 1);
  return (-1);
}
