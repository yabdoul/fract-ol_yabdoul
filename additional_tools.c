/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:49:15 by yabdoul           #+#    #+#             */
/*   Updated: 2024/05/03 14:04:57 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && (unsigned char)c != s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}
t_float* init_float_struct(t_float * float_data) 
{
	float_data->result = 0.000f;
    float_data->sign = 1;
	float_data->i = 0;
    float_data->decimal_point_seen = 0;
    float_data->decimal_multiplier = 0.1f;
	return  float_data; 
}
int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || (c == '.' || c == '-')) ;
}
void check_is_degit(char * str)
{
	int i  = 0 ;
	while(str[i]) 
	{
		if(!ft_isdigit(str[i]))
			exit(0);
		if(str[i] == '-' && str[i+1] == '\0')
			exit(0); 
		i++; 		
	}
} 