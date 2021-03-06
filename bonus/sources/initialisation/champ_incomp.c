/*
** champ_incomp.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 18:45:27 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 14:08:58 2016 corsin_a
*/

#include	"corewar.h"

static int	check_address(t_champion *champ1, t_champion *champ2)
{
  if (champ2->address == -1 || champ1->address == -1)
    return (SUCCESS);
  if (champ1->address == champ2->address)
    return (error_message("Two champions in same memory range"));
  if (champ1->address >= champ2->address && champ1->address <=
      (champ2->address + champ2->header.prog_size))
    return (error_message("Two champions in same memory range"));
  if (champ2->address >= champ1->address && champ2->address <=
      (champ1->address + champ1->header.prog_size))
    return (error_message("Two champions in same memory range"));
  return (SUCCESS);
}

static int	check_champ_values(t_corewar *corewar)
{
  int		cpt;
  int		tmp;

  cpt = 0;
  while (cpt < corewar->nb_champions)
    {
      tmp = cpt + 1;
      while (tmp < corewar->nb_champions)
	{
	  if (corewar->champion[cpt].nb_champion ==
	      corewar->champion[tmp].nb_champion &&
	      corewar->champion[tmp].nb_champion != -1)
	    {
	      return (error_nbr("prog number ",
				corewar->champion[tmp].nb_champion,
				" already used"));
	    }
	  if (check_address(&corewar->champion[cpt],
			    &corewar->champion[tmp]) != SUCCESS)
	    return (ERROR);
	  tmp++;
	}
      cpt++;
    }
  return (SUCCESS);
}

int		champ_imcomp(t_corewar *corewar)
{
  int		cpt;
  int		total_size;

  if (check_champ_values(corewar) != SUCCESS)
    return (ERROR);
  total_size = 0;
  cpt = 0;
  while (cpt < corewar->nb_champions)
    {
      total_size += corewar->champion[cpt].header.prog_size;
      cpt++;
    }
  if (total_size < 0 || total_size >= MEM_SIZE)
    return (error_message("Not enough memory for the champions"));
  return (SUCCESS);
}
