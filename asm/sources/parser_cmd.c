/*
** parser_cmd.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 14:24:56 2016 Grégoire Loens
** Last update Wed Mar 23 12:23:05 2016 
*/

#include	<stddef.h>
#include	"parser.h"
#include	"get_next_line.h"
#include	"asm.h"

int		type_of_cmd(char *line)
{
  char		**cmd;

  if ((cmd = set_cmd_part1()) == NULL)
    return (-1);
  if (line[0] == COMMENT_CHAR || line[0] == '\0')
    return (TYPE_LINE_EMPTY);
  if (line[0] == '.')
    {
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
    if (gst_cmd(line, cmd) == 0)
      return (TYPE_LINE_CMD);
    else if (gst_label(line) == 1)
      return(TYPE_LINE_LABEL);
    else if (gst_label(line) == 2)
      return (TYPE_LINE_LABEL_CMD);
  return (error_message("can't reconize the command "));
}

int		parsing(char *line, int nbr_line)
{
  int		type;

  type = 0;
  (void)nbr_line;
  if ((line = my_isspace(line)) == NULL)
    return(error_message_parser("epurstr failed line ", nbr_line));
  /*#include <stdio.h>*/
    /*  printf("my_isspace result->%s<< a la ligne %d<", line, nbr_line);*/
  if ((type = type_of_cmd(line)) == -1)
    return(error_message_line("line ", nbr_line, line));
  /* printf("type cmd %d \n", type);*/
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

int		storage(char *line, int type)
{
  
}

int		verif_cmd_line(int fd)
{
  char		*line;
  unsigned char	stock;
  int		type;
  int		nbr_line;

  nbr_line = 1;
  stock = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      type = parsing(line, nbr_line);
      if (type == -1)
	stock = 1;
      if (stock != 1)
	if (storage(line, type) == -1)
	  return (-1);
      nbr_line++;
    }
  write_cor(
  return (0);
}
