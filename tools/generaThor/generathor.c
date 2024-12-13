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

int main(int ac, char **av)
{
    FILE *fp;
    int i, j, col, row;
    
	if (ac != 3)
		return (1);
	col = atoi(av[1]);
	row = atoi(av[2]);
	fp = fopen("flat.fdf", "w");
	if (!fp)
		return (1);
	while (i < row)
	{
		j = 0;
		while(j < col)
		{
			if (j < col - 1)
				fprintf(fp, "0 ");
			else
				fprintf(fp, "0");
			j++;
		}
		if (i < row - 1)
			fprintf(fp, "\n");
		i++;
	}
	fclose(fp);
	return (0);
}
