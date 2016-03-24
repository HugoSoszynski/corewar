/*
** stock_code.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
**
** Made by
** Login   <@epitech.net>
**
** Started on  Wed Mar 23 15:55:24 2016
** Last update Thu Mar 24 16:47:33 2016 Grégoire Loens
*/

#include	"parser.h"
#include	"asm.h"

t_cmd		*stock_code(char * line, t_cmd *stock_arg)
{
  char		**code_hexa;
  int		nb_octet;

  stock_arg->line += 6;
  code_hexa = my_str_to_wordtab(line, nb_octet, ' ');
  stock_arg->dot_code_octet = nb_octet;
  return (stock_arg);
}
