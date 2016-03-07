/*
** corewar.h for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/includes/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 17:44:36 2016 Hugo SOSZYNSKI
** Last update Mon Mar  7 18:29:17 2016 Hugo SOSZYNSKI
*/

#ifndef			COREWAR_H_
# define		COREWAR_H_

typedef struct		s_instruction
{
  char			opcode;
  char			octet_codage;
  int			arg[3];
  char			type_arg[3];
}			t_instruction;

typedef struct		s_process
{
  int			reg[16];
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
  char			*name;
  char			*comment;
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
}			t_corewar;

#endif		/* !COREWAR_H_ */
