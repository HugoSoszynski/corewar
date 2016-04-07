/*
** my_bzero.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Feb 24 11:58:27 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 23:06:19 2016 Hugo SOSZYNSKI
*/

void		my_bzero(void *_ptr, int size)
{
  char		*ptr;
  int		cpt;

  ptr = _ptr;
  cpt = 0;
  while (cpt < size)
  {
    ptr[cpt] = 0;
    ++cpt;
  }
}
