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

// static void	bruno_texture_data(t_mlx *mlx)
// {
// 	mlx->gg->img_sprites[0].addr = mlx_get_data_addr(mlx->gg->anim1, \
// 		&mlx->gg->img_sprites[0].bits_per_pixel, \
// 			&mlx->gg->img_sprites[0].line_length, \
// 			&mlx->gg->img_sprites[0].endian);
// 	mlx->gg->img_sprites[1].addr = mlx_get_data_addr(mlx->gg->anim2, \
// 		&mlx->gg->img_sprites[1].bits_per_pixel, \
// 			&mlx->gg->img_sprites[1].line_length, \
// 			&mlx->gg->img_sprites[1].endian);
// 	mlx->gg->img_sprites[2].addr = mlx_get_data_addr(mlx->gg->anim3, \
// 		&mlx->img_sprites[2].bits_per_pixel, \
// 			&mlx->gg->img_sprites[2].line_length, \
// 			&mlx->gg->img_sprites[2].endian);
// 	mlx->gg->img_sprites[3].addr = mlx_get_data_addr(mlx->gg->anim4, \
// 		&mlx->gg->img_sprites[3].bits_per_pixel, \
// 			&mlx->gg->img_sprites[3].line_length, \
// 			&mlx->gg->img_sprites[3].endian);
// }

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
