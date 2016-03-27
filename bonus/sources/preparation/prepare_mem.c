/*
** prepare_mem.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:44:00 2016 corsin_a
** Last update Sun Mar 27 06:34:02 2016 corsin_a
*/

#include	"corewar.h"

void		prepare_mem(t_corewar	*corewar)
{
  int			cpt;
  int			cpt_prog;

  my_init_tab(corewar->mem, MEM_SIZE);
  my_init_tab(corewar->mem_champ, MEM_SIZE * sizeof(int));
  cpt = 0;
  while (cpt < corewar->nb_champions)
    {
      cpt_prog = 0;
      while (cpt_prog < corewar->champion[cpt].header.prog_size)
	{
	  corewar->mem[(cpt_prog + corewar->champion[cpt].address) % MEM_SIZE]
	  = corewar->champion[cpt].prog[cpt_prog];
	  corewar->mem_champ[(cpt_prog + corewar->champion[cpt].address) % MEM_SIZE]
	  = corewar->champion[cpt].color;
	  ++cpt_prog;
	}
      ++cpt;
    }
}
