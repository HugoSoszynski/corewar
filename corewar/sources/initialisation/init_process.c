/*
** init_process.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 12:03:44 2016 corsin_a
** Last update Mon Mar 21 13:00:37 2016 corsin_a
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"corewar.h"

#include		<stdio.h>

static int		read_process(int		fd)
{
  int			nb;
  int			ret;
  int			cpt;

  nb = 0;
  cpt = 1;
  while ((ret = read(fd, &nb, 1)) != 0)
    {
      if (ret == -1) return (-1);
      printf("0x%.2x  ", nb);
      if (cpt == 10)
	{
	  cpt = 0;
	  printf("\n");
	}
      ++cpt;
    }
  printf("\n");
  return (0);
}

int			init_process(t_process_list	*process_list,
				     int		nb_file,
				     char		*file[])
{
  int			cpt;
  int			fd;
  header_t		header;
  int			ret;

  (void)process_list;
  cpt = -1;
  while (++cpt < nb_file)
    {
      /*if ((process_list = malloc(sizeof(t_process_list))) == NULL)
	return (-1);*/
      printf("file name\t:\t%s\n\n", file[cpt]);
      if ((fd = open(file[cpt], O_RDONLY)) == -1) continue ;
      if ((ret = read(fd, &header, sizeof(header_t))) != sizeof(header_t))
	continue ;
      printf("magic number\t:\t%d\nprocess name\t:\t%s\nprocess size\t:\t%d\ncomment\t\t:\t%s\n",
	     header.magic, header.prog_name, header.prog_size, header.comment);
      if (read_process(fd) == -1) continue ;
      close(fd);
      printf("\n-----------------------------------\n");
    }
  return (0);
}
