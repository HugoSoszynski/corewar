/*
** stockage.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar  8 14:42:29 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 10:20:08 2016 
*/

#include	<stddef.h>
#include	"parser.h"
#include	"asm.h"

int		stockage(t_cmd *cmd_tab, char *line, int line_type)
{
  if (cmd_tab == NULL || line == NULL || line_type <= 0 || line_type > 7)
    return (error_message("Stockage argument error\n"));
  return (0);
}
