/*
** stock_code.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed Mar 23 15:55:24 2016 
** Last update Wed Mar 23 16:11:48 2016 
*/

#include		"parser.h"
#include		"asm.h"

t_cmd			*stock_code(char * line, t_cmd *stock_arg)
{
  stock_arg->line += 6;
  return (stock_arg);
}
