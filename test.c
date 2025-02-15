// void p_c(t_color a)
// {
// 	fprintf(stderr, "[%d, %d, %d]\n", a.r, a.g, a.b);
// }
// void p_cs(t_vec3d a)
// {
// 	fprintf(stderr, "[%f, %f, %f]\n", a.x, a.y, a.z);
// }


// void p_c(t_color a)
// {
// 	fprintf(stderr, "[%d, %d, %d]\n", a.r, a.g, a.b);
// }
// void p_cs(t_vec3d a)
// {
// 	fprintf(stderr, "[%f, %f, %f]\n", a.x, a.y, a.z);
// }
// void print_object(t_object *obj)
// {
// 	t_pl		*plane;
// 	t_cy	*cy;
// 	t_sp	*sp;
	
// 	if (obj->type == SPHERE)
// 	{
// 		sp = (t_sp *)obj->object;
// 		fprintf(stderr,"\n\n[%f]",sp->radius);
// 		p_cs(sp->center);
// 		p_c(sp->color);
// 		fprintf(stderr,"============\n\n");
		
// 	}
// 	else if (obj->type == PLANE)
// 	{
// 		plane = (t_pl *)obj->object;
// 	}
// 	else if (obj->type == CYLINDER)
// 	{
// 		cy = (t_cy *)obj->object;
// 	}
// }