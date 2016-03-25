/*
** define_op_cycles.h for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Mar 23 00:32:23 2016 Hugo SOSZYNSKI
** Last update Wed Mar 23 00:54:27 2016 Hugo SOSZYNSKI
*/

#ifndef		DEFINE_OP_CYCLES_H_
# define	DEFINE_OP_CYCLES_H_

# ifndef	CYCLE_LIVE
#  define	CYCLE_LIVE		(10)
# endif		/* !CYCLE_LIVE */

# ifndef	CYCLE_LD
#  define	CYCLE_LD		(5)
# endif		/* !CYCLE_LD */

# ifndef	CYCLE_ST
#  define	CYCLE_ST		(5)
# endif		/* !CYCLE_ST */

# ifndef	CYCLE_ADD
#  define	CYCLE_ADD		(10)
# endif		/* !CYCLE_ADD */

# ifndef	CYCLE_SUB
#  define	CYCLE_SUB		(10)
# endif		/* !CYCLE_SUB */

# ifndef	CYCLE_AND
#  define	CYCLE_AND		(6)
# endif		/* !CYCLE_AND */

# ifndef	CYCLE_OR
#  define	CYCLE_OR		(6)
# endif		/* !CYCLE_OR */

# ifndef	CYCLE_XOR
#  define	CYCLE_XOR		(6)
# endif		/* !CYCLE_XOR */

# ifndef	CYCLE_ZJMP
#  define	CYCLE_ZJMP		(20)
# endif		/* !CYCLE_ZJMP */

# ifndef	CYCLE_LDI
#  define	CYCLE_LDI		(25)
# endif		/* !CYCLE_LDI */

# ifndef	CYCLE_STI
#  define	CYCLE_STI		(25)
# endif		/* !CYCLE_STI */

# ifndef	CYCLE_FORK
#  define	CYCLE_FORK		(800)
# endif		/* !CYCLE_FORK */

# ifndef	CYCLE_LLD
#  define	CYCLE_LLD		(10)
# endif		/* !CYCLE_LLD */

# ifndef	CYCLE_LLDI
#  define	CYCLE_LLDI		(50)
# endif		/* !CYCLE_LLDI */

# ifndef	CYCLE_LFORK
#  define	CYCLE_LFORK		(1000)
# endif		/* !CYCLE_LFORK */

# ifndef	CYCLE_AFF
#  define	CYCLE_AFF		(2)
# endif		/* !CYCLE_AFF */

#endif		/* !DEFINE_OP_CYCLES_H_ */
