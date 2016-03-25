/*
** my_strcmp.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 18:02:22 2016 corsin_a
** Last update Mon Mar 21 18:03:46 2016 corsin_a
*/

int		my_strcmp(char	*str1,
			  char	*str2)
{
  int		cpt;

  cpt = 0;
  while (str1[cpt] && str2[cpt] && str1[cpt] == str2[cpt])
    ++cpt;
  if (str1[cpt] != str2[cpt])
    return (0);
  return (1);
}
