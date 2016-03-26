/*
** write_cor.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 14:40:35 2016 
** Last update Fri Mar 25 19:29:33 2016 
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



#include	<stdio.h>




char		*to_dot_cor(char *filename)
{
  int		cpt;
  char		*output;
  
  if ((output = malloc(sizeof(char) * my_strlen(filename) + 3)) == NULL)
    return (NULL);
  cpt = -1;
  while (filename[++cpt] != '.' && filename[cpt] != '\0')
    output[cpt] = filename[cpt];
  output[cpt] = '.';
  output[cpt + 1] = 'c';
  output[cpt + 2] = 'o';
  output[cpt + 3] = 'r';
  output[cpt + 4] = '\0';
  return (output);
}

int		write_cor(t_cmd *cmd, char *filename)
{
  int		fd;
  char		*name;
  int		cpt;
  char		**comment;
  int		prog_size;
  header_t	*header;
  
  prog_size = 0;
  cpt = 0;
  if (label_and_prog_size(cmd, &prog_size) == -1)
    return (-1);
  if ((cmd = set_octet_label(cmd)) == NULL)
    return (-1);
  if ((filename = to_dot_cor(filename)) == NULL)
    return (-1);
  if ((fd = open(filename, O_CREAT | O_RDONLY | O_WRONLY |
		 O_TRUNC | O_APPEND, S_IWUSR | S_IRUSR | S_IRGRP |
		 S_IWGRP | S_IROTH)) == -1)
    return (-1);
  if ((name = check_one_name(cmd)) == NULL)
    return (-1);
  if ((comment = where_comment(cmd)) == NULL)
    return (-1);
  printf("%s \n", name);
  while (comment[cpt] != NULL)
    {
      printf("%s \n", comment[cpt]);
      cpt++;
    }
  printf("%s \n", comment[cpt]);
  if ((header = create_cor_header(name, comment, prog_size)) == NULL)
    return (-1);
  if ((write_cor_header(header, fd, filename)) == ERROR)
    return (1);
  if ((write_file(fd, cmd)) == -1)
    return(-1);
  return (0);
}
