/*
** free_struct.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:07:48 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 23:08:04 2016 Hugo SOSZYNSKI
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"

void		free_linked_list(t_cmd *cmd)
{
  t_cmd		*to_next;

  while(cmd != NULL)
    {
      to_next = cmd->next;
      if (cmd->line != NULL)
	/*free(cmd->line);*/
      free(cmd);
      cmd = NULL;
      cmd = to_next;
    }
}

void		free_struct(t_cmd *cmd)
{
  t_pile	*to_next;
  t_cmd		*head;

  head = cmd->head;
  while (cmd->def != NULL)
    {
      to_next = cmd->def->next;
      free(cmd->def->label_name);
      free(cmd->def);
      cmd->def = to_next;
    }
  cmd = head;
  while (cmd->call != NULL)
    {
      to_next = cmd->call->next;
      free(cmd->call->label_name);
      free(cmd->call);
      cmd->call = to_next;
    }
  cmd = head;
  head->def = NULL;
  head->call = NULL;
  free_linked_list(cmd);
}
