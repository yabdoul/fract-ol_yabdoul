/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:25:05 by yabdoul           #+#    #+#             */
/*   Updated: 2024/05/03 14:02:39 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.imagine = z1.imagine + z2.imagine;
	result.reel = z1.reel + z2.reel;
	return (result);
}
t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.imagine = 2 * z.imagine * z.reel;
	result.reel = z.reel * z.reel - z.imagine * z.imagine;
	return (result);
}

double	my_scale_tool(double value, double target_min, double target_max,
		double old_min, double old_max)
{
	return ((target_max - target_min) * (value - old_min) / (old_max - old_min)
		+ target_min);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(char *nptr, t_float *float_data)
{	
	check_is_degit(nptr);
	if (ft_strchr(nptr, ' ') || ft_strchr(nptr, '\t') || ft_strchr(nptr, '\n')|| nptr[float_data->i] == '.')
		exit(0);
	if (nptr[float_data->i] == '-' || nptr[float_data->i] == '+')
		if (nptr[float_data->i++] == '-')
			float_data->sign *= -1;
	while (nptr[float_data->i] >= '0' && nptr[float_data->i] <= '9')
	{
		float_data->result *= 10.0f;
		float_data->result += (nptr[float_data->i++] - '0');
	}
	if (nptr[float_data->i++] == '.')
		float_data->decimal_point_seen = 1;
	while (nptr[float_data->i] >= '0' && nptr[float_data->i] <= '9')
	{
		float_data->result += (nptr[float_data->i] - '0')
			* float_data->decimal_multiplier;
		float_data->decimal_multiplier *= 0.1f;
		float_data->i++;
	}
	if (nptr[float_data->i] == '.')
		exit(0);
	return (float_data->result * float_data->sign);
}
