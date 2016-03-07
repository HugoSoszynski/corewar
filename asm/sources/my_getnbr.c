/*
** my_getnbr.c for minitalk in /home/corsin_a/Travail/PSU/PSU_2015_minitalk/client/src/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Feb  1 14:05:30 2016 corsin_a
** Last update Wed Feb 10 14:16:21 2016 corsin_a
*/

int		my_getnbr(const char *str, int *nb)
{
  int		i;

  *nb = 0;
  (str[0] == '-' || str[0] == '+') ? (i = 1) : (i = 0);
  while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
    {
      *nb = *nb * 10 + (str[i] - '0');
      i++;
    }
  if (str[i] != '\0')
    return (0);
  (str[0] == '-') ? (*nb = -*nb) : (*nb = *nb);
  return (1);
}
