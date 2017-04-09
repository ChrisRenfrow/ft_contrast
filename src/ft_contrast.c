/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 01:37:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/09 03:47:11 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

static t_image *init_image(void)
{
	t_image *image 	= (t_image *)malloc(sizeof(t_image));
	image->magic 	= 0;
	image->width 	= 0;
	image->height	= 0;
	image->gslimit 	= 255;
	image->imgbuff	= 0;
	return (image);
}

static t_contr_data *init_data(void)
{
	t_contr_data *data 	= (t_contr_data *)malloc(sizeof(t_contr_data));
	data->srcpath 		= 0;
	data->dstpath 		= 0;
	data->srcfd 		= 0;
	data->dstfd			= 0;
	data->contrast		= 100;
	return (data);
}

static int usage(void)
{
	printf("Usage: ft_contrast -f [source] -c [contrast] -o [dest]\n");
	return (0);
}

static void parse_args(char *args[], t_contr_data *data)
{
	// TODO - Actually parse args
	data->srcpath = ft_strdup(args[2]);
	data->contrast = ft_atoi(args[4]);
	data->dstpath = ft_strdup(args[6]);
}

static int parse_file(t_contr_data *data)
{
	// TODO - Be more elegant + handle comments `#`
	char *line = data->image->imgbuff;
	data->srcfd = open(data->srcpath, O_RDONLY);

	if(get_next_line(data->srcfd, &line))
		data->image->magic = ft_strdup(line);
	if(get_next_line(data->srcfd, &line))
	{
		data->image->width = ft_atoi(line);
		while(ft_isdigit(*line))
			line++;
		data->image->height = ft_atoi(line);
	}
	if (get_next_line(data->srcfd, &line))
		data->image->gslimit = ft_atoi(line);
	if (get_next_line(data->srcfd, &line))
		data->image->imgbuff = ft_strdup(line);
	return (1);
}

int main(int ac, char *av[])
{
	// TODO - Don't be lazy
	if (ac != 7)
		return (usage());
	t_contr_data *data = init_data();
	data->image = init_image();
	parse_args(av, data);
	parse_file(data);
	printf("File Statistics\n%s\nW - %d H - %d\nGS - %d\nBUFF - %s\n",
			data->image->magic, data->image->width, data->image->height,
			data->image->gslimit, data->image->imgbuff);
}
