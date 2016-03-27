/*
** tab_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by Pillon_m
** Login   <@epitech.net>
**
<<<<<<< HEAD
** Started on  Tue Mar  8 16:05:30 2016 Maxime Pillon
** Last update Sun Mar 27 23:17:56 2016 loens_g
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"

char		**set_cmd_part3(char **cmd)
{
  if ((cmd[22] = my_strdup("fork")) == NULL)
    return (NULL);
  if ((cmd[23] = my_strdup("d")) == NULL)
    return (NULL);
  if ((cmd[24] = my_strdup("lfork")) == NULL)
    return (NULL);
  if ((cmd[25] = my_strdup("d")) == NULL)
    return (NULL);
  if ((cmd[26] = my_strdup("lld")) == NULL)
    return (NULL);
  if ((cmd[27] = my_strdup("d/i,r")) == NULL)
    return (NULL);
  if ((cmd[28] = my_strdup("lldi")) == NULL)
    return (NULL);
  if ((cmd[29] = my_strdup("r/d/i,r/d,r")) == NULL)
    return (NULL);
  if ((cmd[30] = my_strdup("aff")) == NULL)
    return (NULL);
  if ((cmd[31] = my_strdup("r")) == NULL)
    return (NULL);
  if ((cmd[32] = my_strdup(".name")) == NULL)
    return (NULL);
  if ((cmd[33] = my_strdup(".comment")) == NULL)
    return (NULL);
  return (cmd);
}

char		**set_cmd_part2(char **cmd)
{
  if  ((cmd[10] = my_strdup("and")) == NULL)
    return (NULL);
  if ((cmd[11] = my_strdup("r/d/i,r/d/i,r")) == NULL)
    return (NULL);
  if ((cmd[12] = my_strdup("or")) == NULL)
    return (NULL);
  if ((cmd[13] = my_strdup("r/d/i,r/d/i,r")) == NULL)
    return (NULL);
  if ((cmd[14] = my_strdup("xor")) == NULL)
    return (NULL);
  if ((cmd[15] = my_strdup("r/d/i,r/d/i,r")) == NULL)
    return (NULL);
  if ((cmd[16] = my_strdup("zjmp")) == NULL)
    return (NULL);
  if ((cmd[17] = my_strdup("d")) == NULL)
    return (NULL);
  if ((cmd[18] = my_strdup("ldi")) == NULL)
    return (NULL);
  if ((cmd[19] = my_strdup("r/d/i,r/d,r")) == NULL)
    return (NULL);
  if ((cmd[20] = my_strdup("sti")) == NULL)
    return (NULL);
  if ((cmd[21] = my_strdup("r,r/d/i,r/d")) == NULL)
    return (NULL);
  return (set_cmd_part3(cmd));
}

char		**set_cmd_part1()
{
  char		**cmd;

  cmd = malloc(sizeof(char *) * 34);
  if ((cmd[0] = my_strdup("live")) == NULL)
    return (NULL);
  if ((cmd[1] = my_strdup("d")) == NULL)
    return (NULL);
  if ((cmd[2] = my_strdup("ld")) == NULL)
    return (NULL);
  if ((cmd[3] = my_strdup("d/i,r")) == NULL)
    return (NULL);
 if ((cmd[4] = my_strdup("st")) == NULL)
    return (NULL);
 if ((cmd[5] = my_strdup("r,i/r")) == NULL)
    return (NULL);
 if ((cmd[6] = my_strdup("add")) == NULL)
    return (NULL);
 if ((cmd[7] = my_strdup("r,r,r")) == NULL)
    return (NULL);
 if ((cmd[8] = my_strdup("sub")) == NULL)
    return (NULL);
  if ((cmd[9] = my_strdup("r,r,r")) == NULL)
    return (NULL);
 return (set_cmd_part2(cmd));
}
