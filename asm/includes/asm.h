/*
** asm.h for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Feb 22 19:35:27 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 23:00:23 2016 
*/

#ifndef		ASM_H_
# define	ASM_H_

#include	"op.h"

# define	ERROR				(-1)

# define	OP_LIVE				(1)
# define	OP_LD				(2)
# define	OP_ST				(3)
# define	OP_ADD				(4)
# define	OP_SUB				(5)
# define	OP_AND				(6)
# define	OP_OR				(7)
# define	OP_XOR				(8)
# define	OP_ZJMP				(9)
# define	OP_LDI				(10)
# define	OP_STI				(11)
# define	OP_FORK				(12)
# define	OP_LLD				(13)
# define	OP_LLDI				(14)
# define	OP_LFORK			(15)
# define	OP_AFF				(16)

# define        TYPE_LINE_ERROR			(-1)
# define	TYPE_LINE_EMPTY			(0)
# define	TYPE_LINE_NAME			(1)
# define        TYPE_LINE_COMMENT		(2)
# define	TYPE_LINE_EXTEND		(3)
# define	TYPE_LINE_CODE			(4)
# define        TYPE_LINE_CMD			(5)
# define	TYPE_LINE_LABEL			(6)
# define	TYPE_LINE_LABEL_CMD		(7)

#ifndef		IS_LIT_ENDIAN
# define	IS_LIT_ENDIAN			(check_for_endianess())
#endif		/* !IS_LIT_ENDIAN */

typedef struct	s_cmd
{
  char		opcode;
  char		octet_codage;
  int		arg[3];
  char		type_arg[3];
  char		label[T_LAB];
}		t_cmd;

/*
** cor_header.c
*/

header_t	*create_cor_header(char *name,
				   char **coment,
				   int prog_size);
int		write_cor_header(header_t *header,
				 int fd,
				 char *file_name);
int		check_for_endianess();
void		my_reverse_bytes(void *value,
				unsigned int size);
t_cmd		*create_cmd_struct(char *line);
int		check_cmd_line(char *line);
int		choose_line_type(char *line);

#endif		/* !ASM_H_ */
