/*
** init_graphics.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/initialisation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Fri Mar 25 17:12:12 2016 corsin_a
** Last update Sun Mar 27 01:47:48 2016 corsin_a
*/

#include	"corewar.h"

int		init_graphics(t_bonus	*data)
{
  if ((data->win = bunny_start(SCREEN_WIDTH, SCREEN_HEIGHT,
			       SCREEN_FULLSCREEN, SCREEN_NAME)) == NULL)
    return (ERROR);
  if ((data->pix = bunny_new_pixelarray(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (ERROR);
  if ((data->cadre = bunny_load_pixelarray("ressources/cadre.png")) == NULL)
    return (ERROR);
  if ((data->titre = bunny_load_pixelarray("ressources/titre.png")) == NULL)
    return (ERROR);
  if ((data->bg = bunny_load_pixelarray("ressources/bg.png")) == NULL)
    return (ERROR);
  if ((data->font = bunny_load_pixelarray("ressources/font2.png")) == NULL)
      return (ERROR);
  return (SUCCESS);
}
