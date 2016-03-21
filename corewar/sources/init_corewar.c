/*
** init_corewar.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:51:42 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 12:00:57 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	"corewar.h"

void		my_init_tab(void *_tab, size_t size)
{
  size_t	cpt;
  char		*tab;

  tab = _tab;
  cpt = 0;
  while (cpt < size)
    {
      tab[cpt] = 0;
      cpt++;
    }
}

int		init_corewar(t_corewar *corewar)
{
  my_init_tab(corewar, sizeof(corewar));
  corewar->cycle_to_die = CYCLE_TO_DIE;
  return (SUCCESS);
}
