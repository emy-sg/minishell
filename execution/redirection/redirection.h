/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:20:45 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 16:20:46 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

//redirection.c
int			ft_redir(t_ast *s_ast, t_env_export *env_export,
				char *heredoc_file_name);

//back_to_normal.c
int			redir_in_back_to_normal(t_redirect *redirect);
int			redir_out_back_to_normal(t_redirect *redirect);

//here_doc.c
int			exec_here_doc(t_ast *s_ast, t_env_export *env_export,
				char *heredoc_file_name);
int			here_doc(t_env_export *env_export, char *limiter,
				char *heredoc_file_name);
int			cmd_has_here_doc(t_ast *s_ast);
int			nbr_here_doc(t_ast *s_ast);
char		*mini_gnl(void);
void		child_here_doc(t_env_export *env_export, char *limiter, int fd);

//init_redirection.c
t_redirect	*init_redirect(t_ast *s_ast, char *heredoc_file_name);
int			open_files(t_ast *s_ast, t_redirect *redirect,
				char *heredoc_file_name);

//simple_redirection.c
int			simple_redir_in(t_redirect *redirect, t_ast *s_ast);
int			simple_redir_out(t_redirect *redirect, t_ast *s_ast);

#endif
