/*
** op_list.h for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:51:58 2016 corsin_a
** Last update Wed Mar 23 11:41:18 2016 Hugo SOSZYNSKI
*/

#ifndef		OP_LIST_H_
# define	OP_LIST_H_

# include	"corewar.h"

# ifndef	OP_LIVE
#  define	OP_LIVE		(1)
# endif		/* !OP_LIVE */

# ifndef	OP_LD
#  define	OP_LD		(2)
# endif		/* !OP_LD */

# ifndef	OP_ST
#  define	OP_ST		(3)
# endif		/* !OP_ST */

# ifndef	OP_ADD
#  define	OP_ADD		(4)
# endif		/* !OP_ADD */

# ifndef	OP_SUB
#  define	OP_SUB		(5)
# endif		/* !OP_SUB */

# ifndef	OP_AND
#  define	OP_AND		(6)
# endif		/* !OP_AND */

# ifndef	OP_OR
#  define	OP_OR		(7)
# endif		/* !OP_OR */

# ifndef	OP_XOR
#  define	OP_XOR		(8)
# endif		/* !OP_XOR */

# ifndef	OP_ZJMP
#  define	OP_ZJMP		(9)
# endif		/* !OP_ZJMP */

# ifndef	OP_LDI
#  define	OP_LDI		(10)
# endif		/* !OP_LDI */

# ifndef	OP_STI
#  define	OP_STI		(11)
# endif		/* !OP_STI */

# ifndef	OP_FORK
#  define	OP_FORK		(12)
# endif		/* !OP_FORK */

# ifndef	OP_LLD
#  define	OP_LLD		(13)
# endif		/* !OP_LLD */

# ifndef	OP_LLDI
#  define	OP_LLDI		(14)
# endif		/* !OP_LLDI */

# ifndef	OP_LFORK
#  define	OP_LFORK	(15)
# endif		/* !OP_LFORK */

# ifndef	OP_AFF
#  define	OP_AFF		(16)
# endif		/* !OP_AFF */

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
