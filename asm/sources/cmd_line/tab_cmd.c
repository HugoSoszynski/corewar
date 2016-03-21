/*
** tab_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Tue Mar  8 16:05:30 2016
** Last update Mon Mar 21 14:25:17 2016 Grégoire Loens
*/

#include	<stdlib.h>

char		**set_cmd_part2(char **cmd)
{
  cmd[22] = my_strdup("fork");
  cmd[23] = my_strdup("1d");
  cmd[24] = my_strdup("lfork");
  cmd[25] = my_strdup("1d");
  cmd[26] = my_strdup("lld");
  cmd[27] = my_strdup("2d/i,r");
  cmd[28] = my_strdup("lldi");
  cmd[29] = my_strdup("2r/d/i,r/d,r");
  cmd[30] = my_strdup("aff");
  cmd[31] = my_strdup("1r");
  cmd[32] = my_strdup(".name");
  cmd[33] = my_strdup(".comment");
  return (cmd);
}

char		**set_cmd_part1()
{
  char		**cmd;

  #include	<string.h>
  cmd = malloc(sizeof(char *) * 35);
  cmd[0] = my_strdup("live");
  cmd[1] = my_strdup("1d");
  cmd[2] = my_strdup("ld");
  cmd[3] = my_strdup("2d/i,r");
  cmd[4] = my_strdup("st");
  cmd[5] = my_strdup("3r,d/r");
  cmd[6] = my_strdup("add");
  cmd[7] = my_strdup("3r,r,r");
  cmd[8] = my_strdup("sub");
  cmd[9] = my_strdup("3r,r,r");
  cmd[10] = my_strdup("and");
  cmd[11] = my_strdup("3r/d/i,r/d/i,r");
  cmd[12] = my_strdup("or");
  cmd[13] = my_strdup("3r/d/i,r/d/i,r");
  cmd[14] = my_strdup("xor");
  cmd[15] = my_strdup("3r/d/i,r/d/i,r");
  cmd[16] = my_strdup("zjmp");
  cmd[17] = my_strdup("1d");
  cmd[18] = my_strdup("ldi)";
  cmd[19] = my_strdup("2r/d/i,r/d/i");
  cmd[20] = my_strdup("sti");
  cmd[21] = my_strdup("3r,r/d/i,r/d");
  return(set_cmd_part2(cmd));
}
