/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:57:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 19:17:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*static const GLfloat g_vertex_buffer_data[] = {
	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, // triangle 1 : end
	1.0f, 1.0f,-1.0f, // triangle 2 : begin
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f, // triangle 2 : end
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
};*/

static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
	      1.0f, -1.0f, 0.0f,
	         0.0f,  1.0f, 0.0f,
};
/*
static const GLfloat g_color_buffer_data[] = {
	0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f,
	0.055f,  0.953f,  0.042f,
	0.714f,  0.505f,  0.345f,
	0.783f,  0.290f,  0.734f,
	0.722f,  0.645f,  0.174f,
	0.302f,  0.455f,  0.848f,
	0.225f,  0.587f,  0.040f,
	0.517f,  0.713f,  0.338f,
	0.053f,  0.959f,  0.120f,
	0.393f,  0.621f,  0.362f,
	0.673f,  0.211f,  0.457f,
	0.820f,  0.883f,  0.371f,
	0.982f,  0.099f,  0.879f
};*/

t_matrix	*get_rotation_matrix()
{
	t_matrix	*rx;
	t_matrix	*ry;
	t_matrix	*rz;

	if (!(rx = matrix_create_rotate_x(0)))
		ERROR("failed to create rotate x matrix");
	if (!(ry = matrix_create_rotate_y(1)))
		ERROR("failed to create rotate y matrix");
	if (!(rz = matrix_create_rotate_z(0)))
		ERROR("failed to create rotate z matrix");
	matrix_mult(rx, ry);
	matrix_mult(rx, rz);
	free(ry);
	free(rz);
	return (rx);
}

t_matrix	*get_final_matrix(t_env *env)
{
	t_matrix	*projection;
	t_matrix	*rotation;
	t_matrix	*position;
	t_matrix	*model;

	if (!(projection = matrix_create_projection(ft_toradians(45)
					, env->window_width / (double)env->window_height
					, 0.01, 100)))
		ERROR("failed to create projection matrix");
	if (!(rotation = get_rotation_matrix()))
		ERROR("failed to create rotation matrix");
	if (!(position = matrix_create_translation(4, 3, 3)))
		ERROR("failed to create translation matrix");
	if (!(model = matrix_create_identity()))
		ERROR("failed to creatre identity matrix");
	ft_putendl("projection");
	matrix_print(projection);
	ft_putendl("\nrotation");
	matrix_print(rotation);
	ft_putendl("\nposition");
	matrix_print(position);
	matrix_mult(projection, rotation);
	ft_putendl("\nprojection + rotation");
	matrix_print(projection);
	matrix_mult(projection, position);
	ft_putendl("\nprojection + rotation + position");
	matrix_print(projection);
	matrix_mult(projection, model);
	ft_putendl("free1");
	free(rotation);
	ft_putendl("free2");
	free(position);
	ft_putendl("free3");
	free(model);
	ft_putendl("free4");
	return (projection);
}

void		loop(t_env *env)
{
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	GLuint programID = shader_create("shader.vert", "shader.frag");
	GLuint MatrixID = glGetUniformLocation(programID, "ft_matrix");
	t_matrix *matrix;
	if (!(matrix = get_final_matrix(env)))
		ERROR("failed to get final matrix");
	matrix_print(matrix);
	while (!glfwWindowShouldClose(env->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &matrix->value[0][0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		glfwSwapBuffers(env->window);
		glfwPollEvents();
	}
}

int	main(int ac, char **av)
{
	t_env	env;

	if (!glfwInit())
		ERROR("glfwInit failed");
	ft_bzero(&env, sizeof(env));
	if (ac != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putstr(" <filename.obj>");
		return (EXIT_FAILURE);
	}
	//obj_load(&env, av[1]);
	window_init(&env);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	loop(&env);
	return (EXIT_SUCCESS);
}
