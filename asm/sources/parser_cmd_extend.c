/*
** parser_cmd_extend.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by Maxime Pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Sun Mar 27 21:34:15 2016 
** Last update Sun Mar 27 21:56:32 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"op.h"
#include	"parser.h"
#include	"pile_label.h"
#include	"get_next_line.h"
#include	"asm.h"

int		parser_cmd_extend(t_cmd **stock_arg, int fd)
{
  int		nbr_line;
  char		*line;
  int		type;
  unsigned char	stock;

  stock = 0;
  nbr_line = 1;
  while ((line = get_next_line(fd)) != NULL)
    {
      if ((line = my_isspace(line, 0, 0)) == NULL)
	return(error_message_parser("epurstr failed line ", nbr_line));
      type = parsing(line, nbr_line);
      if (type == -1 || type == TYPE_LINE_EXTEND)
	stock = 1;
      if (stock != 1 && type != TYPE_LINE_EMPTY)
	{
	  if (storage(nbr_line, line, type, *stock_arg) == -1)
	    return (-1);
	  else if ((*stock_arg = add_cmd(*stock_arg)) == NULL)
	    return (-1);
	}
      else
	free(line);
      nbr_line++;
    }
  if (stock == 1)
    return (-1);
  return (0);
}
