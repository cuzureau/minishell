/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <cuzureau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:06:19 by cuzureau          #+#    #+#             */
/*   Updated: 2018/01/09 21:09:16 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

char                **ft_getpath(char **tab)
{
    short int       i;

    i = 0;
    while (!ft_strnstr(tab[i], "PATH=", 5))
        i++;
    return(ft_strsplit(tab[i], ':'));
}

void                ft_internal_commands(char **opt, char **path)
{
    short int       i;
    char            *f;
    void            *dir;
    struct dirent   *infos;
    
    i = 0;
    while (path[i])
    {
        while (!(dir = opendir(path[i])))
            i++;
	    while ((infos = readdir(dir)) != NULL)
	    {
	    	if (ft_strequ(opt[0], infos->d_name))
            {
                //printf("opt[0]=\"%s\" ->d_name=\"%s\"\n", opt[0], infos->d_name);
                f = ft_strjoin(path[i], "/");
                f = ft_strjoin(f, opt[0]);
                execve(f, opt, NULL);
            }
	    }
	    closedir(dir);
        i++;
        printf("i=%d;\n", i);
    }

    /*while (path[i])
    {
        
        ft_strequ(opt[0], "ls") ? f = ft_strjoin(path[i], "/ls") : 0;
        ft_strequ(opt[0], "pwd") ? f = ft_strjoin(path[i], "/ls") : 0;
        execve(f, opt, NULL);
        i++;
    }
    */
}

void                ft_external_commands(char **opt, char **path)
{
    (void)opt;
    (void)path;
    printf("external builtin a rediger\n");
}

int                 main(int ac, char **av)
{
    (void)ac;  // a suppr
    char            **opt;
    char            **path;
    while (1)
    {
        write(1, "$> ", 3);
        get_next_line(1, &av[0]);
        opt = ft_strsplit(av[0], ' ');
        path = ft_getpath(&av[2]);
        if (ft_strequ(opt[0], "echo") || ft_strequ(opt[0], "cd") || \
        ft_strequ(opt[0], "setenv") || ft_strequ(opt[0], "unsetenv") || \
        ft_strequ(opt[0], "env") || ft_strequ(opt[0], "exit"))  
            ft_external_commands(opt, path);
        else
            ft_internal_commands(opt, path);
        
    }
    return (0);
}

/*
    pid_t   father;

    father = fork();
    if (father > 0)
    {
        wait(0);
        ft_putendl("father");
    }
    if (father == 0)
    {
        execve("/bin/ls", &av[0], NULL);
    }
*/
