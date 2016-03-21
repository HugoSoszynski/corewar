/*
** init_stockage_functions.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar  8 16:06:35 2016 Hugo SOSZYNSKI
** Last update Tue Mar  8 16:43:45 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>

int		init_stock_func(void *tab)
{
  if (tab == NULL)
    return (ERROR);
  tab[TYPE_LINE_NAME] = my_stock_name;
  tab[TYPE_LINE_COMMENT] = my_stock_comment;
  tab[TYPE_LINE_EXTEND] = NULL;
  tab[TYPE_LINE_CODE] = my_stock_code;
  tab[TYPE_LINE_CMD] = my_stock_cmd;
  tab[TYPE_LINE_LABEL] = my_stock_label;
  tab[TYPE_LINE_LABEL_CMD] = my_stock_cmd_and_label;
  return (0);
}
