/*
** stock_code.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
**
** Made by
** Login   <@epitech.net>
**
** Started on  Wed Mar 23 15:55:24 2016
** Last update Fri Mar 25 01:55:57 2016 
*/

#include	"parser.h"
#include	"asm.h"
#include	"pile_label.h"

t_cmd		*stock_code(char *line, t_cmd *stock_arg)
{
  char		**code_hexa;
  int		nb_octet;

  stock_arg->line += 6;
  code_hexa = my_str_to_wordtab(line, &nb_octet, ' ');
  stock_arg->dot_code_octet = nb_octet;
  return (stock_arg);
}
