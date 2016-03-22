/*
** fill_chapions.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 22:09:36 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 14:42:12 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

static void	set_address_one(t_corewar *corewar)
{
  int		cpt;
  int		free_size;
  int		set;
  int		current_address;

  free_size = MEM_SIZE;
  cpt = -1;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].address != -1)
	set = cpt;
      free_size -= corewar->champion[cpt].header.prog_size;
    }
  free_size /= corewar->nb_champions;
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

static void	check_set_address(t_corewar *corewar)
{

}

int		fill_champions(t_corewar *corewar)
{
  int		cpt;
  int		tmp;

  tmp = -666;
  cpt = -1;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].nb_champion == -1)
	{
	  corewar->champion[cpt].nb_champion = tmp;
	  tmp -= 9;
	}
    }
}
