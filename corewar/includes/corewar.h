/*
** corewar.h for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 17:44:36 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 22:34:01 2016 corsin_a
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

# define		IS_DEAD		(0)
# define		IS_RUN		(1)
# define		IS_ALIVE	(2)

typedef struct		s_instruction
{
  char			opcode;
  char			octet_codage;
  int			arg[3];
  char			type_arg[3];
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
  t_instruction		current;
  unsigned int		cycle;
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

#endif		/* !COREWAR_H_ */
