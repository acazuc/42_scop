/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:00:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 19:15:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../libft/include/libft.h"
# include <GLFW/glfw3.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

typedef struct s_obj_vertex			t_obj_vertex;
typedef struct s_obj_vertex_list	t_obj_vertex_list;
typedef struct s_obj_face			t_obj_face;
typedef struct s_obj_face_list		t_obj_face_list;
typedef struct s_obj_mtl			t_obj_mtl;
typedef struct s_obj_mtl_list		t_obj_mtl_list;
typedef struct s_obj				t_obj;
typedef struct s_window				t_window;
typedef struct s_camera				t_camera;
typedef struct s_env				t_env;
typedef struct s_matrix				t_matrix;

void	error_quit(char *error, char *file, int line);
void	window_init(t_env *env);
void	obj_load(t_env *env, char *file);
void	obj_read(t_obj *obj, int fd);
void	obj_read_face(t_obj *obj, char *line);
void	obj_read_vertex(t_obj *obj, char *line);
void	obj_read_smooth(t_obj *obj, char *line);
void	obj_read_usemtl(t_obj *obj, char *line);
void	obj_read_mtllib(t_obj *obj, char *line);
void	obj_read_mtllib_read(t_obj *obj, int fd);
void	obj_read_mtllib_read_ka(t_obj *obj, char *line);
void	obj_read_mtllib_read_kd(t_obj *obj, char *line);
void	obj_read_mtllib_read_ks(t_obj *obj, char *line);
void	obj_read_mtllib_read_ns(t_obj *obj, char *line);
void	obj_read_mtllib_read_ni(t_obj *obj, char *line);
void	obj_read_mtllib_read_tr(t_obj *obj, char *line);
void	obj_read_mtllib_read_d(t_obj *obj, char *line);
void	obj_read_mtllib_read_illum(t_obj *obj, char *line);
void	obj_read_mtllib_read_newmtl(t_obj *obj, char *line);
char	*read_next_line(int fd, ssize_t *readed);
int		parse_valid_number(char *datas);
void	free_array(char **array);
char	*read_file(char *file);
GLuint	shader_create(char *vertex, char *fragment);
t_matrix	*matrix_create();
t_matrix	*matrix_create_identity();
t_matrix	*matrix_create_translation(double x, double y, double z);
t_matrix	*matrix_create_scale(double scale);
t_matrix	*matrix_create_rotate_x(double angle);
t_matrix	*matrix_create_rotate_y(double angle);
t_matrix	*matrix_create_rotate_z(double angle);
t_matrix	*matrix_create_projection(double fov, double ratio, double near, double far);
void		matrix_mult(t_matrix *m1, t_matrix *m2);
void		matrix_print(t_matrix *matrix);

struct							s_obj_vertex
{
	double						x;
	double						y;
	double						z;
};

struct							s_obj_vertex_list
{
	t_obj_vertex					vertex;
	t_obj_vertex_list			*next;
};

struct							s_obj_face
{
	char						*mtl;
	int							is_quad;
	int							v1;
	int							v2;
	int							v3;
	int							v4;
};

struct							s_obj_face_list
{
	t_obj_face					face;
	t_obj_face_list				*next;
};

struct							s_obj_mtl
{
	char						*name;
	float						kar;
	float						kag;
	float						kab;
	float						kdr;
	float						kdg;
	float						kdb;
	float						ksr;
	float						ksg;
	float						ksb;
	float						ns;
	float						ni;
	float						tr;
	int							illum;
};

struct							s_obj_mtl_list
{
	t_obj_mtl					mtl;
	t_obj_mtl_list				*next;
};

struct							s_obj
{
	char						*file;
	t_obj_vertex_list			*vertexes;
	t_obj_face_list				*faces;
	t_obj_mtl_list				*mtls;
	t_obj_mtl_list				*current_mtl;
	char						*used_mtl;
	int							smooth;
};

struct							s_camera
{
	float						px;
	float						py;
	float						pz;
	float						rx;
	float						ry;
	float						rz;
};

struct							s_matrix
{
	float						**value;
};

struct							s_env
{
	GLFWwindow					*window;
	int							window_width;
	int							window_height;
	t_camera					camera;
	t_obj						obj;
	GLuint						vertexbuffer;
};

#endif
