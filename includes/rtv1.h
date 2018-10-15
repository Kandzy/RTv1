# include <stdlib.h>
# include <SDL2/SDL.h>
# include <math.h>
# include "../libft/includes/libft.h"

# define TRUE 1
# define FALSE 0
# define ACTIVE 1
# define DISACTIVE 0
# define THREADS 4
# define WIDTH 1366
# define HEIGHT 768

typedef	struct		s_position
{
	int				x;
	int				y;
	int				z;
}					t_position;

typedef	struct		s_rotation
{
	int				rot_x;
	int				rot_y;
	int				rot_z;
}					t_rotation;

typedef	union		u_color
{
	int				color;
	char			rgb[4];
}					t_color;

typedef struct		s_object
{
	char			*object;
	t_color			color;
	int				incline;
	int				radius;
	int 			height;
	t_position		pos;
	t_rotation		angle;
}					t_object;

typedef	struct		s_scene
{
	t_object		*figs;
}					t_scene;

typedef struct		s_window
{
	// t_menu			menu;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int				i;
	int				**buffer;
	int				**current_map;
	int				height;
	int				width;
	int				sflag;
	int				lvl_id;
	int				keystatus;
	short int		resolution;
	int				exit_flag;
}					t_window;