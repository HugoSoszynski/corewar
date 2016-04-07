/*
** parser_cmd_extend.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:20:53 2016 Hugo SOSZYNSKI
** Last update Thu Apr  7 12:13:39 2016 gregoire loens
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"op.h"
#include	"parser.h"
#include	"pile_label.h"
#include	"get_next_line.h"
#include	"asm.h"

int		parser_cmd_extend(t_cmd **stock_arg, int fd, unsigned char
				  stock, int nbr_line)
{
  char		*line;
  int		type;

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
      //else
	//	free(line);
      nbr_line++;
    }
  if (stock == 1)
    return (error_message_nonb("you have a .dot_extend or an error_line"));
  return (0);
}
