/*
** fill_chapions.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 22:09:36 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 22:33:02 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

static void	set_address_one_2(t_corewar	*corewar,
				  int		set,
				  int		free_size)
{
  int		cpt;
  int		current_address;

  current_address = corewar->champion[set].address;
  cpt = -1;
  while (++cpt < corewar->nb_champions)
    {
      corewar->champion[(cpt + set) % corewar->nb_champions].address
      = current_address;
      current_address = (corewar->champion[(cpt + set) %
			 corewar->nb_champions].header.prog_size
			 + free_size + current_address) % MEM_SIZE;
    }
}

static void	set_address_one(t_corewar 	*corewar)
{
  int		cpt;
  int		free_size;
  int		set;

  free_size = MEM_SIZE;
  cpt = -1;
  set = -1;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].address != -1)
	set = cpt;
      free_size -= corewar->champion[cpt].header.prog_size;
    }
  free_size /= corewar->nb_champions;
  if (set == -1)
    {
      corewar->champion[0].address = 0;
      set = 0;
    }
  set_address_one_2(corewar, set, free_size);
}

int		fill_champions(t_corewar *corewar)
{
  int		cpt;
  int		tmp;
  int		nb_set;

  tmp = 666;
  cpt = -1;
  nb_set = 0;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].nb_champion == -1)
	{
	  corewar->champion[cpt].nb_champion = tmp;
	  tmp = (tmp * 666) % 9999;
	}
      if (corewar->champion[cpt].address != -1)
	++nb_set;
    }
  if (nb_set == 0 || nb_set == 1)
    set_address_one(corewar);
  else
    return (error_message("prout"));
  return (SUCCESS);
}
