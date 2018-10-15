/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rtv1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 11:25:08 by dkliukin          #+#    #+#             */
/*   Updated: 2018/09/09 11:25:10 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"
#include <fcntl.h>
#include <stdio.h>

int				quit_wolf(t_window *win, SDL_Event ev)
{
	if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN &&
		ev.key.keysym.sym == SDLK_ESCAPE) || win->exit_flag)
	{
		win->exit_flag = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void save_object_element()
{
	
}

void read_scene_objects(int fd, char **str, t_object *fig){
	while (ft_strcmp(*str, ">"))
	{ 
		get_next_line(fd, str);
		*str = ft_strtrim(*str);
		char **obj = ft_strsplit(*str, ':');
		if (!ft_strcmp(obj[0], "sphere") || !ft_strcmp(obj[0], "cylinder") || !ft_strcmp(obj[0], "cone"))
		{
			fig->object = obj[0];
			obj[1] = ft_strtrim(obj[1]);
			if (!ft_strcmp(obj[1],"{"))
			{
				while(ft_strcmp(*str, "}"))
				{
					get_next_line(fd, str);
					*str = ft_strtrim(*str);
					char **obj = ft_strsplit(*str, ':');
					obj[1] = ft_strtrim(obj[1]);
					if (obj[1] && !ft_strcmp(obj[1],"{"))
					{
						char *s = "{";
						while(get_next_line(fd, &s))
						{
							s = ft_strtrim(s);
							if (!ft_strcmp(s, "},"))
								break;
							if (!ft_strcmp(obj[0], "color"))
							{
								char **rgb = ft_strsplit(s, ',');
								fig->color.rgb[3] = 0;
								fig->color.rgb[0] = ft_atoi(rgb[2]);
								fig->color.rgb[1] = ft_atoi(rgb[1]);
								fig->color.rgb[2] = ft_atoi(rgb[0]);
								// printf("%s\n", s);
							}
							if (!ft_strcmp(obj[0], "position"))
							{
								char **pos = ft_strsplit(s, ':');
								pos[1] = ft_strtrim(pos[1]);
								if (!ft_strcmp(pos[0], "x"))
									fig->pos.x = ft_atoi(pos[1]);
								if (!ft_strcmp(pos[0], "y"))
									fig->pos.y = ft_atoi(pos[1]);
								if (!ft_strcmp(pos[0], "z"))
									fig->pos.z = ft_atoi(pos[1]);
							}
							if (!ft_strcmp(obj[0], "rotation"))
							{
								char **angle = ft_strsplit(s, ':');
								angle[1] = ft_strtrim(angle[1]);
								if (!ft_strcmp(angle[0], "rot_x"))
									fig->angle.rot_x = ft_atoi(angle[1]);
								if (!ft_strcmp(angle[0], "rot_y"))
									fig->angle.rot_y = ft_atoi(angle[1]);
								if (!ft_strcmp(angle[0], "rot_z"))
									fig->angle.rot_z = ft_atoi(angle[1]);
							}
						}
					}
					else if (!ft_strcmp(obj[0], "radius"))
						fig->radius = atoi(obj[1]);
					else if (!ft_strcmp(obj[0], "height"))
						fig->height = atoi(obj[1]);
					else if (!ft_strcmp(obj[0], "incline"))
						fig->incline = atoi(obj[1]);
				}
			}
		}
	}
}

int				read_scene_params(int fd, char **str)
{
	while (ft_strcmp(*str, "]"))
	{
		get_next_line(fd, str);
		// printf("%s\n", *str);
	}
	return 1;
}

int main(void){
	int fd = open("scene/test_scene", O_RDONLY);
	char *str;
	t_scene scene;
	int		n_figs;
	t_object *temp;

	n_figs = 0;
	while(get_next_line(fd ,&str))
	{
		str = ft_strtrim(str);
		if (!ft_strcmp(str, "["))
		{
			// printf("%s\n", str);
			read_scene_params(fd, &str);
		}
		if (!ft_strcmp(str, "<"))
		{
			n_figs++;
			if (n_figs > 1)
				temp = scene.figs;
			scene.figs = (t_object*)ft_memalloc(n_figs * sizeof(t_object));
			if (n_figs > 1)
				ft_memcpy(scene.figs, temp, sizeof(t_object) * n_figs - 1);
			read_scene_objects(fd, &str, &scene.figs[n_figs - 1]);
		}
		
	}
		while (n_figs != 0)
		{
			printf("\n%s: radius: %d, color : %d\n " ,scene.figs[n_figs - 1].object, scene.figs[n_figs - 1].radius, scene.figs[n_figs - 1].color.color);
			printf("height: %d, incline: %d\n",scene.figs[n_figs - 1].height, scene.figs[n_figs - 1].incline);
			printf("position: %d, %d, %d\n",scene.figs[n_figs - 1].pos.x, scene.figs[n_figs - 1].pos.y, scene.figs[n_figs - 1].pos.z);
			printf("rot: %d, %d, %d\n",scene.figs[n_figs - 1].angle.rot_x, scene.figs[n_figs - 1].angle.rot_y, scene.figs[n_figs - 1].angle.rot_z);
			n_figs--;
		}
	































































	
    // t_window win;
	// SDL_Event	ev;

    // if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	// {
	// 	ft_putendl(SDL_GetError());
	// 	return (1);
	// }
    // win.win = SDL_CreateWindow("Wolfenstein 3D", SDL_WINDOWPOS_CENTERED,
    // SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, win.sflag);
    
    // if (win.win == NULL)
	// {
	// 	ft_putendl(SDL_GetError());
	// 	return (2);
	// }
	// win.ren = SDL_CreateRenderer(win.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // SDL_Surface *bmp = SDL_LoadBMP("005.bmp");
    // SDL_Texture *tex = SDL_CreateTextureFromSurface(win.ren, bmp);
    // SDL_FreeSurface(bmp);
    // SDL_RenderClear(win.ren);
    // SDL_RenderCopy(win.ren, tex, NULL, NULL);
    // SDL_RenderPresent(win.ren);
	// // SDL_Delay(2000);
	// if (win.ren == NULL)
	// {
	// 	ft_putendl(SDL_GetError());
	// 	return (3);
	// }
    // while (TRUE)
	// {
	// 	unsigned int start = SDL_GetTicks();
	// 	SDL_RenderClear(win.ren);
	// 	SDL_PollEvent(&ev);
    // 	SDL_RenderCopy(win.ren, tex, NULL, NULL);
    // 	SDL_RenderPresent(win.ren);
	// 	SDL_GetWindowSize(win.win, &(win.width), &(win.height));
	// 	unsigned int end = SDL_GetTicks();
	// 	SDL_Delay(2000);
	// }
	// SDL_Quit();
    // return (0);
}