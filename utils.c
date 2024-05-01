#include "mlx.h"
#include <stdlib.h>  
#include <unistd.h>
#include "utils.h" 

int ft_strcmp(char *  s1 , char * s2)
{
    int i = 0;  
    while(s1[i])
    {
        if(s1[i] != s2[i])
        return 0 ; 
        i++ ; 
    }
    return 1 ; 
} 
void init_fract(t_fractol *fractol , char  *name)
{
    fractol->type = name ;  
	fractol->mlx_ptr = mlx_init();
	fractol->mlx_window = mlx_new_window(fractol->mlx_ptr, HEIGHT, WIDTH, "Hello world!");
	fractol->img.img = mlx_new_image(	fractol->mlx_ptr, HEIGHT, WIDTH);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,&fractol->img.bits_per_pixel,&fractol->img.line_length,
								&fractol->img.endian);
    fractol->max_itteration = 42; 
    fractol->x = 0 ; 
    fractol->y = 0 ;
    fractol->zoom = 1.1;
    fractol->over_value =  4;
}

double my_scale_tool(double value, double target_min, double target_max, double old_min, double old_max)
{
    return (target_max - target_min) * (value - old_min) / (old_max - old_min) + target_min;
}


t_complex add_complex(t_complex z1 , t_complex z2)
{
    t_complex result;  
    result.imagine = z1.imagine  +  z2.imagine;
    result.reel= z1.reel + z2.reel; 
    return result;  
}
t_complex complex_square(t_complex z)
{
    t_complex result ; 
    result.imagine = 2 *  z.imagine * z.reel ;
    result.reel = z.reel * z.reel - z.imagine * z.imagine; 
    return result; 
} 

void my_img_pixel_put(t_data *data, int x, int y, int color)
{
char *dst;
dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));


    *(unsigned int*)dst = color;
}

void draw_mandelbort_pixel(t_fractol* fract , int x , int y)
{
 t_complex z1,z2; 
 z1.reel = 0.0 ; 
 z1.imagine = 0.0;
 z2.reel =(my_scale_tool(x,-2,2,0,WIDTH) *fract->zoom) + fract->x ; 
 z2.imagine =(my_scale_tool(y,2,-2,0,HEIGHT)* fract->zoom)+fract->y;
 int i = 1; 
 while(i < fract->max_itteration)
 {
    z1 = add_complex(complex_square(z1),z2);
    if( (z1.reel * z1.reel) + (z1.imagine * z1.imagine) > fract->over_value)
        {
            int color = my_scale_tool(i,BLACK,WHITE,0,fract->max_itteration); 
            my_img_pixel_put(&fract->img,x,y,color); 
            return; 
        }
    i++; 
 }
my_img_pixel_put(&fract->img,x,y,PSYCHEDELIC_COLOR); 
} 
void draw_julia_pixel(t_fractol* fract , int x , int y)
{
    t_complex z1,z2; 
 z2.reel = -0.86 ; 
 z2.imagine = 0.156;
 z1.reel =(my_scale_tool(x,-2,2,0,WIDTH) *fract->zoom) + fract->x ; 
 z1.imagine =(my_scale_tool(y,2,-2,0,HEIGHT)* fract->zoom)+fract->y;
 int i = 1; 
 while(i < fract->max_itteration)
 {
    z1 = add_complex(complex_square(z1),z2);
    if( (z1.reel * z1.reel) + (z1.imagine * z1.imagine) > fract->over_value)
        {
            int color = my_scale_tool(i,BLACK,WHITE,0,fract->max_itteration); 
            my_img_pixel_put(&fract->img,x,y,color); 
            return; 
        }
    i++; 
 }
my_img_pixel_put(&fract->img,x,y,PSYCHEDELIC_COLOR) ; 
}
void draw_all_fractol(t_fractol *fractol)
{
    int x,y;
    y = 0 ;
    while(y < HEIGHT)
    {
        x =0; 
        while(x < WIDTH)
        {
            if(ft_strcmp(fractol->type , "mandelbort"))
                draw_mandelbort_pixel(fractol,x,y);
            else if(ft_strcmp(fractol->type , "julia"))
                 draw_julia_pixel(fractol,x,y); 
            x++;
        } 
        y++  ; 
    } 
    mlx_put_image_to_window(fractol->mlx_ptr,fractol->mlx_window,fractol->img.img,0,0);
} 

