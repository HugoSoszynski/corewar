/*
** write_cor.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:25:06 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 23:42:51 2016 Sylvain Corsini
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<stddef.h>
#include	"pile_label.h"
#include	"asm.h"
#include	"parser.h"
#include	"op.h"

char		*to_dot_cor(char *filename)
{
  int		cpt;
  char		*output;

  if ((output = malloc(sizeof(char) * my_strlen(filename) + 3)) == NULL)
    return (NULL);
  cpt = -1;
  while ((filename[++cpt] != '\0'))
    output[cpt] = filename[cpt];
  while (cpt != 0 && output[cpt] != '.')
    cpt--;
  if (cpt == 0)
    {
      write (2, "name file incorrect", 19);
      return (NULL);
    }
  output[cpt + 1] = 'c';
  output[cpt + 2] = 'o';
  output[cpt + 3] = 'r';
  output[cpt + 4] = '\0';
  return (output);
}

int		write_cor_extend(t_cmd *cmd, char *filename, int *fd, int *prog_size)
{
  *prog_size = 0;
  cmd = cmd->head;
  if (label_and_prog_size(cmd, prog_size) == -1)
    return (-1);
  cmd = cmd->head;
  if ((cmd = set_octet_label(cmd)) == NULL)
    return (-1);
  if ((filename = to_dot_cor(filename)) == NULL)
    return (-1);
  if ((*fd = open(filename, O_CREAT | O_RDONLY | O_WRONLY |
		 O_TRUNC | O_APPEND, S_IWUSR | S_IRUSR | S_IRGRP |
		 S_IWGRP | S_IROTH)) == -1)
    return (-1);
  return (0);
}

int		write_cor(t_cmd *cmd, char *filename)
{
  int		fd;
  char		*name;
  int		cpt;
  char		**comment;
  int		prog_size;
  header_t	*header;

  cpt = 0;
  if ((write_cor_extend(cmd, filename, &fd, &prog_size)) == -1)
    return (-1);
  if ((name = check_one_name(cmd)) == NULL)
    return (-1);
  if ((comment = where_comment(cmd, 0)) == NULL)
    return (-1);
  while (comment[cpt] != NULL)
    cpt++;
  if ((header = create_cor_header(name, comment, prog_size)) == NULL)
    return (-1);
  if ((write_cor_header(header, fd, filename)) == ERROR)
    return (1);
  free(header);
  if ((write_file(fd, cmd)) == -1)
    return(-1);
  return (0);
}
