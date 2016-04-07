/*
** cor_header.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Feb 24 11:58:27 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 23:06:19 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"
#include	"parser.h"

static header_t	*cpy_commentary(header_t *header,
				char **comment)
{
  int		cpt;
  int		cpt1;
  int		cpt2;

  cpt = 0;
  cpt2 = 0;
  while (comment[cpt] != NULL)
    {
      cpt1 = 0;
      while (comment[cpt][cpt1] != '\0')
	{
	  header->comment[cpt2] = comment[cpt][cpt1];
	  cpt2++;
	  ++cpt1;
	}
      if (comment[cpt + 1] != NULL)
	header->comment[cpt2] = '\n';
      cpt2++;
      ++cpt;
    }
  cpt = -1;
  while (comment[++cpt])
    free(comment[cpt]);
  free(comment);
  return (header);
}

header_t	*create_cor_header(char *name,
				   char **comment,
				   int prog_size)
{
  header_t	*header;
  int		cpt;

  if ((header = malloc(sizeof(header_t))) == NULL)
  {
    write(2, "Can’t perform malloc\n", 21);
    return (NULL);
  }
  my_bzero(header, sizeof(header_t));
  header->magic = COREWAR_EXEC_MAGIC;
  cpt = 0;
  while (name[cpt] != '\0')
  {
    header->prog_name[cpt] = name[cpt];
    ++cpt;
  }
  header->prog_size = prog_size;
  header = cpy_commentary(header, comment);
  return (header);
}

int		write_cor_header(header_t *header,
				 int fd,
				 char *file_name)
{
  (void)file_name;
  if (IS_LIT_ENDIAN)
    {
      my_reverse_bytes(&header->magic, sizeof(int));
      my_reverse_bytes(&header->prog_size, sizeof(int));
    }
  if (write(fd, header, sizeof(header_t)) == -1)
    return (-1);
  return (0);
}
