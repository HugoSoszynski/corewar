/*
** stock_label.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Fri Mar 25 00:01:14 2016 
** Last update Sun Mar 27 20:41:14 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"
#include	"op.h"

t_cmd		*stock_label(char *line, t_cmd *cmd)
{
  char		*tofree;

  tofree = my_getword(line, 1);
  if ((cmd->head->def = stock_pile_for_def(cmd->head->def, tofree, cmd->nbr_line)) == NULL)
    {
      free(tofree);
      tofree = NULL;
      return (NULL);
    }
  return (cmd);
}
