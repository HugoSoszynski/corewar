/*
** tab_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar  8 16:05:30 2016 
** Last update Tue Mar  8 16:06:57 2016 
*/

char		**set_cmd_part1()
{
  char**cmd;

  cmd[0] = "live";
  cmd[1] = "1d";
  cmd[2] = "ld";
  cmd[3] = "2d/i,r";
  cmd[4] = "st";
  cmd[5] = "3r,d/r";
  cmd[6] = "add";
  cmd[7] = "3r,r,r";
  cmd[8] = "sub";
  cmd[9] = "3r,r,r";
  cmd[10] = "and";
  cmd[11] = "3r/d/i,r/d/i,r";
  cmd[12] = "or";
  cmd[13] = "3r/d/i,r/d/i,r";
  cmd[14] = "xor";
  cmd[15] = "3r/d/i,r/d/i,r";
  cmd[16] = "zjmp";
  cmd[17] = "1d";
  cmd[18] = "ldi";
  cmd[19] = "2r/d/i,r/d/i";
  cmd[20] = "sti";
  cmd[21] = "3r,r/d/i,r/d";
  return (set_cmd_part2(cmd));
}

char		**set_cmd_part2(char **cmd)
{
  cmd[22] = "fork";
  cmd[23] = "1d";
  cmd[24] = "lfork";
  cmd[25] = "1d";
  cmd[26] = "lld";
  cmd[27] = "2d/i,r";
  cmd[28] = "lldi";
  cmd[29] = "2r/d/i,r/d,r";
  cmp[30] = "aff";
  cmp[31] = "1r";
  cmp[32] = ".name";
  cmp[33] = ".comment";
  return (cmd);
}
