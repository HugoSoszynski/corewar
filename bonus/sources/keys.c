/*
** keys.c for tekdoom in /home/corsin_a/Travail/Infographie/tekdoom_test
**
** Made by corsin_a
** Login   <corsin_a@epitech.net>
**
** Started on  Wed Jan 20 18:00:44 2016 corsin_a
** Last update Fri Mar 25 17:25:48 2016 corsin_a
*/

#include		"corewar.h"

t_bunny_response	key(t_bunny_event_state		state,
			    t_bunny_keysym		key,
			    void			*data)
{
  (void)state;
  (void)data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
