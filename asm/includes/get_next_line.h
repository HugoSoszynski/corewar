/*
** get_next_line.h for  in /home/pillon_m/rendu/rendu/CPE_2015_getnextline
**
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
**
** Started on  Mon Jan  4 16:29:16 2016 maxime pillon
** Last update Wed Mar 23 11:35:32 2016 
*/

#ifndef READ_SIZE
# define READ_SIZE (1)

char	*my_realloc(char *, int);
char	*cp_buffer(char *, char *, int, int);
char	*copy_buffer_ret(char *, char *, int *);
char	*get_next_line(int);

#endif /* !READ_SIZE */
