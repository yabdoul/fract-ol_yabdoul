/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:25:05 by yabdoul           #+#    #+#             */
/*   Updated: 2024/05/02 15:00:37 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h" 

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

double my_scale_tool(double value, double target_min, double target_max, double old_min, double old_max)
{
    return (target_max - target_min) * (value - old_min) / (old_max - old_min) + target_min;
}
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
// TODO functions atoi a version to handle doubles !!
double ft_atof(const char *nptr)
{
    double result = 0.000f;
    int sign = 1;
    int i = 0;
    int  decimal_point_seen = 0;
    double decimal_multiplier = 0.1f;

    if(nptr[i] == '.')
        exit(0);
    while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
           nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
        i++;

    if (nptr[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (nptr[i] == '+')
    {
        i++;
    }

    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result *= 10.0f;
        result += (nptr[i] - '0');
        i++;
    }

    if (nptr[i] == '.')
    {
        decimal_point_seen = 1;
        i++;
    }
    if(nptr[i] == '.')
        exit(0);

    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result += (nptr[i] - '0') * decimal_multiplier;
        decimal_multiplier *= 0.1f; 
        i++;
    }
     if(nptr[i] == '.')
        exit(0);
    return result * sign;
    
}
