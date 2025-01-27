#include "headers/minirt.h"
void vec_print(t_vec3d a)
{
	printf("{%.1f, %.1f, %.1f}\n",a.x, a.y, a.z);
}
void color_prints(t_color a)
{
	printf("{%d, %d, %d}\n",a.r, a.g, a.b);
}
int main(){

    t_minirt minirt;
	t_object *obj;

    printf("=========Camera===========\n");
	vec_print(minirt.camera.position);
	vec_print(minirt.camera.normal);
	printf("%d\n", minirt.camera.fov);
	// vec_print(minirt.camera.position);
	printf("==========================\n");
	printf("=========Abding===========\n");
	printf("%f\n", minirt.am_light.al);
	printf("==========================\n");
	printf("=========Lighting===========\n");
	vec_print(minirt.light.position);
	printf("%f\n", minirt.light.intensity);
	printf("==========================\n");
	printf("==========object count==========\n");
	printf("COUNT OBJT : (%d)\n", minirt.obj_count);
	printf("=============================\n");
	printf("=========SPHER===========\n");
	obj = (t_object*)minirt.object->content;
	t_sphere *sp = (t_sphere*)obj->object;
	vec_print(sp->center);
	printf("%f\n", sp->radius);
	color_print(sp->color);
	printf("==========================\n");
	printf("=========PLANE===========\n");
	obj = (t_object*)minirt.object->next->content;
	t_plane *pl = (t_plane*)obj->object;
	vec_print(pl->normal);
	vec_print(pl->point);
	color_print(pl->color);
	printf("==========================\n");
	printf("=========CYLANDER===========\n");
	obj = (t_object*)minirt.object->next->next->content;
	t_cylinder *cy = (t_cylinder*)obj->object;
	vec_print(cy->normal);
	vec_print(cy->point);
	color_print(cy->color);
	printf("%f\n", cy->radius);
	printf("%f\n", cy->len);
	printf("==========================\n");
}