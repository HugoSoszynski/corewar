/*
** my_getnbr_base.c for yolo in /tmp
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu Mar 24 18:58:34 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 15:31:45 2016 
*/

static int		check_in_base(char car, const char *base)
{
  int			cpt;

  cpt = -1;
  while (base[++cpt] != '\0')
    if (car == base[cpt])
      return (0);
  return (1);
}

int		my_getnbr_base(char *str, const char *base)
{
  int	       		nb;
  int			sign;
  int			cpt;
  int			idx;
  int			base_len;

  base_len = -1;
  sign = 0;
  if (str[0] == '-')
    {
      sign = 1;
      str++;
    }
  while (base[++base_len] != '\0');
  nb = 0;
  cpt = -1;
  while (str[++cpt] != '\0' && check_in_base(str[cpt], base) == 0)
    {
      idx = -1;
      while (base[++idx] != str[cpt]);
      nb *= base_len;
      nb += idx;
    }
  if (sign == 1)
    nb *= -1;
  return (nb);
}
