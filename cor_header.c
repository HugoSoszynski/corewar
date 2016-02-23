/*
** cor_header.c for  in /home/pillon_m/corewar/CPE_2015_corewar
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Feb 23 16:20:01 2016 
** Last update Tue Feb 23 17:33:50 2016 
*/

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

header_t	*create_cor_header(char *name,
				   char **comment,
				   int prog_size)
{
  header_t	*header;
  int		cpt;
  
  cpt = -1;
  if ((header = malloc(sizeof(t_header))) == NULL)
    return (NULL);
  if ((header = my_bzero(header)) == NULL)
    return (NULL);
  while (name[++cpt] != '\0')
    header->prog_name[cpt] = name[cpt];
  header = cpy_comentary(header, comment);
  header->prog_size = prog_size;
  return (header);
}

int		write_cor_header(header_t *header,
				 int fd)
{
  if (write(fd, header, sizeof(header)) == -1)
    {
      write(2, "Error: writing the header\n", 26);
      return (ERROR);
    }
  return (0);
}
