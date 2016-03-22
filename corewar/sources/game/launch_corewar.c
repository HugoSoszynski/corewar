/*
** launch_corewar.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 22:17:05 2016 corsin_a
** Last update Tue Mar 22 22:45:32 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

static int	game_is_not_finished(t_corewar	*corewar)
{
  int		cpt;
  int		check;

  if (corewar->cycle_passed < corewar->cycle_to_die)
    return (CONTINUE);
  cpt = 0;
  check = 0;
  while (cpt < corewar->nb_champions)
    {
      if (corewar->champions_alive[cpt] != IS_ALIVE)
	{
	  corewar->champions_alive[cpt] = IS_DEAD;
	  ++check;
	}
      ++cpt;
    }
  if (check >= cpt)
    return (SUCCESS);
  corewar->cycle_passed = 0;
  return (CONTINUE);
}

int		launch_corewar(t_corewar	*corewar)
{
  while (game_is_not_finished(corewar) == CONTINUE)
    {
      printf("%ld\n", corewar->actual_cycle);
      ++corewar->cycle_passed;
      ++corewar->actual_cycle;
    }
  return (SUCCESS);
}
