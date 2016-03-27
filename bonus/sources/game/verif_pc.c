/*
** verig_pc.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 15:37:53 2016 corsin_a
** Last update Sun Mar 27 22:16:23 2016 corsin_a
*/

#include	"corewar.h"

int		verif_pc(int		pc)
{
  if (pc < 0)
    pc = MEM_SIZE + pc % MEM_SIZE;
  pc %= MEM_SIZE;
  return (pc);
}
