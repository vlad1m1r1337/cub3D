// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   bruno_helper.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/30 15:13:01 by jfrances          #+#    #+#             */
// /*   Updated: 2023/09/30 15:13:02 by jfrances         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/cub3d.h"


// void	bruno_textures(t_mlx *mlx)
// {
// 	mlx->gg->anim1 = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/anim1.xpm", \
// 	&mlx->gg->img_sprites[0].width, &mlx->gg->img_sprites[0].height);
// 	mlx->gg->anim2 = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/anim2.xpm", \
// 	&mlx->gg->img_sprites[1].width, &mlx->gg->img_sprites[1].height);
// 	mlx->gg->anim3 = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/anim3.xpm", \
// 	&mlx->gg->img_sprites[2].width, &mlx->gg->img_sprites[2].height);
// 	mlx->gg->anim4 = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/anim4.xpm", \
// 	&mlx->gg->img_sprites[3].width, &mlx->gg->img_sprites[3].height);
// 	if (mlx->gg->anim1 == NULL || mlx->gg->anim2 == NULL \
// 	|| mlx->gg->anim3 == NULL || mlx->gg->anim4 == NULL)
// 		error_handle(mlx->gg);
// 	bruno_texture_data(mlx);
// }
