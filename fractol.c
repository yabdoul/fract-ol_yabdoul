#include <stdio.h>
#include <stdlib.h>
#include "mlx.h" // Assuming you have the necessary MLX library
#include "utils.h"   
// #include <X11/X.h>
int	handle_keypress(int keysym, t_fractol* fractol)
{
    if (keysym == 53)
    { 
        mlx_destroy_image(fractol->mlx_ptr,fractol->img.img);
        mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_window);
        exit(0); 
    }
    if(keysym == 123) 
        fractol->x+=0.1*fractol->zoom ;
    if(keysym == 124)
        fractol->x-=0.1*fractol->zoom;
    if(keysym == 125)
        fractol->y -=0.1*fractol->zoom;
    if(keysym == 126)
        fractol->y +=0.1*fractol->zoom;
 
    draw_all_fractol(fractol); 
    return (0);
}
int handle_mouse_move(int keysym , int x , int y, t_fractol* fractol)
{
       if(keysym == 5)
        fractol->zoom *= 1.1;
    if(keysym == 4)
        fractol->zoom /= 1.1;
        draw_all_fractol(fractol);
        return 0;
} 
int  handle_no_event()
{
    return(0);
}
int	main(int ac  ,  char  **  av )
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    t_fractol *fractol;
    fractol = (t_fractol *)malloc(sizeof(t_fractol));
    // printf("%s\n",av[1]) ; 
    init_fract(fractol,av[1]);
    draw_all_fractol(fractol);
    mlx_loop_hook(fractol->mlx_ptr, &handle_no_event, fractol);
    mlx_hook(fractol->mlx_window, 02, (1L<<0), &handle_keypress, fractol);
    mlx_mouse_hook(fractol->mlx_window,&handle_mouse_move,fractol); 
    mlx_loop(fractol->mlx_ptr);
}
