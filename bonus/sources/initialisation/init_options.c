/*
** init_options.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 17:42:18 2016 corsin_a
** Last update Sun Mar 27 06:21:44 2016 corsin_a
*/

#include	<stddef.h>
#include	<stdio.h>
#include	"corewar.h"

static void	clean_champion(t_options_champion	*champion)
{
  champion->name = NULL;
  champion->nb = -1;
  champion->ad = -1;
}

static int	is_options(t_options	*options,
			   char		*opt,
			   char		*next)
{
  if (my_strcmp(opt, "-dump"))
    {
      if (options->dump != -1 || next == NULL ||
	  !my_getnbr(next, &(options->dump)))
	return (error_message("Error with '-dump'"));
      return (SUCCESS);
    }
  else if (my_strcmp(opt, "-n"))
    {
      if (options->champion[options->nb_champion].nb != -1 || next == NULL ||
	  !my_getnbr(next, &(options->champion[options->nb_champion].nb)))
	return (error_message("Error with '-n'"));
      return (SUCCESS);
    }
  else if (my_strcmp(opt, "-a"))
    {
      if (options->champion[options->nb_champion].ad != -1 || next == NULL ||
	  !my_getnbr(next, &(options->champion[options->nb_champion].ad)))
	return (error_message("Error with '-a'"));
      return (SUCCESS);
    }
  return (CONTINUE);
}

static int	is_champion(t_options	*options,
			    char	*champ)
{
  options->champion[options->nb_champion].name = champ;
  ++(options->nb_champion);
  if (options->nb_champion > 4)
    return (ERROR);
  if (options->nb_champion != 4)
    clean_champion(&(options->champion[options->nb_champion]));
  return (SUCCESS);
}

int		init_options(int	argc,
			     char	*argv[],
			     t_options	*options)
{
  int		cpt;
  int		ret;

  cpt = 1;
  options->nb_champion = 0;
  options->dump = -1;
  clean_champion(&(options->champion[0]));
  while (cpt < argc)
    {
      if ((ret = is_options(options, argv[cpt], argv[cpt + 1])) == ERROR)
	return (ERROR);
      if (ret == CONTINUE)
	if (options->nb_champion > 3 ||
	    is_champion(options, argv[cpt]) != SUCCESS)
	    return (error_message("Too much champions"));
      if (ret == SUCCESS)
	++cpt;
      ++cpt;
    }
  if (options->nb_champion == 0 || cpt == 1)
    return (error_message("Need at least one champion"));
  return (SUCCESS);
}
