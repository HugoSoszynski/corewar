/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 20:47:55 2016 corsin_a
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"corewar.h"

static void	free_corewar(t_bonus	*data)
{
  int		cpt;

  cpt = 0;
  while (cpt < data->corewar.nb_champions)
    {
      free(data->corewar.champion[cpt].prog);
      ++cpt;
    }
  free(data->corewar.op_tab);
  bunny_stop(data->win);
  bunny_delete_clipable(&data->pix->clipable);
  bunny_delete_clipable(&data->bg->clipable);
  bunny_delete_clipable(&data->cadre->clipable);
  bunny_delete_clipable(&data->titre->clipable);
  bunny_delete_clipable(&data->font->clipable);
}

static void	start_game(t_bonus	*data)
{
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data->win, 250, data);
  bunny_set_loop_main_function(leaderboard);
  bunny_loop(data->win, 250, data);
}

int		main(int 	argc,
		     char 	*argv[],
		     char	*arge[])
{
  t_bonus	data;

  if (check_h() != SUCCESS)
    return (ERROR);
  if (my_getenv(arge, "TERM") == NULL || my_getenv(arge, "DISPLAY") == NULL)
    return (ERROR);
  if (there_is_help(argc, argv) == SUCCESS)
    {
      aff_help(0);
      return (SUCCESS);
    }
  if (init_corewar(&data, argc, argv) != SUCCESS)
    return (aff_help(1));
  if (prepare_corewar(&data.corewar) != SUCCESS)
    return (ERROR);
  start_game(&data);
  free_processlist(data.corewar.process_list);
  free_corewar(&data);
  return (SUCCESS);
}
