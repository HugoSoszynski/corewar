/*
** main.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar 22 18:16:49 2016 
** Last update Tue Mar 22 18:25:13 2016 
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
    return (-1);
  if ((verif_cmd_line(fd)) == -1)
    return (-1);
}
