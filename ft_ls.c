/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:44:08 by qbackaer          #+#    #+#             */
/*   Updated: 2019/08/29 18:28:01 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//check the input args and separate files from directories, then call list on them.
//to implement:  error checking and frees.
static int	ls_dispatch(char **arg_list, char *opt_list)
{
	char		**roam;
	char		**dir_list;
	char		**reg_list;
	struct stat	st_buff;

	dir_list = NULL;
	reg_list = NULL;
	if (!arg_list)
	{
		// list home directory (".")
		return (1);
	}
	sort_args(&arg_list, opt_list);
	roam = arg_list;
	ft_putendl("we just get out of sort_args");
	while (*roam)
	{
		stat(*roam, &st_buff);
		ft_putendl("stat done");
		if (S_ISDIR(st_buff.st_mode))
		{
			dir_list = update_args(dir_list, *roam);
		}
		else
		{
			reg_list = update_args(reg_list, *roam);
		}	
		roam++;
	}
	ft_putendl("we get out of dispatch");
	//list all files from reg_list first, respecting options.
	//loop on reg_list and list their content.
	return (1);
}

//review error checking and frees.
int			main(int argc, char **argv)
{
	char *opt_list;
	char **arg_list;

	opt_list = NULL;
	arg_list = NULL;
	if (!parse(argc, argv, &opt_list, &arg_list))
	{
		arg_free(arg_list, opt_list);
		return (1);
	}
	if (!check_opt(opt_list, arg_list))
		return (1);
	ls_dispatch(arg_list, opt_list);
	arg_free(arg_list, opt_list);
	return (0);
}
