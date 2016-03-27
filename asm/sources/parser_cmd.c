/*
** parser_cmd.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 14:24:56 2016 Grégoire Loens
** Last update Sun Mar 27 23:22:34 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"op.h"
#include	"parser.h"
#include	"pile_label.h"
#include	"get_next_line.h"
#include	"asm.h"

int		type_of_cmd_extend(char *line, char **cmd)
{
  if (gst_cmd(line, cmd) == 0)
    {
      free_tab_cmd(cmd);
      return (TYPE_LINE_CMD);
    }
  else if (gst_label(line) == 1)
    {
      free_tab_cmd(cmd);
      return(TYPE_LINE_LABEL);
    }
  else if (gst_label(line) == 2)
    {
      free_tab_cmd(cmd);
      return (TYPE_LINE_LABEL_CMD);
    }
  free_tab_cmd(cmd);
  return (error_message("can't reconize the command "));
}

int		type_of_cmd(char *line)
{
  char		**cmd;

  if ((cmd = set_cmd_part1()) == NULL)
    return (-1);
  if (line[0] == COMMENT_CHAR || line[0] == '\0')
    {
      free_tab_cmd(cmd);
      return (TYPE_LINE_EMPTY);
    }
  if (line[0] == '.')
    {
      free_tab_cmd(cmd);
      if (gst_name(line) == 0)
	return (TYPE_LINE_NAME);
      else if (gst_comment(line) == 0)
	return (TYPE_LINE_COMMENT);
      else if (gst_code(line) == 0)
	return (TYPE_LINE_CODE);
      else if (gst_extend(line) == 0)
	return (TYPE_LINE_EXTEND);
    }
  else
    return (type_of_cmd_extend(line, cmd));
  return (-1);
}

int		parsing(char *line, int nbr_line)
{
  int		type;

  type = 0;
  (void)nbr_line;
  if ((type = type_of_cmd(line)) == -1)
    return(error_message_line("line ", nbr_line, line));
  if (type == TYPE_LINE_NAME)
    if (check_dot_name(line) == -1)
      return(error_message_line("line ", nbr_line, line));
  if (type == TYPE_LINE_COMMENT)
    if (check_dot_comment(line) == -1)
      return(error_message_line("line ", nbr_line, line));
  if (type == TYPE_LINE_EXTEND)
    if (check_dot_extend(line) == -1)
      return(error_message_line("line ", nbr_line, line));
  if (type == TYPE_LINE_CODE)
    if (check_dot_code(line) == -1)
      return(error_message_line("line ", nbr_line, line));
  if (type == TYPE_LINE_CMD)
    if (check_cmd(line) == -1)
      return(error_message_line("line ", nbr_line, line));
  if (type == TYPE_LINE_LABEL_CMD)
    if (check_label_cmd(line) == -1)
      return(error_message_line("line ", nbr_line, line));
  return (type);
}

int		storage(int nbr_line, char *line, int type, t_cmd *stock_arg)
{
  stock_arg->type = type;
  stock_arg->line = line;
  stock_arg->nbr_line = nbr_line;
  if (type == TYPE_LINE_NAME || type ==
      TYPE_LINE_COMMENT || type == TYPE_LINE_EXTEND)
    return (0);
  else if (type == TYPE_LINE_CODE)
    {
      if ((stock_arg = stock_code(line, stock_arg)) == NULL)
	return (-1);
    }
  else if (type == TYPE_LINE_CMD)
    {
      if ((stock_arg = stock_cmd(line, stock_arg)) == NULL)
	return (-1);
    }
  else if (type == TYPE_LINE_LABEL)
    {
      if ((stock_arg = stock_label(line, stock_arg)) == NULL)
	return (-1);
    }
  else
    if ((stock_arg = stock_label_cmd(line, stock_arg)) == NULL)
      return (-1);
  return (0);
}

int		verif_cmd_line(int fd, char *filename)
{
  t_cmd		*stock_arg;

  if ((stock_arg = init_first_cmd()) == NULL)
    return (error_message("initialise conflict for stocking argument"));
  if (parser_cmd_extend(&stock_arg, fd, 0, 1) == -1)
    {
      stock_arg = stock_arg->head;
      free_struct(stock_arg);
      return (-1);
    }
  stock_arg = stock_arg->head;
  write_cor(stock_arg, filename);
  return (0);
}
