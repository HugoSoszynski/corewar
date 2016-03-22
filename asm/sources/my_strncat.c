/*
** my_strncat.c for blablabla in /home/corsin_a/rendu/Piscine_C_J07
**
** Made by Corsini Sylvain
** Login   <corsin_a@epitech.net>
**
** Started on  Tue Oct  6 15:37:05 2015 Corsini Sylvain
** Last update Thu Jan  7 16:00:16 2016 corsin_a
*/

char		*my_strncat(char *dest, char *src, int nbr)
{
  int		cpt_dest;
  int		cpt_src;

  cpt_src = 0;
  cpt_dest = 0;
  while (dest[cpt_dest] != '\0')
    ++cpt_dest;
  while (src[cpt_src] != '\0' && nbr-- > 0)
    dest[cpt_dest++] = src[cpt_src++];
  dest[cpt_dest] = '\0';
  return (dest);
}
