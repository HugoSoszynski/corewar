/*
** launch_corewar.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 22:17:05 2016 corsin_a
** Last update Sun Mar 27 07:27:24 2016 corsin_a
*/

#include	"corewar.h"

static int	game_is_not_finished(t_corewar	*corewar)
{
  int		cpt;
  int		live;

  if (corewar->cycle_passed < corewar->cycle_to_die)
    return (CONTINUE);
  cpt = 0;
  live = 0;
  while (cpt < corewar->nb_champions)
    {
      if (corewar->champions_alive[cpt] == IS_RUN)
	{
	  if ((corewar->process_list =
	       kill_zombies(corewar->process_list,
			    corewar->champion[cpt].nb_champion)) == NULL)
	    return (SUCCESS);
	  corewar->champions_alive[cpt] = IS_DEAD;
	}
      else if (corewar->champions_alive[cpt] == IS_ALIVE)
	{
	  corewar->champions_alive[cpt] = IS_RUN;
	  ++live;
	}
      ++cpt;
    }
  if (live == 1 && corewar->nb_champions != 1)
    return (SUCCESS);
  corewar->cycle_passed = 0;
  return (CONTINUE);
}

int		launch_corewar(t_corewar	*corewar)
{
  if (game_is_not_finished(corewar) == CONTINUE)
    {
      execute_process(corewar);
      ++corewar->cycle_passed;
      ++corewar->actual_cycle;
      corewar->cycle_to_die = CYCLE_TO_DIE - corewar->live_nb / NBR_LIVE * CYCLE_DELTA;
      if (corewar->cycle_to_die <= 0)
	return (SUCCESS);
      return (CONTINUE);
    }
  return (SUCCESS);
}
