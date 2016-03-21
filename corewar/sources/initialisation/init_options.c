/*
** init_options.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 17:42:18 2016 corsin_a
** Last update Mon Mar 21 18:26:57 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

static void	clean_champion(t_options_champion	*champion)
{
  champion->name = NULL;
  champion->nb = -1;
  champion->ad = -1;
}

int		init_options(int	argc,
			     char	*argv[],
			     t_options	*options)
{
  int		cpt;

  cpt = 1;
  options->nb_champion = 0;
  options->dump = -1;
  clean_champion(&options->champion[0]);
  while (cpt < argc)
    {
      if (my_strcmp(argv[cpt], "-dump"))
	{
	  if (!my_getnbr(argv[cpt + 1], &options->dump))
	    return (ERROR);
	  ++cpt;
	}
      else if (my_strcmp(argv[cpt], "-n"))
	{
	  if (!my_getnbr(argv[cpt + 1], &options->champion[options->nb_champion].nb))
	    return (ERROR);
	  ++cpt;
	}
      else if (my_strcmp(argv[cpt], "-a"))
	{
	  if (!my_getnbr(argv[cpt + 1], &options->champion[options->nb_champion].ad))
	    return (ERROR);
	  ++cpt;
	}
      else
	{
	  options->champion[options->nb_champion].name = argv[cpt];
	  ++options->nb_champion;
          if (options->nb_champion > 3)
	    return (error_message("Too much champions"));
          clean_champion(&options->champion[options->nb_champion]);
	}
      ++cpt;
    }
  return (SUCCESS);
}
