/*
** cor_header.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Feb 24 11:58:27 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 20:47:33 2016 
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"

/*
** Copie le tableau de string contenant les commentaires
** dans la section comment du header au format :
** "comment_1\ncomment2\ncomment_3\0"
*/

static header_t	*cpy_commentary(header_t *header,
				char **comment)
{
  int		cpt;
  int		cpt1;
  int		cpt2;

  cpt = -1;
  cpt2 = 0;
  while (comment[++cpt] != NULL)
    {
      cpt1 = -1;
      while (comment[cpt][++cpt1] != '\0')
	{
	  header->comment[cpt2] = comment[cpt][cpt1];
	  cpt2++;
	}
      if (comment[cpt + 1] != NULL)
	header->comment[cpt2] = '\n';
      cpt2++;
    }
  return (header);
}

/*
** Alloue la mémoire pour le header_t
** et met toutes les valeurs à 0
*/

static header_t	*init_cor_header()
{
  int		cpt;
  header_t	*header;

  if ((header = malloc(sizeof(header_t))) == NULL)
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
      header->comment[cpt] = '\0';
      cpt++;
    }
  return (header);
}

/*
** Appelle la fonction init_cor_header() et le remplit
*/

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
  header = cpy_commentary(header, comment);
  return (header);
}

/*
** Ecrit la structure header_t remplie dans le fichier .cor
*/

int		write_cor_header(header_t *header,
				 int fd,
				 char *file_name)
{
  int		size;

  if (IS_LIT_ENDIAN)
    {
      my_reverse_bytes(&header->magic, sizeof(int));
      my_reverse_bytes(&header->prog_size, sizeof(int));
    }
  if (write(fd, header, sizeof(header_t)) == -1)
    {
      size = 0;
      while (file_name[size] != '\0')
	size++;
      write(2, "File ", 5);
      write(2, file_name, size);
      write(2, " not accessible\n", 15);
      return (ERROR);
    }
  return (0);
}
