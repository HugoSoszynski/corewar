/*
** label_and_prog_size.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 15:25:08 2016 
** Last update Fri Mar 25 17:56:01 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"

#include	<unistd.h>
#include	<stdio.h>


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
/*
void		write_struct(t_pile *call, t_pile *def)
{
  while ( call != NULL && call->label_name != NULL)
    {
      printf ("les valeurs dans call %s %d \n", call->label_name, call->nb_line);
      call = call->next;
    }
  while (def != NULL && def->label_name != NULL)
    {
      printf ("les valeurs dans def %s %d \n", def->label_name, def->nb_line);
      def = def->next;
    }
}
*/
int		check_call_exist(t_cmd *cmd)
{
  t_pile	*call;
  t_pile	*def;
  int		cpt;

  cpt = 0;
  call = cmd->call;
  def = cmd->def;
  /*write_struct(call, cmd->def);*/
  while (call != NULL && call->label_name != NULL)
    {
      while (def != NULL && def->label_name != NULL && cpt != 1)
	{
	  /*	  printf ("->%s<----->%s<-  \n", def->label_name, call->label_name);*/
	  if (strcmpend(def->label_name, call->label_name) == 0)
	    cpt = 1;
	  else
	    def = def->next;
	}
      if (cpt != 1)
	return (-1);
      def = cmd->def;
      call = call->next;
      cpt = 0;
      /*      printf ("verif one");*/
    }
  cmd = cmd->head;
  return (0);
}

t_cmd		*check_only_label(t_cmd *cmd)
{
  t_pile       	*check;
  t_pile	*start;

  start = cmd->def;
  if (check_call_exist(cmd) == -1)
    return (NULL);
  cmd = cmd->head;
  if (cmd->def->next == NULL)
    return (cmd);
  while (cmd->def->next != NULL)
    {
      check = cmd->def;
      while (check->next != NULL)
	{
	  check = check->next;
	  if (strcmpend(cmd->def->label_name, check->label_name) != -1)
	    return (NULL);
	}
      cmd->def = cmd->def->next;
    }
  cmd = cmd->head;
  cmd->def = start;
  return (cmd);
}

int		label_and_prog_size(t_cmd *cmd, int *prog_size)
{
  int		i;
  t_cmd		*head;

  /*printf ("%s \n", cmd->head->line);*/
  head = cmd;
  *prog_size = 0;
  if ((cmd = check_only_label(cmd)) == NULL)
    return (-1);
  cmd = cmd->head;
  while (cmd != NULL)
    {
      i = -1;
      /*printf ("cmd->type writting %d \n",cmd->type); */
      /*write(1, "inf", 3);*/
      if (cmd->type == TYPE_LINE_CODE)
	*prog_size += cmd->dot_code_octet;
      else if (cmd->type == TYPE_LINE_CMD || cmd->type == TYPE_LINE_LABEL ||
	       cmd->type == TYPE_LINE_LABEL_CMD)
	while (++i < 3)
	  if (cmd->type_arg[i] < 10)
	    *prog_size += cmd->type_arg[i];
	  else
	    *prog_size += cmd->type_arg[i] - 10;
      cmd = cmd->next;
    }
  cmd = head;
  /*write (1, "sortie", 6);*/
  return (0);
}
