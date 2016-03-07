/*
** parser_cmd.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 14:24:56 2016 Grégoire Loens
** Last update Mon Mar  7 16:09:42 2016 
*/

#include	"parser.h"

int		verif_cmd_line(int fd, int nbr_line)
{
  char		*line;

  while ((line = get_next_line(fd)) != NULL)
    {
      if (line = my_isspace(line) == NULL)
	return(error_message_parser("Syntax error line ", nbr_line));
      if (verif_nbr_cmd(line) == -1)
	return (error_message_parser("Syntax error line ", nbr_line));
      if (verif_nbr_arg(line) == -1)
	return (error_message_parser("Syntax error line ", nbr_line));
      if (command_with_arg(line) == -1)
	return (error_message_parser("Syntax error line ", nbr_line));
      if (use_of_arg(line) == -1)
	return (error_message_parser("Syntax error line ", nbr_line));
    }
}
