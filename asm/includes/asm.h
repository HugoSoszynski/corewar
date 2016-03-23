/*
** asm.h for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Feb 22 19:35:27 2016 Hugo SOSZYNSKI
** Last update Wed Mar 23 17:42:33 2016 
*/

#ifndef		ASM_H_
# define	ASM_H_

#include	"op.h"

# define	ERROR			(-1)

# ifndef	OP_LIVE
#  define	OP_LIVE			(0)
# endif		/* !OP_LIVE */

# ifndef	OP_LD
#  define	OP_LD			(2)
# endif		/* !OP_LD */

# ifndef	OP_ST
#  define	OP_ST			(4)
# endif		/* !OP_ST */

# ifndef	OP_ADD
#  define	OP_ADD			(6)
# endif		/* !OP_ADD */

# ifndef	OP_SUB
#  define	OP_SUB			(8)
# endif		/* !OP_SUB */

# ifndef	OP_AND
#  define	OP_AND			(10)
# endif		/* !OP_AND */

# ifndef	OP_OR
#  define	OP_OR			(12)
# endif		/* !OP_OR */

# ifndef	OP_XOR
#  define	OP_XOR			(14)
# endif		/* !OP_XOR */

# ifndef	OP_ZJMP
#  define	OP_ZJMP			(16)
# endif		/* !OP_ZJMP */

# ifndef	OP_LDI
#  define	OP_LDI			(18)
# endif		/* !OP_LDI */

# ifndef	OP_STI
#  define	OP_STI			(20)
# endif		/* !OP_STI */

# ifndef	OP_FORK
#  define	OP_FORK			(22)
# endif		/* !OP_FORK */

# ifndef	OP_LLD
#  define	OP_LLD			(24)
# endif		/* !OP_LLD */

# ifndef	OP_LLDI
#  define	OP_LLDI			(26)
# endif		/* !OP_LLDI */

# ifndef	OP_LFORK
#  define	OP_LFORK		(28)
# endif		/* !OP_LFORK */

# ifndef	OP_AFF
#  define	OP_AFF			(30)
# endif		/* !OP_AFF */

# ifndef	TYPE_LINE_ERROR
#  define       TYPE_LINE_ERROR		(-1)
# endif		/* TYPE_LINE_ERROR */

# ifndef	TYPE_LINE_EMPTY
# define	TYPE_LINE_EMPTY		(0)
# endif		/* TYPE_LINE_EMPTY */

# ifndef	TYPE_LINE_NAME
# define	TYPE_LINE_NAME		(1)
# endif		/* TYPE_LINE_NAME */

# ifndef	TYPE_LINE_COMMENT
# define        TYPE_LINE_COMMENT	(2)
# endif		/* TYPE_LINE_COMMENT */

# ifndef	TYPE_LINE_EXTEND
# define	TYPE_LINE_EXTEND	(3)
# endif		/* TYPE_LINE_EXTEND */

# ifndef	TYPE_LINE_CODE
# define	TYPE_LINE_CODE		(4)
# endif		/* TYPE_LINE_CODE*/

# ifndef	TYPE_LINE_CMD
# define        TYPE_LINE_CMD		(5)
# endif		/* TYPE_LINE_CMD */

# ifndef	TYPE_LINE_LABEL
# define	TYPE_LINE_LABEL		(6)
# endif		/* TYPE_LINE_LABEL */

# ifndef	TYPE_LINE_LABEL_CMD
# define	TYPE_LINE_LABEL_CMD	(7)
# endif		/* TYPE_LINE_LABEL_CMD */


#ifndef		IS_LIT_ENDIAN
# define	IS_LIT_ENDIAN		(check_for_endianess())
#endif		/* !IS_LIT_ENDIAN */

typedef struct s_list
{
  struct s_cmd	*head;
}		t_list;

typedef struct	s_cmd
{
  char		type;
  char		*line;
  int		nbr_line;
  char		opcode;
  char		octet_codage;
  int		arg[3];
  char		type_arg[3];
  char		label[3][T_LAB];
  t_list	*head;
  struct s_cmd	*next;
  t_pile	*def;
  t_pile	*call;
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
