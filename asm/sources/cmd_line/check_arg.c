/*
** check_arg.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar 21 17:40:54 2016
** Last update Mon Mar 21 18:24:39 2016 Grégoire Loens
*/

#include	"parser.h"
#include	"asm.h"

int		arg_direct(char *arg_file)
{
  int		cpt;

  cpt = 1;
  if (arg_file[cpt - 1] != '%')
    return (-1);
  if (arg_file[cpt] == '\0')
    return (-1);
  while (arg_file[cpt] != 0)
    {
      if(arg_file[cpt] < '0' && arg_file[cpt] > '9')
	return (-1);
      else
	cpt++;
    }
  return (0);
}

int		arg_indirect(char *arg_file)
{
  int		cpt;

  cpt = 0;
  if (arg_file[cpt] == '%')
    {
      if (arg_file[cpt + 1] != ':' || arg_file[cpt + 2] == '\0')
	return (-1);
      if (arg_register(arg_file) == 0)
	return (0);
      if (my_issalpha(arg_file + 2) == 0)
	return (0);
      if (my_isnum(arg_file + 2) == 0)
	return (0);
      return (-1);
    }
  else
    if (my_isnum(arg_file) == 1)
	return(0);
}

int		arg_register(char *arg_file)
{
  int		cpt;

  cpt = 0;
  if (arg_file[cpt] != 'r')
    return (-1);
  else
    {
      cpt++;
      if ((((arg_file[cpt] > '1' && arg_file[cpt] < '7') && arg_file[cpt] <=
	    '9') && arg_file[cpt + 1] == '\0') || (arg_file[cpt] == '1' &&
	   (arg_file[cpt + 1] >= '0' && arg_file[cpt + 1] <= "6")))
	return (0);
      else
	return (-1);
    }
}

int		check_is_type(char *arg_file, char *type)
{
  if (type[0] == 'd')
    if (arg_direct(arg_file) == 0)
      return (0);
  if (type[0] == 'i')
    if (arg_indirect(arg_file) == 0)
      return (0);
  if (type[0] == 'r')
    if (arg_register(arg_file) == 0)
      return (0);
  return (-1);
}

int             check_one_arg(char *arg_file, char *arg_cmd)
{
  int           nb_type;
  int           cpt;
  char          **type_of_arg_cmd;

  cpt = 0;
  type_of_arg_cmd = my_str_to_wordtab(arg_cmd, &nb_type, "/");
  while (cpt < nb_type)
    {
      if ((check_is_type(arg_file, type_of_arg_cmd[cpt])) == 0)
	return (0);
      cpt++;
    }
  return (-1);
}
