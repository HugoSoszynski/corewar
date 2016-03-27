/*
** my_getenv.c for wolf3d in /home/soszyn_h/rendu/Infographie/gfx_wolf3d
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Dec 30 15:30:36 2015 Hugo SOSZYNSKI
** Last update Sun Mar 27 20:58:23 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

char		*my_getenv(char **env, char *var)
{
  int		var_len;
  int		count;
  int		i;

  count = 0;
  var_len = my_strlen(var);
  while (env[count] != NULL && my_strncmp(env[count], var, var_len) != 0)
    count++;
  if (env[count] == NULL)
    return (NULL);
  i = 0;
  while (env[count][i] != '\0' && env[count][i] != '=')
    i++;
  i++;
  if (env[count][i] == '\0')
    return (NULL);
  return (&(env[count][i]));
}
