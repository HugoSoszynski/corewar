/*
** error.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 13:40:34 2016 Grégoire Loens
** Last update Mon Mar  7 13:41:33 2016 Grégoire Loens
*/

int		error_message(char *message)
{
  write(2, message, my_strlen(message));
  return (-1);
}
