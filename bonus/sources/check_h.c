/*
** check_h.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sat Mar 26 16:42:59 2016 corsin_a
** Last update Sat Mar 26 17:30:35 2016 corsin_a
*/

#include	"corewar.h"
#include	"op.h"
#include	"op_list.h"
#include	"define_op_cycles.h"

int		check_h(void)
{
  if (REG_NUMBER < 1 || REG_SIZE != 4 || CYCLE_TO_DIE < 1
      || CYCLE_DELTA < 0 || NBR_LIVE < 1 || PROG_NAME_LENGTH < 1
      || COMMENT_LENGTH < 1 || IND_SIZE < 1 || DIR_SIZE < 1
      || T_REG < 1 || T_DIR < 1 || T_IND < 1)
    return (error_message("Error op.h"));
  if (SUCCESS != 0 || ERROR != 1 || CONTINUE != 2 ||
      IS_DEAD != 0 || IS_RUN != 1 || IS_ALIVE != 2)
    return (error_message("Error corewar.h"));
  if (CYCLE_LIVE < 1 || CYCLE_LD < 1 || CYCLE_ST < 1 || CYCLE_ADD < 1 ||
      CYCLE_SUB < 1 || CYCLE_AND < 1 || CYCLE_OR < 1 || CYCLE_XOR < 1 ||
      CYCLE_ZJMP < 1 || CYCLE_LDI < 1 || CYCLE_STI < 1 || CYCLE_FORK < 1 ||
      CYCLE_LLD < 1 || CYCLE_LLDI < 1 || CYCLE_LFORK < 1 || CYCLE_AFF < 1)
    return (error_message("Error define_op_cycles.h"));
  if (OP_LIVE != 1 || OP_LD != 2 || OP_ST != 3 || OP_ADD != 4 ||
      OP_SUB != 5 || OP_AND != 6 || OP_OR != 7 || OP_XOR != 8 ||
      OP_ZJMP != 9 || OP_LDI != 10 || OP_STI != 11 || OP_FORK != 12 ||
      OP_LLD != 13 || OP_LLDI != 14 || OP_LFORK != 15 || OP_AFF != 16)
    return (error_message("Error define_op_cycles.h"));
  return (SUCCESS);
}
