/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 01:41:00 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/09 03:21:03 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# include "libft.h"

typedef struct	s_image
{
				char 	*magic;
				int 	width;
				int 	height;
				int 	gslimit;
				char	*imgbuff;
}				t_image;

typedef struct	s_contr_data
{
				char 	*srcpath;
				char 	*dstpath;
				int		srcfd;
				int 	dstfd;
				int 	contrast;
				t_image *image;
}				t_contr_data;

#endif
#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H



#endif
