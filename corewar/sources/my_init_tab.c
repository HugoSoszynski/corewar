/*
** my_init_tab.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 22 18:55:03 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 21:53:59 2016 corsin_a
*/

#include	<stddef.h>

void		my_init_tab(void *_tab, size_t size)
{
  char		*tab;
  size_t	cpt;

  cpt = 0;
  tab = (char *)_tab;
  while (cpt < size)
    {
      tab[cpt] = 0;
      cpt++;
    }
}
