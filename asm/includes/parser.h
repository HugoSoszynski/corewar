/*
** parser.h for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/includes/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 13:43:06 2016 Grégoire Loens
** Last update Fri Mar 25 06:05:03 2016 
*/

#ifndef	PARSER_H_
# define PARSER_H_

#include	"pile_label.h"
#include	"asm.h"


t_cmd		*init_first_cmd(void);
t_cmd		*init_cmd(void);
char		**set_tab_part1(void);
t_pile		*init_pile(void);
t_pile		*stock_pile_for_call(t_pile *, char *, int);
t_pile		*add_label(t_pile *label);
t_pile		*stock_pile_for_def(t_pile *, char *, int);
t_cmd		*add_cmd(t_cmd *);
int		add_octet(t_cmd *arg);
t_cmd		*set_octet_label(t_cmd *cmd);
t_cmd		*stock_label_cmd(char *, t_cmd *);
t_cmd		*stock_label(char *, t_cmd *);
t_cmd		*stock_code(char *, t_cmd *);
int		label_and_prog_size(t_cmd *, int *);
t_cmd		*stock_cmd(char *, t_cmd *);
int		strcmpend(char *str1, char *str2);
int		calc_with_def(t_cmd *, t_cmd *, t_cmd *);
int		calc_with_call(t_cmd *, t_cmd *, t_cmd *);
int		add_octet(t_cmd *);
header_t	*create_cor_header(char *, char **, int);
int		write_cor_header(header_t *, int, char *);
char		*to_do_cor(char *filename);
int		write_cor(t_cmd *, char *);
int		write_file(int fd, t_cmd *);
unsigned char	my_getnbr_base(char *str, const char *base);
char		*check_one_name(t_cmd *cmd);
char		**where_comment(t_cmd *);
int	my_strlen(const char *);
int	error_message(char *);
int	error_message_line(char *,int , char *);
int	error_message_parser(char *message, int nbr);
int	arg_direct(char *);
int	error_message_parser1(char *, int);
int	error_message_nonb(char *);
char	*my_strncat(char *dest, char *src, int nbr);
int	my_islabelchar(char);
int	arg_indirect(char *);
int	arg_register(char *);
int	check_is_type(char*, char *);
int	my_islabel(char *);
int	check_one_arg(char *, char *);
int	check_validity(char *, char **);
int	check_cmd(char *);
int	is_hexa(char );
int	check_dot_code(char *);
int	check_dot_comment(char *);
int	check_dot_extend(char *);
int	check_dot_name(char *);
int	check_exist_cmd(char *, char **cmd);
int	check_label_cmd(char *);
int	check_label(char *);
int	start_word(char *, int);
char	*my_getword(char *, int);
char	**set_cmd_part1();
char	**set_cmd_part2(char **);
char	**set_cmd_part3(char **);
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
int	gst_code(char *);
int	my_getnbr(const char *, int *);
void	find_word(char *, char *, int *);
void	move_to_word(char *, char *, int *);
char	**my_make_tab(char **, char *, int , char *);
int	my_counter_words(char *, char *);
char	**my_str_to_wordtab(char *, int *, char *);
char	*my_strdup(const char *);
int	type_of_cmd(char *);
int	parsing(char *, int);
int	verif_cmd_line(int, char *);
int	my_put_nbr_base(int, char *);

#endif	/* !PARSER_H_ */
