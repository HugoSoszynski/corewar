/*
** stock_label.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Fri Mar 25 00:01:14 2016 
** Last update Sun Mar 27 17:00:38 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"
#include	"op.h"

t_cmd		*stock_label(char *line, t_cmd *cmd)
{
  if ((cmd->head->def = stock_pile_for_def(cmd->head->def, my_getword(line, 1), cmd->nbr_line)) == NULL)
    return (NULL);
  return (cmd);
}
