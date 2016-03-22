/*
** init_corewar.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:51:42 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 14:47:14 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

#include	<stdio.h>

static void	print_options(t_options *options)
{
  int		cpt = 0;

  printf("\n-----\nOPTIONS\n-----\n");
  while (cpt < options->nb_champion)
    {
      printf("name : %s\nnb : %d\nad : %d\n\n",
	     options->champion[cpt].name, options->champion[cpt].nb,
	     options->champion[cpt].ad);
      ++cpt;
    }
}

static void	print_corewar(t_corewar *corewar)
{
  int		cpt = 0;

  printf("\n-----\nCOREWAR\n-----\n");
  while (cpt < corewar->nb_champions)
    {
      printf("ad : %d\nnb : %d\n",
	     corewar->champion[cpt].address, corewar->champion[cpt].nb_champion);
      printf("header name : %s\nheader size prog : %d\n\n",
	     corewar->champion[cpt].header.prog_name,
	     corewar->champion[cpt].header.prog_size);
      ++cpt;
    }
}

int		init_corewar(t_corewar *corewar,
			     int ac, char **av)
{
  t_options	options;

  if (init_options(ac, av, &options) != SUCCESS)
    {
            return (ERROR);
    }
  if (init_champ(corewar, &options) != SUCCESS)
    {
            printf("here\n");
      return (ERROR);
    }
  print_options(&options);
  print_corewar(corewar);
  if (champ_imcomp(corewar) != SUCCESS)
    return (ERROR);
  if (fill_champions(corewar) != SUCCESS)
    return (ERROR);
  print_corewar(corewar);
  return (SUCCESS);
}
