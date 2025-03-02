/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:53 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/27 23:53:22 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	key_hook(int keycode, t_minirt *mrt)
{
	if (keycode == K_ESC)
		ft_clear_all(mrt, 0);
	return (0);
}

int	key_press(int button, t_minirt *mrt)
{
	if (mrt->selected.id_obj == -1 || button == K_ESC)
		return (key_hook(button, mrt), print_err("\nNo object", "."));
	if (button == K_R)
		mrt->key.rot = YES;
	else if (button == K_T)
		mrt->key.tra = YES;
	else if (button == K_RIGHT)
		mrt->key.right = YES;
	else if (button == K_LEFT)
		mrt->key.left = YES;
	else if (button == K_UP)
		mrt->key.up = YES;
	else if (button == K_DOWN)
		mrt->key.down = YES;
	else if (button == K_Z_O)
		mrt->key.z_i = YES;
	else if (button == K_Z_I)
		mrt->key.z_o = YES;
	else if (button == K_IN || button == K_OUT)
		if (obj_zoom(button, mrt) && mrt->selected.id_obj != -1)
			render_image(mrt);
	if (rotation_translation(mrt) && mrt->selected.id_obj != -1)
		render_image(mrt);
	return (0);
}

int	key_relase(int button, t_minirt *mrt)
{
	(void)button;
	ft_memset(&mrt->key, 0, sizeof(t_keys));
	return (0);
}
