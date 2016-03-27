/*
** init_process.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/initialisation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 12:03:44 2016 corsin_a
** Last update Sun Mar 27 21:31:58 2016 Hugo SOSZYNSKI
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<stddef.h>
#include		<stdlib.h>
#include		"corewar.h"

static unsigned char	*read_exe(int			fd,
				  size_t		prog_size)
{
  unsigned char		*prog;
  char			test[1];

  if ((prog = malloc(prog_size + 1)) == NULL)
    {
      error_message("Can't perform malloc");
      return (NULL);
    }
  prog[prog_size] = '\0';
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

static int		finish_init(t_corewar	*corewar,
				    t_options	*options,
				    int		cpt,
				    int		fd)
{
  if ((corewar->champion[cpt].prog =
       read_exe(fd, corewar->champion[cpt].header.prog_size)) == NULL)
    return (ERROR);
  corewar->champion[cpt].address = options->champion[cpt].ad;
  corewar->champion[cpt].nb_champion = options->champion[cpt].nb;
  return (SUCCESS);
}

static void		opt_endian(t_corewar *corewar)
{
  if (IS_LIT_ENDIAN)
    {
      my_reverse_bytes(&(corewar->champion[cpt].header.magic),
		       sizeof(int));
      my_reverse_bytes(&(corewar->champion[cpt].header.prog_size),
		       sizeof(int));
    }
}

int			init_champ(t_corewar	*corewar,
				   t_options	*options)
{
  int			cpt;
  int			fd;

  cpt = -1;
  while (++cpt < options->nb_champion)
    {
      if ((fd = open(options->champion[cpt].name, O_RDONLY)) == -1)
	return (error_file("File ",
			   options->champion[cpt].name, " is not accessible"));
      if (read(fd, &corewar->champion[cpt].header,
	       sizeof(header_t)) != sizeof(header_t))
	return (error_file("File ",
			   options->champion[cpt].name, " : wrong file size"));
      opt_endian(corewar);
      if (corewar->champion[cpt].header.magic != COREWAR_EXEC_MAGIC)
	return (error_file("", options->champion[cpt].name,
			   " is not a corewar executable"));
      if (finish_init(corewar, options, cpt, fd) == ERROR)
	return (ERROR);
      close(fd);
    }
  corewar->nb_champions = options->nb_champion;
  return (SUCCESS);
}
