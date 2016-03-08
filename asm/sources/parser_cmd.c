/*
1;2802;0c** parser_cmd.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 14:24:56 2016 Grégoire Loens
** Last update Tue Mar  8 15:27:33 2016 Grégoire Loens
*/

#include	"parser.h"
#include	"asm.h"

int		type_of_cmd(char *line)
{
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
    {
      if (gst_label(line) == 1)
	return(TYPE_LINE_LABEL);
      else if (gst_label(line) == 2)
	return (TYPE_LINE_LABEL_CMD);
      else if (gst_cmd(line) == 0)
	return (TYPE_LINE_CMD);
    }
}

int		parsing(char *line)
{
  int		type;

  if (line = my_isspace(line) == NULL)
    return(error_message_parser("Syntax error line ", nbr_line));
  if ((type == type_of_cmd(line)) == -1)
    return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_NAME)
    if (check_dot_name(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_COMMENT)
    if (check_dot_comment(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_EXTEND)
    if (check_dot_extend(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_CODE)
    if (check_dot_code(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_CMD)
    if (check_cmd(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_LABEL)
    if (check_label(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  if (type == TYPE_LINE_LABER_CMD)
    if (check_label_cmd(line) == -1)
      return(error_message_parser("Syntax error line ", nbr_line));
  return (type);
}

  /*if (verif_nbr_cmd(line) == -1)
    return (error_message_parser("Syntax error line ", nbr_line));
  if (verif_nbr_arg(line) == -1)
    return (error_message_parser("Syntax error line ", nbr_line));
  if (command_with_arg(line) == -1)
    return (error_message_parser("Syntax error line ", nbr_line));
  if (use_of_arg(line) == -1)
  return (error_message_parser("Syntax error line ", nbr_line));  */

int		verif_cmd_line(int fd, int nbr_line)
{
  char		*line;
  int		type;

  while ((line = get_next_line(fd)) != NULL)
    {

      type = parsing(line);
    }
}
