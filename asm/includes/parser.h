/*
** parser.h for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/includes/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 13:43:06 2016 Grégoire Loens
** Last update Tue Mar 22 11:17:04 2016 
*/

#ifndef	PARSER_H_
# define PARSER_H_

int	my_strlen(char *);
int	error_message(char *);
int	error_message_parser(char *message, int nbr);
int	arg_direct(char *);
int	arg_indirect(char *);
int	arg_register(char *);
int	check_is_type(char*, char *);
int	check_one_arg(char *, char *);
int	check_validity(char *, char **);
int	check_cmd(char *);
int	is_hexa(char );
int	check_dot_code(char *);
int	check_dot_comment(char *);
int	check_dot_name(char *);
int	check_exist_cmd(char *, char *cmd);
int	check_label_cmd(char *);
int	check_label(char *);
int	start_word(char *, int);
char	*my_getword(char *, int);
char	**set_cmd_part1();
char	**set_cmd_part2(char **);
int	my_isnum(char *);
int	my_isalpha(char *);
int	error_message_parser(char *, int);
int	error_message(char *);
int	my_isalpha_num(char );
int	my_strcmp(char *, char *);
int	my_ispace(char );
char	*my_isspace(char *);
int	gst_comment(char *);
int	gst_name(char *);
int	gst_cmd(char *, char **);
int	gst_extend(char *);
int	gst_label(char *);
int	my_getnbr(const char *, int *);
void	find_word(char *, char *, int *);
void	move_to_word(char *, char *, int *);
char	**my_make_tab(char **, char *, int , char);
int	my_counter_words(char *, char *);
char	**my_str_to_wordtab(char *, int *, char *);
char	*my_strdup(const char *);
int	type_of_cmd(char *, char **);
int	parsing(char *);
int	verif_cmd_line(int, int);

#endif	/* !PARSER_H_ */
