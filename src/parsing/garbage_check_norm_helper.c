/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_check_norm_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:32:13 by jfrances          #+#    #+#             */
/*   Updated: 2023/10/02 16:32:14 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	norm_cnt(t_helper *h, int flg)
{
	if (flg == 1)
		h->n_cnt++;
	else if (flg == 2)
		h->s_cnt++;
	else if (flg == 3)
		h->e_cnt++;
	else if (flg == 4)
		h->w_cnt++;
	else if (flg == 5)
		h->f_cnt++;
	else if (flg == 6)
		h->c_cnt++;
	return (0);
}
