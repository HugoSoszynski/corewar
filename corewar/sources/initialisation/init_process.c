/*
** init_process.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 12:03:44 2016 corsin_a
** Last update Mon Mar 21 17:33:22 2016 Hugo SOSZYNSKI
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<stddef.h>
#include		<stdlib.h>
#include		"corewar.h"

unsigned char		*read_exe(int			fd,
				  size_t		prog_size)
{
  unsigned char		*prog;
  char			test[1];

  if ((prog = malloc(prog_size + 1)) == NULL)
    {
      error_message("Can't perform malloc");
      return (NULL);
    }
  prog[prog_size]
  if (read(fd, prog, prog_size) < (int)(prog_size))
    {
      free(prog);
      error_message("Wrong champion size");
      return (NULL);
    }
  if (read(fd, test, 1) > 0)
    {
      free(prog);
      error_message("Wrong champion size");
      return (NULL);
    }
  return (prog);
}

int			init_champ(t_corewar	*corewar,
				   int		nb_file,
				   char		*file[])
{
  int			cpt;
  int			fd;

  cpt = -1;
  while (++cpt < nb_file)
    {
      if ((fd = open(file[cpt], O_RDONLY)) == -1)
	return (error_file("File ", file[cpt], " is not accessible"));
      if (read(fd, &corewar->champion[cpt].header,
	       sizeof(header_t)) != sizeof(header_t))
	return (error_file("File ", file[cpt], " : wrong file size"));
      if (IS_LIT_ENDIAN)
	{
	  my_reverse_bytes(&(corewar->champion[cpt].header.magic),
			   sizeof(int));
          my_reverse_bytes(&(corewar->champion[cpt].header.prog_size),
			   sizeof(int));
	}
      if ((corewar->champion[cpt].prog =
	   read_exe(fd, corewar->champion[cpt].header.prog_size)) == NULL)
	return (ERROR);
      close(fd);
    }
  return (SUCCESS);
}
