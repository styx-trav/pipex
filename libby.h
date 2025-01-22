/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libby.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:25:57 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 16:27:52 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBY_H
# define LIBBY_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_args
{
	char	**args1;
	char	**args2;
	char	*com1;
	char	*com2;
	int		outfile;
}	t_args;

//from where.c
int		find_command(t_args *args);
int		find_command2(t_args *args);
char	*copy(char *s1, char *write, int i);
char	*join(char *s1, char *s2);

//from checker.c
t_args	*check_comms(char **argv);
int		isfile(char *filename);
char	*comm(char *command);
t_args	*make_args(void);
int		is_outfile(t_args *args, char *outfile);

//from utils.c
void	print(char *str);
void	print_nl(char *str);
void	print_zsh_err(char *str, char *name);

//from utils_free.c
void	free_prot(char **tab, int j);
void	free_prot_num(char **tab, int j);
t_args	*free_args(t_args *args);

//from split.c
char	**split(char *str, char c, char *add);
char	**add_add(char **res, char *add);
char	**init(char **res, int end);
int		fill_next(char *str, char ***res, int i, int k);
int		ct_words(char *str, char c);

//from attempt.c
int		not_main(t_args *args);

#endif
