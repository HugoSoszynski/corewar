/*
** corewar.h for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 17:44:36 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 19:53:51 2016 Hugo SOSZYNSKI
*/

#ifndef			COREWAR_H_
# define		COREWAR_H_

# include		<stdbool.h>
# include		<stddef.h>
# include		"op.h"
# include		"define_op_cycles.h"

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
  unsigned char		opcode;
  int			arg[3];
  char			type_arg[3];
  bool			correct;
}			t_instruction;

typedef struct		s_process
{
  int			reg[REG_NUMBER];
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

typedef struct		s_op_tab
{
  int			(*check)(char			opcode);
  void			(*exec)(t_corewar 		*corewar,
			        t_process_list		*process_list);
  void			(*copy)(t_corewar		*corewar,
			        t_process_list		*process_list);
  int			cycle;
}			t_op_tab;

# ifndef		OP_TAB
#  define		OP_TAB		((t_op_tab*)(corewar->op_tab))
# endif			/* !OP_TAB */

int			check_h(void);
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
int			check_instruction(t_corewar	*corewar,
					  t_process_list	*process_list);
void 			move_pc(t_process_list		*process_list);
t_process_list		*kill_zombies(t_process_list 	*list,
				      unsigned int 	nb_champion);
void			free_processlist(t_process_list *list);
void			copy_args(t_corewar		*corewar,
				  t_process_list	*process_list);
int			prepare_op_tab(t_corewar	*corewar);
void			check_reg(t_process_list	*current);
void			print_champ_win(t_champion	*champion,
					int		nb);
void			print_champ_dead(t_champion	*champion,
					 int		nb);
void			print_champ_alive(t_champion	*champion,
					  int		nb);
int			check_winner(t_corewar		*corewar);
void			address_2_setand_left(t_corewar	*corewar);
int			verif_pc(int		pc);

#endif		/* !COREWAR_H_ */
