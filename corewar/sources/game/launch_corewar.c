/*
** launch_corewar.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 22:17:05 2016 corsin_a
** Last update Sun Mar 27 21:21:55 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

static int	test_champ_cycles(t_corewar *corewar, int *live)
{
  int		cpt;

  cpt = 0;
  while (cpt < corewar->nb_champions)
    {
      if (corewar->champions_alive[cpt] == IS_RUN)
	{
	  corewar->champions_alive[cpt] = IS_DEAD;
	  print_champ_dead(&(corewar->champion[cpt]), cpt);
	  if ((corewar->process_list =
	       kill_zombies(corewar->process_list,
			    corewar->champion[cpt].nb_champion)) == NULL)
	    return (SUCCESS);
	}
      else if (corewar->champions_alive[cpt] == IS_ALIVE)
	{
	  corewar->champions_alive[cpt] = IS_RUN;
	  *live += 1;
	}
      ++cpt;
    }
  return (CONTINUE);
}

static int	game_is_not_finished(t_corewar	*corewar)
{
  int		live;

  live = 0;
  if (corewar->cycle_passed < corewar->cycle_to_die)
    return (CONTINUE);
  if (test_champ_cycles(corewar, &live) == SUCCESS)
    return (SUCCESS);
  if (live == 1 && corewar->nb_champions != 1)
    {
      check_winner(corewar);
      return (SUCCESS);
    }
  corewar->cycle_passed = 0;
  return (CONTINUE);
}

int		launch_corewar(t_corewar	*corewar)
{
  while (game_is_not_finished(corewar) == CONTINUE)
    {
      execute_process(corewar);
      ++corewar->cycle_passed;
      ++corewar->actual_cycle;
      corewar->cycle_to_die = (CYCLE_TO_DIE - corewar->live_nb /
			       NBR_LIVE * CYCLE_DELTA);
      if (corewar->cycle_to_die <= 0)
	return (SUCCESS);
    }
  return (SUCCESS);
}
