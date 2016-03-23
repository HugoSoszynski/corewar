/*
** op_list.h for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:51:58 2016 corsin_a
** Last update Wed Mar 23 04:06:00 2016 corsin_a
*/

#ifndef		OP_LIST_H_
# define	OP_LIST_H_

#include	"corewar.h"

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

int		check_op_live(char);
void		op_live(t_corewar *, t_process_list *);
int		check_op_ld(char);
void		op_ld(t_corewar *, t_process_list *);
int		check_op_st(char);
void		op_st(t_corewar *, t_process_list *);
int		check_op_add(char);
void		op_add(t_corewar *, t_process_list *);
int		check_op_sub(char);
void		op_sub(t_corewar *, t_process_list *);
int		check_op_and(char);
void		op_and(t_corewar *, t_process_list *);
int		check_op_or(char);
void		op_or(t_corewar *, t_process_list *);
int		check_op_xor(char);
void		op_xor(t_corewar *, t_process_list *);
int		check_op_zjmp(char);
void		op_zjmp(t_corewar *, t_process_list *);
int		check_op_ldi(char);
void		op_ldi(t_corewar *, t_process_list *);
int		check_op_sti(char);
void		op_sti(t_corewar *, t_process_list *);
int		check_op_fork(char);
void		op_fork(t_corewar *, t_process_list *);
int		check_op_lld(char);
void		op_lld(t_corewar *, t_process_list *);
int		check_op_lldi(char);
void		op_lldi(t_corewar *, t_process_list *);
int		check_op_lfork(char);
void		op_lfork(t_corewar *, t_process_list *);
int		check_op_aff(char);
void		op_aff(t_corewar *, t_process_list *);

#endif		/* !OP_LIST_H_ */
