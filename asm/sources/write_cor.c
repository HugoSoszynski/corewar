/*
** write_cor.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 14:40:35 2016 
** Last update Thu Mar 24 19:33:42 2016 
*/

#include	<unistd.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"

char		*to_dot_cor(char *filename)
{
  int		cpt;
  char		*output;
  
  if ((output = malloc(sizeof(char) my_strlen(filename) + 2)) == NULL)
    return (NULL);
  cpt = -1;
  while (filename[++cpt] != '.' && filename[cpt] != '\0')
    output[cpt] = filename[cpt];
  output[cpt] = '.';
  output[cpt + 1] = 'c';
  output[cpt + 2] = 'o';
  output[cpt + 3] = 'r';
  return (output);
}

int		write_cor(t_cmd *cmd, char *filename)
{
  int		fd;
  char		*name;
  char		**comment;
  int		prog_size;
  header_t	*header;

  if (label_and_prog_size(cmd, &prog_size) == -1)
    return (-1);
  if ((filename = to_dot_cor(filename)) == NULL)
    return (-1);
  if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC |
		 O_APPEND, S_IWUSR | S_IWGRP | S_IROTH)) == -1)
    return (-1);
  if ((name = check_one_name(cmd)) == NULL)
    return (-1);
  if ((comment = where_comment(cmd)) == NULL)
    return (-1);
  if ((header = create_cor_header(name, comment, prog_size)) == NULL)
    return (-1);
  if ((write_cor_header(header, fd, filename)) == ERROR)
    return (1);
  if ((write_file(fd, cmd)) == -1)
    return(-1);
}
