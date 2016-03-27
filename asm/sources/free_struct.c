/*
** free_struct.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by Maxime Pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Sun Mar 27 12:06:51 2016 
** Last update Sun Mar 27 14:32:16 2016 
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"

/*void		free_linked_list(t_cmd *cmd)
{
  t_cmd		*to_next;

  free(head);
  while(cmd != NULL)
    {
      to_next = cmd->next;
      free(cmd->line);
      cmd = to_next;
    }
}

void		free_struct(t_cmd *cmd)
{
  t_pile	*to_next;

  cmd = cmd->head;
  while (cmd->def != NULL)
    {
      to_next = cmd->def->next;
      free(cmd->def->label_name);
      free(cmd->def);
      cmd->def = to_next;
    }
  while (cmd->call != NULL)
    {
      to_next = cmd->call->next;
      free(cmd->call->label_name);
      free(cmd->call);
      cmd->call = to_next;
    }
  free_linked_list(cmd);
}
*/
