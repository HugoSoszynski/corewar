/*
** pile_label.h for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/includes/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 01:12:56 2016 Grégoire Loens
** Last update Fri Mar 25 02:13:54 2016 
*/

#ifndef PILE_LABEL_H_
# define PILE_LABEL_H_

typedef struct	s_pile
{
  char		*label_name;
  int		nb_octet;
  int		nb_line;
  struct s_pile	*next;
}		t_pile;


t_pile		*init_pile(void);
t_pile		*add_label(t_pile *);

#endif /* !PILE_LABEL_H_ */
