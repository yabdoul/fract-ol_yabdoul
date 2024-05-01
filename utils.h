#ifndef UTILS_H 
#define UTILS_H 
#endif
#define WIDTH 800
#define HEIGHT 800
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define WHITE   0xFFFFFF
#define BLACK   0x000000
#define PSYCHEDELIC_COLOR 0xFF00FF
#define MLX_ERR "[minilibx] error !please try Again"
#define MLX_WINDOW_ERROR "[minilibx] : window error"
#include <stdio.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct fractol
{ 
    void* mlx_window; 
    void* mlx_ptr ; 
    int over_value;
    double zoom;
    int max_itteration ; 
    char * type ;
    double x; 
    double y ;
    t_data img ;
} t_fractol ; 

typedef struct complex
{
    double imagine; 
    double reel; 
} t_complex ;


t_complex complex_square(t_complex z) ; 
double my_scale_tool(double value, double target_min, double target_max, double old_min, double old_max);
t_complex add_complex(t_complex z1 , t_complex z2);
void draw_fractol_pixel(t_fractol* fract , int x , int y);
void draw_all_fractol(t_fractol *fract);
void my_img_pixel_put(t_data *data, int x, int y, int color);
void init_fract(t_fractol *fractol , char  *name);
int ft_strcmp(char *  s1 , char * s2); 