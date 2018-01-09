/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <cuzureau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:06:19 by cuzureau          #+#    #+#             */
/*   Updated: 2017/12/18 14:25:31 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         main(int ac, char **av)
{
    while (1)
    {
        write(1, "$> ", 3);
        get_next_line(1, av[1]);
    }
    return (0);
}