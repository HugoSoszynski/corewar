/*
** write_file.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 19:33:51 2016 
** Last update Sun Mar 27 22:08:58 2016 
*/

#include	<unistd.h>
#include	"asm.h"
#include	"pile_label.h"
#include	"parser.h"
#include	"op.h"

int		write_arg1(int fd, t_cmd *cmd)
{
  if (cmd->opcode == (OP_STI / 2 + 1))
    {
      write(fd, &(cmd->arg[0]), 1);
      my_reverse_bytes(&(cmd->arg[1]), 2);
      my_reverse_bytes(&(cmd->arg[2]), 2);
      write(fd, &(cmd->arg[1]), 2);
      write(fd, &(cmd->arg[2]), 2);
    }
  else if (cmd->opcode == (OP_LDI / 2 + 1) || cmd->opcode == (OP_LLDI / 2 + 1))
    {
      my_reverse_bytes(&(cmd->arg[0]), 2);
      my_reverse_bytes(&(cmd->arg[1]), 2);
      write(fd, &(cmd->arg[0]), 2);
      write(fd, &(cmd->arg[1]), 2);
      write(fd, &(cmd->arg[2]), 1);
    }
  else if (cmd->opcode == (OP_FORK / 2 + 1) || cmd->opcode == (OP_LFORK / 2 + 1) || cmd->opcode == (OP_ZJMP / 2 + 1))
    {
      my_reverse_bytes(&(cmd->arg[0]), 2);
      write(fd, &(cmd->arg[0]), 2);      
    }
  else
    return (1);
  return (0);
}

void		write_arg(int fd, t_cmd *cmd)
{
  int		cpt;

  cpt = -1;
  if (write_arg1(fd, cmd) == 0)
    return ;
  else if (cmd->opcode == (OP_LIVE / 2 + 1))
    {
      my_reverse_bytes(&(cmd->arg[0]), 4);
      write(fd, &(cmd->arg[0]), 4);            
    }
  else
    while (++cpt < 3)
      {
	if (cmd->type_arg[cpt] == 0)
	  return ;
	if (cmd->type_arg[cpt] == 12 || cmd->type_arg[cpt] == 14)
	  cmd->type_arg[cpt] -= 10;
	if (cmd->type_arg[cpt] > 1)
	  if (IS_LIT_ENDIAN)
	    my_reverse_bytes(&(cmd->arg[cpt]), cmd->type_arg[cpt]);
	write(fd, &(cmd->arg[cpt]), cmd->type_arg[cpt]);
      }
}

void		write_dot_code(int fd, t_cmd *cmd)
{
  int		cpt;
  unsigned char	c;
  
  cpt = 0;
  while (cmd->line[cpt] != '\0')
    {
      c = my_getnbr_base(&(cmd->line[cpt]), "0123456789ABCDEF");
      write(fd, &c, 1); 
      if (cmd->line[cpt + 1] != '\0' && cmd->line[cpt + 2] != '\0' && cmd->line[cpt + 3] != '\0')
	cpt += 3;
      else
	return ;
    }
}

int		write_file(int fd, t_cmd *cmd)
{
  t_cmd		*rescue;

  cmd = cmd->head;
  while (cmd != NULL)
    {
      if (cmd->type == TYPE_LINE_CMD || cmd->type == TYPE_LINE_LABEL_CMD)
	{
	  cmd->opcode = cmd->opcode / 2 + 1;
	  write(fd, &cmd->opcode, 1);
	  if (cmd->octet_codage != 0)
	    write(fd, &cmd->octet_codage, 1);
	  write_arg(fd, cmd);
	}
      else if (cmd->type == TYPE_LINE_CODE)
	write_dot_code(fd, cmd);
      rescue = cmd;
      cmd = cmd->next;
    }
  rescue = rescue->head;
  free_struct(rescue);
  return (0);
}
