/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:28 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:43:29 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSER_H
# define PARSER_H

int		parse_and_execute(t_lexer *s_lexer, t_env_export *env_export);
t_ast	*init_ast(int type);
t_ast	*parse_command(t_token **s_token, t_lexer *s_lexer, char **table_of_env_var);
t_ast	*parse_simple_command(t_token **s_token, t_lexer *s_lexer, char **table_of_env_var);

void	add_arg_to_simple_cmd(t_token **s_token, t_lexer *s_lexer, t_ast *s_cmd, char **table_of_env_var);
void	add_redir_to_simple_cmd(t_lexer *s_lexer, t_token **s_token, t_ast *s_cmd, char **table_of_env_var);
void	add_simple_cmd_to_pipeline(t_ast *s_parent, t_ast *s_child);
void    add_string_to_table_of_args(char **cap_content, t_ast *s_cmd);

char	*expand_dollar_sign(char *content, int *index, char **table_of_env_var);
char	*get_env_var_value(char *var, int size, char **table_of_env_var);
char    *get_env_var_name(char *content, int i, int *j);
char    *expand_string_within_double_quotes(char **table_of_env_var, char *content);
char    *extract_string_within_dollar_sign(t_ast *s_cmd, char **str_before, char *content);
char	*extract_string_within_quotes(char *content, int *index, char char_quote);

void    ft_strjoin_and_free(char **cap_content, char **str);
void    free_ast(t_ast *s_ast);
void    free_simple_cmd(t_ast *s_simple_cmd);
void    free_lexer(t_lexer **s_lexer);
void    free_token(t_token **s_token);
void    free_table_of_string(char **argv);
void    free_table_of_redir(t_redir **s_redir);

int		get_size_of_table(char **table);
int     get_size_of_redir_table(t_redir **table);
void    add_redir_to_table_of_redirection(t_ast *s_cmd, t_token **s_redir, t_token **s_filename, char **table_of_env_var);
void	fill_table_of_redir(t_ast *s_cmd, t_token **s_redir, t_token **s_filename, char *str);

t_redir	*init_redir(t_token *s_redir, char *name_file);

char	*unlock_file_name(char *content, char **table_of_env_var);
void	unlock_string(char *content, t_ast *cmd, char **table_of_env_var);

char	**ft_realloc_table(char **args, int size);
t_redir	**ft_realloc_redir_table(t_redir **s_redir, int i);
#endif