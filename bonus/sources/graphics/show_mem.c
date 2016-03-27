/*
** show_mem.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 04:07:00 2016 corsin_a
** Last update Sun Mar 27 06:24:31 2016 corsin_a
*/

#include		"corewar.h"

static void		put_octet(t_bonus		*data,
				  t_bunny_position	*pos,
				  t_color		*color)
{
  int			i;
  t_bunny_position	tmp;

  i = 0;
  tmp.x = pos->x;
  tmp.y = pos->y;
  while (i < 5 * 5)
    {
      if (i % 5 == 0 && i != 0)
	{
	  tmp.x = pos->x;
	  ++tmp.y;
	}
      tekpixel(data->pix, &tmp, color);
      ++i;
      ++tmp.x;
    }

}

static void		print_mem(t_bonus	*data)
{
  int			cpt;
  t_bunny_position	pos;
  t_color		color;

  cpt = 0;
  pos.x = 33;
  pos.y = 89;
  while (cpt < MEM_SIZE)
    {
      if (data->corewar.mem_champ[cpt] == 0)
	color.full = 4285945600;
      else
	color.full = WHITE;
      if (cpt % 128 == 0 && cpt != 0)
	{
	  pos.x = 33;
	  pos.y += 7;
	}
      put_octet(data, &pos, &color);
      pos.x += 7;
      ++cpt;
    }
}

static void		print_process(t_bonus	*data)
{
  t_process_list	*current;
  t_color		color;
  t_bunny_position	pos;

  color.full = RED;
  current = data->corewar.process_list;
  while (current != NULL)
    {
      pos.x = current->process.pc % 128 * 7 + 33;
      pos.y = current->process.pc / 128 * 7 + 89;
      put_octet(data, &pos, &color);
      current = current->next;
    }
}

void			show_mem(t_bonus	*data)
{
  print_mem(data);
  print_process(data);
}
