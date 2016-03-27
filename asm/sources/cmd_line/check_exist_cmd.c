/*
** check_exist_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
**
** Made by pillon_m
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 19:23:44 2016 Maxime Pillon
** Last update Sun Mar 27 23:32:49 2016 Hugo SOSZYNSKI
*/

#include	"parser.h"
#include	"asm.h"

int		check_exist_cmd(char *line,
				char **cmd)
{
  int		cpt;

  cpt = 0;
  while (cpt < 31)
    {
      if (my_strcmp(line, cmd[cpt]) == 0)
	return (cpt);
      cpt += 2;
    }
  return (-1);
}
