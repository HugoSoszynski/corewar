/*
** print_champions_states.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sat Mar 26 19:13:09 2016 Hugo SOSZYNSKI
** Last update Sat Mar 26 21:33:39 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	"corewar.h"

void		print_champ_alive(t_champion *champion, int nb)
{
  int		cpt;

  cpt = -1;
  while (champion->header.prog_name[++cpt] != '\0');
  write(1, "The player ", 11);
  nb += '1';
  write(1, &nb, 1);
  write(1, "(", 1);
	write(1, champion->header.prog_name, cpt);
	write(1, ") is alive !\n", 13);
}

void		print_champ_dead(t_champion *champion, int nb)
{
  int		cpt;

  cpt = -1;
  while (champion->header.prog_name[++cpt] != '\0');
  write(1, "The player ", 11);
  nb += '1';
  write(1, &nb, 1);
  write(1, "(", 1);
	write(1, champion->header.prog_name, cpt);
	write(1, ") is dead !\n", 12);
}

void		print_champ_win(t_champion *champion, int nb)
{
  int		cpt;

  cpt = -1;
  while (champion->header.prog_name[++cpt] != '\0');
  write(1, "The player ", 11);
  nb += '1';
  write(1, &nb, 1);
  write(1, "(", 1);
	write(1, champion->header.prog_name, cpt);
	write(1, ") won !\n", 8);
}

int		check_winner(t_corewar *corewar)
{
  int		cpt;

  if (corewar->nb_champions < 2)
    return (CONTINUE);
  cpt = -1;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champions_alive[cpt] != IS_DEAD)
	{
	  print_champ_win(&(corewar->champion[cpt]), cpt);
	  return (SUCCESS);
	}
    }
  return (SUCCESS);
}
