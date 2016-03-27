/*
** my_strlen.c for tekgui in /home/corsin_a/Travail/Infographie/gfx_tekgui/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Feb 15 12:53:45 2016 corsin_a
** Last update Mon Feb 15 12:54:33 2016 corsin_a
*/

int	my_strlen(const char *str)
{
  int	cpt;

  cpt = 0;
  while (str[cpt++]);
  return (cpt);
}
