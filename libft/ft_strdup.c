/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lperron <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:35:03 by lperron      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 17:13:14 by lperron     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (src[i] != '\0')
		i++;
	res = (char*)malloc((sizeof(*res) * (i + 1)));
	if (res)
	{
		i = 0;
		while (src[i] != '\0')
		{
			res[i] = src[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
