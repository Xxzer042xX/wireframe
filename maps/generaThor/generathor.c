/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generathor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:07:42 by madelmen          #+#    #+#             */
/*   Updated: 2024/12/13 14:07:42 by madelmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    put_zero(int row, int col, FILE *fp)
{
    int        i;
    int        j;

    i = 0;
    while (i < row)
    {
        j = 0;
        while (j < col)
        {
            if (j < col - 1)
            {    
                if (j % 2 == 0)
                    fprintf(fp, "10 ");
                else if (j % 3 == 0)
                    fprintf(fp, "20 ");
                else if (j % 5 == 0)
                    fprintf(fp, "30 ");
                else
                    fprintf(fp, "0 ");
            }
            else
                fprintf(fp, "0");
            j++;
        }
        if (i < row - 1)
            fprintf(fp, "\n");
        i++;
    }
}

int    main(int ac, char **av)
{
    FILE    *fp;
    int        col;
    int        row;

    if (ac != 3)
        return (1);
    col = atoi(av[1]);
    row = atoi(av[2]);
    fp = fopen("flat.fdf", "w");
    if (!fp)
        return (1);
    put_zero(row, col, fp);
    fclose(fp);
    return (0);
}