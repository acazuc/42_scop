/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:00:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 14:08:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx_opengl.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
void	obj_read_mtllib_read_ni(t_obj *obj, char *line);
void	obj_read_mtllib_read_tr(t_obj *obj, char *line);
void	obj_read_mtllib_read_d(t_obj *obj, char *line);
void	obj_read_mtllib_read_newmtl(t_obj *obj, char *line);
char	*read_next_line(int fd, ssize_t *readed);
int		parse_valid_number(char *datas);
void	free_array(char **array);

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

struct							s_window
{
	void						*mlx_window;
	void						*mlx;
	char						*name;
	int							width;
	int							height;
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

struct							s_env
{
	t_window					window;
	t_camera					camera;
	t_obj						obj;
};

#endif
