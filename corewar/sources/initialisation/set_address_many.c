/*
** set_address_many.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sat Mar 26 22:54:27 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 00:47:07 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

static void	calc_position(t_corewar *corewar, int *champ_set,
			      int size1, int size2)
{
  int		mem;

  mem = MEM_SIZE;
  if (corewar->champion[champ_set[2]].header.prog_size >= size1)
    {
      corewar->champion[champ_set[2]].address =
      (corewar->champion[champ_set[0]].address +
       corewar->champion[champ_set[0]].header.prog_size +
       (size1 - corewar->champion[champ_set[2]].header.prog_size) / 2) % mem;
      corewar->champion[champ_set[3]].address =
      (corewar->champion[champ_set[1]].address +
       corewar->champion[champ_set[1]].header.prog_size +
       (size2 - corewar->champion[champ_set[3]].header.prog_size) / 2) % mem;
    }
  else
    {
      corewar->champion[champ_set[3]].address =
      (corewar->champion[champ_set[0]].address +
       corewar->champion[champ_set[0]].header.prog_size +
       (size2 - corewar->champion[champ_set[3]].header.prog_size) / 2) % mem;
      corewar->champion[champ_set[2]].address =
      (corewar->champion[champ_set[1]].address +
       corewar->champion[champ_set[1]].header.prog_size +
       (size1 - corewar->champion[champ_set[2]].header.prog_size) / 2) % mem;
    }
}

void		address_2_setand_left(t_corewar *corewar)
{
  int		champ_set[4];
  int		cpt;
  int		size1;
  int		size2;

  cpt = -1;
  size1 = 0;
  size2 = 2;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].address != -1)
	champ_set[size1++] = cpt;
      else
	champ_set[size2++] = cpt;
    }
  size1 = ((corewar->champion[champ_set[1]].address +
	   corewar->champion[champ_set[1]].header.prog_size) -
	   (corewar->champion[champ_set[0]].address +
	    corewar->champion[champ_set[0]].header.prog_size));
  size2 = ((corewar->champion[champ_set[0]].address +
	    corewar->champion[champ_set[0]].header.prog_size) -
	   (corewar->champion[champ_set[1]].address +
	    corewar->champion[champ_set[1]].header.prog_size));
  calc_position(corewar, champ_set, size1, size2);
}
