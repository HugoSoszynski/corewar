/*
** main.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:12:25 2016 Hugo SOSZYNSKI
** Last update Thu Apr  7 12:14:15 2016 gregoire loens
*/

#include	<sys/stat.h>
#include	<stddef.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	"parser.h"
#include	"asm.h"

int		main(int ac, char **av, char **envp)
{
  int		fd;

  if (envp == NULL)
    return (-1);
  if (envp[0] == NULL)
    return (-1);
  if (ac != 2)
    return (-1);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (error_message_nonb("cant open file"));
  if ((verif_cmd_line(fd, av[1])) == -1)
    return (-1);
  return (0);
}
