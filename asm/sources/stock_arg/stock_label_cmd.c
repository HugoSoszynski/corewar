/*
** stock_label_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Fri Mar 25 00:29:22 2016 
** Last update Sun Mar 27 20:17:17 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"
#include	"pile_label.h"


#include	<stdio.h>
#include	<unistd.h>


t_cmd	*stock_label_cmd(char *line, t_cmd *cmd)
{
  int	cpt;
  char	*tofree;
  
  cpt = 0;
  tofree =  my_getword(line, 1); 
  if ((cmd = stock_label(tofree, cmd)) == NULL) 
    { 
      free(tofree);
      return (NULL);
    }
  free(tofree);
  while (line[cpt] != ':')
    cpt++;
  if ((cmd = stock_cmd(line+cpt+2, cmd)) == NULL)
    return (NULL);
  return (cmd);
}
