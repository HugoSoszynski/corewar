/*
** stock_label_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Fri Mar 25 00:29:22 2016 
** Last update Fri Mar 25 00:48:02 2016 
*/

#include	"asm.h"
#include	"parser.h"
#include	"op.h"
#include	"pile.h"

t_cmd	*stock_label_cmd(char *line, t_cmd *cmd)
{
  int	cpt;

  cpt = 0;
  if ((cmd = stock_label(my_getword(line, 1), cmd)) == NULL)
    return (NULL);
  while (line[cpt] != ':')
    cpt++;
  if ((cmd = stock_cmd(line+cpt+2, cmd)) == NULL)
    return (NULL);
  return (cmd);
}
