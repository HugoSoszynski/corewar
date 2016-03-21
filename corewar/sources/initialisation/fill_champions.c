/*
** fill_chapions.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 22:09:36 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 22:53:48 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

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
