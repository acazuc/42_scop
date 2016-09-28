/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:47:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/28 16:35:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		check_info_log_error(GLuint id)
{
	char	*message;
	GLint	result;
	int		info_log_length;

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info_log_length);
	if (info_log_length > 0)
	{
		if ((message = ft_strnew(info_log_length + 1)))
		{
			glGetProgramInfoLog(id, info_log_length, NULL, message);
			ft_putendl(message);
		}
		ERROR("shaders compilation failed");
	}
}

static GLuint	read_compile_shader(char *filename, GLuint shader)
{
	char	*file_value;

	if (!(file_value = read_file(filename)))
		ERROR("failed to read fragment file");
	glShaderSource(shader, 1, (const GLchar *const *)&file_value, NULL);
	glCompileShader(shader);
	check_info_log_error(shader);
	free(file_value);
	return (shader);
}

GLuint			shader_create(char *vertex, char *fragment)
{
	GLuint	vertex_shader;
	GLuint	fragment_shader;
	GLuint	program;
	
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	read_compile_shader(vertex, vertex_shader);
	read_compile_shader(fragment, fragment_shader);
	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	check_info_log_error(program);
	glDetachShader(program, vertex_shader);
	glDetachShader(program, fragment_shader);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return (program);
}
