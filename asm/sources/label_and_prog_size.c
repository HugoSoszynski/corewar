/*
** label_and_prog_size.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 15:25:08 2016 
** Last update Thu Mar 24 16:35:41 2016 
*/

#include	"asm.h"
#include	"parser.h"
#include	"op.h"

int		strcmpend(char *str1, char *str2)
{
  int		cpt;

  cpt = 0;
  while (str1[cpt] && str2[cpt] && str1[cpt] == str2[cpt])
    ++cpt;
  if (!str2[cpt] && !str1[cpt])
    return (0);
  return (-1);
}

int		check_only_label(t_cmd *cmd)
{
  t_pile	*head;
  t_pile       	*check;

  head = cmd->def;
  if (cmd->def->next == NULL)
    return (0);
  while (cmd->def->next != NULL)
    {
      check = cmd->def->next;
      while (check->next != NULL)
	{
	  if (strcmpend(cmd->def->label_name, check->label_name) != -1)
	    return (-1);
	}
    }
}

      int		label_and_prog_size(t_cmd *cmd, int *prog_size)
      {
	if (check_only_label(cmd) == -1)
	  return (-1);
      }
