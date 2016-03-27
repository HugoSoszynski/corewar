/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 03:13:57 2016 corsin_a
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
}

int		main(int 	argc,
		     char 	*argv[])
{
  t_bonus	data;

  if (REG_NUMBER < 1 || REG_SIZE != 4 || CYCLE_TO_DIE < 1
      || CYCLE_DELTA < 0 || NBR_LIVE < 1 || PROG_NAME_LENGTH < 1
      || COMMENT_LENGTH < 1 || IND_SIZE < 1 || DIR_SIZE < 1
      || T_REG < 1 || T_DIR < 1 || T_IND < 1)
    return (error_message("Error op.h"));
  if (there_is_help(argc, argv) == SUCCESS)
    {
      aff_help(0);
      return (SUCCESS);
    }
  if (init_corewar(&data, argc, argv) != SUCCESS)
    return (aff_help(1));
  if (prepare_corewar(&data.corewar) != SUCCESS)
    return (ERROR);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, 250, &data);
  free_processlist(data.corewar.process_list);
  free_corewar(&data);
  return (SUCCESS);
}
