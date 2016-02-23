/*
** asm.h for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Feb 22 19:35:27 2016 Hugo SOSZYNSKI
** Last update Tue Feb 23 15:20:08 2016 Hugo SOSZYNSKI
*/

#ifndef		ASM_H_
# define	ASM_H_

# define	OP_LIVE		(1)
# define	OP_LD		(2)
# define	OP_ST		(3)
# define	OP_ADD		(4)
# define	OP_SUB		(5)
# define	OP_AND		(6)
# define	OP_OR		(7)
# define	OP_XOR		(8)
# define	OP_ZJMP		(9)
# define	OP_LDI		(10)
# define	OP_STI		(11)
# define	OP_FORK		(12)
# define	OP_LLD		(13)
# define	OP_LLDI		(14)
# define	OP_LFORK	(15)
# define	OP_AFF		(16)

typedef struct	s_op
{
  char		opcode;
  char		octet_codage;
  int		arg1;
  int		arg2;
  int		arg3;
  char		type_arg1;
  char		type_arg2;
  char		type_arg3;
}		t_op;

typedef struct	s_op_tab
{
  char		type;
  char		label[T_LAB];
  void		*op;
}		t_op_tab;

#endif		/* !ASM_H_ */
