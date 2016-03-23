/*
** corewar.h for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 17:44:36 2016 Hugo SOSZYNSKI
** Last update Wed Mar 23 11:44:43 2016 Hugo SOSZYNSKI
*/

#ifndef			COREWAR_H_
# define		COREWAR_H_

# include		<stdbool.h>
# include		<stddef.h>
# include		"op.h"

# ifndef		SUCCESS
#  define		SUCCESS		(0)
# endif			/* !SUCCESS */

# ifndef		ERROR
#  define		ERROR		(1)
# endif			/* !ERROR */

# ifndef		CONTINUE
#  define		CONTINUE	(2)
# endif			/* !CONTINUE */

# ifndef		IS_LIT_ENDIAN
#  define		IS_LIT_ENDIAN	(check_for_endianess())
# endif			/* !IS_LIT_ENDIAN */

# ifndef		IS_DEAD
#  define		IS_DEAD		(0)
# endif			/* !IS_DEAD */

# ifndef		IS_RUN
#  define		IS_RUN		(1)
# endif			/* !IS_RUN */

# ifndef		IS_ALIVE
#  define		IS_ALIVE	(2)
# endif			/* !IS_ALIVE */

typedef struct		s_instruction
{
  char			op;
  char			opcode;
  int			arg[3];
  char			type_arg[3];
  bool			correct;
}			t_instruction;

typedef struct		s_process
{
  char			reg[REG_NUMBER][REG_SIZE];
  char			carry;
  unsigned int		pc;
  unsigned int		nb_champion;
}			t_process;

typedef struct		s_process_list
{
  t_process		process;
  t_instruction		instruction;
  int			cycle;
  struct s_process_list	*next;
}			t_process_list;

typedef struct		s_champion
{
  header_t		header;
  unsigned char		*prog;
  int			address;
  int			nb_champion;
}			t_champion;

typedef struct		s_corewar
{
  t_process_list	*process_list;
  unsigned int		cycle_to_die;
  unsigned int		cycle_passed;
  unsigned long int	actual_cycle;
  char			champions_alive[4];
  unsigned char		nb_champions;
  t_champion		champion[4];
  unsigned char		mem[MEM_SIZE];
  unsigned int		live_nb;
  void			*op_tab;
}			t_corewar;

typedef struct		s_options_champion
{
  char			*name;
  int			nb;
  int			ad;
}			t_options_champion;

typedef struct		s_options
{
  int			dump;
  int			nb_champion;
  t_options_champion	champion[4];
}			t_options;

# ifndef		OP_LIVE
#  define		OP_LIVE		(1)
# endif			/* !OP_LIVE */

# ifndef		OP_LD
#  define		OP_LD		(2)
# endif			/* !OP_LD */

# ifndef		OP_ST
#  define		OP_ST		(3)
# endif			/* !OP_ST */

# ifndef		OP_ADD
#  define		OP_ADD		(4)
# endif			/* !OP_ADD */

# ifndef		OP_SUB
#  define		OP_SUB		(5)
# endif			/* !OP_SUB */

# ifndef		OP_AND
#  define		OP_AND		(6)
# endif			/* !OP_AND */

# ifndef		OP_OR
#  define		OP_OR		(7)
# endif			/* !OP_OR */

# ifndef		OP_XOR
#  define		OP_XOR		(8)
# endif			/* !OP_XOR */

# ifndef		OP_ZJMP
#  define		OP_ZJMP		(9)
# endif			/* !OP_ZJMP */

# ifndef		OP_LDI
#  define		OP_LDI		(10)
# endif			/* !OP_LDI */

# ifndef		OP_STI
#  define		OP_STI		(11)
# endif			/* !OP_STI */

# ifndef		OP_FORK
#  define		OP_FORK		(12)
# endif			/* !OP_FORK */

# ifndef		OP_LLD
#  define		OP_LLD		(13)
# endif			/* !OP_LLD */

# ifndef		OP_LLDI
#  define		OP_LLDI		(14)
# endif			/* !OP_LLDI */

# ifndef		OP_LFORK
#  define		OP_LFORK	(15)
# endif			/* !OP_LFORK */

# ifndef		OP_AFF
#  define		OP_AFF		(16)
# endif			/* !OP_AFF */

int			check_op_live(char);
void			op_live(t_corewar *, t_process_list *);
int			check_op_ld(char);
void			op_ld(t_corewar *, t_process_list *);
int			check_op_st(char);
void			op_st(t_corewar *, t_process_list *);
int			check_op_add(char);
void			op_add(t_corewar *, t_process_list *);
int			check_op_sub(char);
void			op_sub(t_corewar *, t_process_list *);
int			check_op_and(char);
void			op_and(t_corewar *, t_process_list *);
int			check_op_or(char);
void			op_or(t_corewar *, t_process_list *);
int			check_op_xor(char);
void			op_xor(t_corewar *, t_process_list *);
int			check_op_zjmp(char);
void			op_zjmp(t_corewar *, t_process_list *);
int			check_op_ldi(char);
void			op_ldi(t_corewar *, t_process_list *);
int			check_op_sti(char);
void			op_sti(t_corewar *, t_process_list *);
int			check_op_fork(char);
void			op_fork(t_corewar *, t_process_list *);
int			check_op_lld(char);
void			op_lld(t_corewar *, t_process_list *);
int			check_op_lldi(char);
void			op_lldi(t_corewar *, t_process_list *);
int			check_op_lfork(char);
void			op_lfork(t_corewar *, t_process_list *);
int			check_op_aff(char);
void			op_aff(t_corewar *, t_process_list *);

typedef struct		s_op_tab
{
  int			(*check)(char			opcode);
  void			(*exec)(t_corewar 		*corewar,
			        t_process_list		*process_list);
  int			cycle_to_die;
}			t_op_tab;

int			init_corewar(t_corewar		*corewar,
				     int		ac,
				     char		**av);
int			init_champ(t_corewar		*corewar,
				   t_options		*options);
int			init_options(int		argc,
				     char		*argv[],
				     t_options		*options);
int			check_for_endianess(void);
void			my_reverse_bytes(void		*_value,
					 unsigned int 	size);
int			my_getnbr(const char 		*str,
				  int 			*nb);
void			my_putnbr(int			nb);
int			my_strcmp(char			*str1,
				  char			*str2);
int			error_message(char		*msg);
int			error_file(char			*start,
				   char			*name,
				   char			*end);
int			error_nbr(char			*start,
				  int			nb,
				  char			*end);
int			champ_imcomp(t_corewar		*corewar);
int			fill_champions(t_corewar	*corewar);
int			aff_help(int			a);
int			there_is_help(int		argc,
				      char		*argv[]);
void			my_init_tab(void		*_tab,
				    size_t		size);
int			prepare_corewar(t_corewar	*corewar);
int			launch_corewar(t_corewar	*corewar);
void			free_processlist(t_process_list	*list);
int			clone_process(t_process_list	*src,
				      int		add_to_pc);
void			execute_process(t_corewar	*corewar);
void			prepare_mem(t_corewar		*corewar);
int			prepare_process_list(t_corewar	*corewar);
int			copy_instruction(t_corewar	*corewar,
					 t_process_list	*process_list);

#endif		/* !COREWAR_H_ */
