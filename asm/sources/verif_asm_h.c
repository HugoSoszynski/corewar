/*
** verif_asm_h.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Sun Mar 27 16:24:28 2016 Grégoire Loens
** Last update Sun Mar 27 16:45:07 2016 Grégoire Loens
*/

#include	"asm.h"

int		verif_asm_h()
{
  if ((ERROR != -1) || (OP_LIVE != 0) || (OP_LD != 2) || (OP_ST != 4)
      || (OP_ADD != 6))
    return (-1);
  else if ((OP_SUB != 8) || (OP_AND != 10) || (OP_OR != 12) || (OP_XOR != 14))
    return (-1);
  else if ((OP_ZJMP != 16) || (OP_LDI != 18) || (OP_STI != 20)
	  || (OP_FORK != 22))
    return (-1);
  else if ((OP_LLD != 24) || (OP_LLDI != 26) || (OP_LFORK != 28)
	   || (OP_AFF != 30))
    return (-1);
  else if ((TYPE_LINE_ERROR != -1) || (TYPE_LINE_EMPTY != 0)
	   || (TYPE_LINE_NAME) != 1))
    return (-1);
  else if ((TYPE_LINE_COMMENT != 2) || (TYPE_LINE_EXTEND != 3))
    return (-1);
  else if ((TYPE_LINE_CODE != 4) || (TYPE_LINE_CMD != 5))
    return (-1);
  else if ((TYPE_LINE_LABEL != 6) || (TYPE_LINE_LABEL_CMD != 7))
    return (-1)
  else
    return (0);
}
