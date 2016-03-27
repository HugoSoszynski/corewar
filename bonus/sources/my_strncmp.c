/*
** my_strncmp.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 20:59:30 2016 corsin_a
** Last update Sun Mar 27 21:01:33 2016 corsin_a
*/

int		my_strncmp(char	*str1,
			   char	*str2,
			   int	n)
{
  int		cpt;

  cpt = 0;
  while (str1[cpt] && str2[cpt] && str1[cpt] == str2[cpt] && cpt < n)
    ++cpt;
  if (cpt >= n)
    return (1);
  if (str1[cpt] != str2[cpt])
    return (0);
  return (1);
}
