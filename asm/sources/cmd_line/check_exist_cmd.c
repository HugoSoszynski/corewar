/*
** check_exist_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar  7 19:23:44 2016 
** Last update Fri Mar 25 04:22:30 2016 
*/

#include	"parser.h"
#include	"asm.h"

#include	<stdio.h>

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
