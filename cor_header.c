/*
** cor_header.c for  in /home/pillon_m/corewar/CPE_2015_corewar
**
** Made by
** Login   <@epitech.net>
**
** Started on  Tue Feb 23 16:20:01 2016
** Last update Tue Feb 23 19:41:35 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	"asm.h"
#include	"op.h"

static header_t		*cpy_commentary(header_t *header,
					char **comment)
{
  int		cpt;
  int		cpt1;
  int		cpt2;

  cpt = -1;
  cpt1 = -1;
  cpt2 = 0;
  while (comment[++cpt] != NULL)
    {
      while (comment[cpt][++cpt1] != '\0')
	{
	  header->comment[cpt2] = comment[cpt][++cpt1];
	  cpt2++;
	}
      if (comment[cpt + 1] != NULL)
	header->comment[cpt2] = '\n';
      cpt2++;
      cpt1 = 0;
    }
  return (header);
}

static header_t	*init_cor_header()
{
  int		cpt;

  if ((header = malloc(sizeof(t_header))) == NULL)
    {
      write(2, "Can’t perform malloc\n", 21);
      return (NULL);
    }
  header->magic = 0;
  cpt = 0;
  while (cpt < PROG_NAME_LENGTH + 1)
    {
      header->prog_name[cpt] = '\0';
      cpt++;
    }
  header->prog_size = 0;
  cpt = 0;
  while (cpt < COMMENT_LENGTH + 1)
    {
      headr->comment[cpt] = '\0';
      cpt++;
    }
  return (header);
}

header_t	*create_cor_header(char *name,
				   char **comment,
				   int prog_size)
{
  header_t	*header;
  int		cpt;

  if ((header = init_cor_header()) == NULL)
    return (NULL);
  header->magic = COREWAR_EXEC_MAGIC;
  cpt = -1;
  while (name[++cpt] != '\0')
    header->prog_name[cpt] = name[cpt];
  header->prog_size = prog_size;
  header = cpy_comentary(header, comment);
  return (header);
}

int		write_cor_header(header_t *header,
				 int fd,
				 char *file_name)
{
  int		size;

  size = 0;
  while (file_name[size] != '\0')
    size++;
  if (write(fd, header, sizeof(header)) == -1)
    {
      write(2, "File ", 5);
      write(2, file_name, size);
      write(2, "not accessible\n", 15);
      return (ERROR);
    }
  return (0);
}
