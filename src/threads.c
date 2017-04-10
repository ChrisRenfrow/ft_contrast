/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 17:24:20 by irhett            #+#    #+#             */
/*   Updated: 2017/04/09 18:01:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

// sorry I spent so much time looking over the thread stuff and not over the
// code you'd already written. feel free to modify this to make it work with
// your code. this is mostly pseudo but the thread code should be intact


// you want to set getnextline's BUFF_SIZE to ~2000 for this project to save
// time and increase speed of reading the file

#define NUM_THREADS 10

typedef struct		s_image_data
{
	unsigned int	wid;			//	number of columns of pixels
	unsigned int	len;			// number of rows for pixels
	
	pixel_data_type	**pixels;		// double array [len][wid] of pixel
									// structure type. would have to be 
									// modified for handling R,G,B vs
									// single-byte colors
}					t_image_data;

typedef struct		s_thread_data
{
	unsigned int	start_row;
	unsigned int	end_row;
	t_image_data	*image;
}					t_thread_data;

void	*do_stuff_to_rows(void	*thread_data)
{
	unsigned int	i;
	t_image_data	*t;

	t = (t_thread_data*)thread_data;
	i = t->start_row;
	while (i < t->end_row)
	{
		// perform contrast on this row of data
		i++;
	}
	return (0);
}


int		main(int argc, char **argv)
{
	t_image_data	*data;
	unsigned int	last_row;
	unsigned int	i;

	pthread_attr_t	*attr;		// for threads, leave it alone except for
								// the mandatory functions

	pthread_t		*threads[NUM_THREADS];	// array of the threads
	
	if (pthread_attr_init(attr))
		ft_error("unable to initialize thread attribute");
	
	// read in file to populate (t_image_data *data)
	// 		setting wid, len, values, etc
	
	i = 0;
	while (i < NUM_THREADS);
	{
		unsigned int startrow = last_row;
		unsigned int endrow = startrow + 100;
		if (endrow > data->len)
			endrow = data->len;
		last_row = endrow + 1;
		t_thread_data *some_data = init(startrow, endrow, data);
		pthread_create(threads[i], attr, do_stuff_to_rows, some_data);
		// ^ this will have to be revised, thread need to not quit on done
		// but have a way to get new instructions
	}

	// do stuff here to re-start the threads with new data, keeping track of the
	// (last_row) allocated
	
	// once all the data has been read, set up listeners with 
	// pthread_join() to know when a thread has finished and exited
	// 
	// while (num_threads_still_active > 0)
	// 		do_stuff();
	//
	// now that all threads have been finished, write to the file
	// free all the image data
	// free all the thread data
	//

	pthread_attr_destroy(attr);
	exit(0);
}
