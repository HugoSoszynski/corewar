/*
** check_arg.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 17:40:54 2016 
** Last update Mon Mar 21 17:55:05 2016 
*/

#include	"parser.h"
#include	"asm.h"

int		arg_direct(char *arg_file)
{
}

int		arg_indirect(char *arg_file)
{
}

int		arg_register(char *arg_file)
{
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

