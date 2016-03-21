/*
** corewar.h for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 17:44:36 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 17:30:43 2016 Hugo SOSZYNSKI
*/

#ifndef			COREWAR_H_
# define		COREWAR_H_

#include		"op.h"

#ifndef			SUCCESS
# define		SUCCESS		(0)
#endif			/* !SUCCESS */

#ifndef			ERROR
# define		ERROR		(1)
#endif			/* !ERROR */

#ifndef			IS_LIT_ENDIAN
# define		IS_LIT_ENDIAN	(check_for_endianess())
#endif			/* !IS_LIT_ENDIAN */

typedef struct		s_instruction
{
  char			opcode;
  char			octet_codage;
  int			arg[3];
  char			type_arg[3];
}			t_instruction;

typedef struct		s_process
{
  char			reg[REG_NUMBER * REG_SIZE];
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
  char			*prog;
  unsigned int		address;
  unsigned int		nb_champion;
}			t_champion;

typedef struct		s_corewar
{
  t_process_list	*process_list;
  unsigned int		cycle_to_die;
  unsigned long int	actual_cycle;
  char			champions_alive[4];
  unsigned char		nb_champions;
  t_champion		champions_info[4];
  char			mem[MEM_SIZE];
  unsigned int		live_nb;
}			t_corewar;

int			init_champ(t_process_list	*process_list,
				   int			nb_file,
				   char			*file[]);
int			check_for_endianess(void);
void			my_reverse_bytes(void		*_value,
					 unsigned int 	size);
void			error_message(char		*msg);
int			error_file(char			*start,
				   char			*name,
				   char			*end);

#endif		/* !COREWAR_H_ */
