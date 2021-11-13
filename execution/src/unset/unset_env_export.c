/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:07:33 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:07:34 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	unset_env_export(t_ast *s_ast, t_env_export *env_export)
{
	int	i;

	i = 1;
	while (s_ast->argv[i])
	{
		if (valid_arg(s_ast->argv[i]) == EXIT_SUCCESS)
		{
			if (remove_arg_env_export(env_export, s_ast->argv[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (valid_input(s_ast));
}

int	remove_arg_env_export(t_env_export *env_export, char *arg)
{
	if (remove_arg_env(env_export, arg) == ERROR)
		return (ERROR);
	if (remove_arg_export(env_export, arg) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}

int	remove_arg_env(t_env_export *env_export, char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_fstrjoin(arg, "=");
	if (temp == NULL)
		return (ERROR);
	while (env_export->env[i])
	{
		if (ft_strbstr(env_export->env[i], temp))
		{
			free(env_export->env[i]);
			env_export->env[i] = ft_fstrdup("NaN");
			if (env_export->env[i] == NULL)
			{
				free(temp);
				return (ERROR);
			}
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(temp);
	return (EXIT_FAILURE);
}

int	remove_arg_export(t_env_export *env_export, char *arg)
{
	char	*temp0;
	char	*temp;
	int		ret;

	temp0 = ft_fstrjoin("declare -x ", arg);
	if (temp0 == NULL)
		return (ERROR);
	ret = delete_export_elements(env_export->export, temp0);
	if (ret != EXIT_FAILURE)
	{
		free (temp0);
		return (ret);
	}
	temp = ft_fstrjoin(temp0, "=");
	free(temp0);
	if (temp == NULL)
		return (ERROR);
	ret = delete_export_elements(env_export->export, temp);
	free(temp);
	return (ret);
}


int	delete_export_elements(char **export, char *temp)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], temp))
		{
			free(export[i]);
			export[i] = ft_fstrdup("NaN");
			if (export[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}