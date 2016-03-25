/*
** my_getnbr_base.c for yolo in /tmp
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu Mar 24 18:58:34 2016 Hugo SOSZYNSKI
** Last update Fri Mar 25 01:36:10 2016 
*/

unsigned char		my_getnbr_base(char *str, const char *base)
{
  unsigned char		nb;
  int			cpt;
  int			idx;
  int			base_len;

  base_len = -1;
  while (base[++base_len] != '\0');
  nb = 0;
  cpt = -1;
  while (str[++cpt] != '\0')
    {
      idx = -1;
      while (base[++idx] != str[cpt]);
      nb *= base_len;
      nb += idx;
    }
  return (nb);
}
