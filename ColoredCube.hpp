#ifndef COLOREDCUBE
#define COLOREDCUBE

#include <GL/glew.h>
#include <glm/glm.hpp>

class ColoredCube {
public:
	void animation_step();
	ColoredCube(GLfloat *g_vertex_buffer_data, int vertices_size, GLfloat *g_color_buffer_data, int colors_size);
	~ColoredCube();

private:
	GLuint VertexArrayID;
	GLuint MatrixID;
	GLuint programID;

	glm::mat4 Model;
	glm::mat4 View;
	glm::mat4 Projection;
	glm::mat4 MVP;

	GLuint vertexbuffer;
	GLuint colorbuffer;
};

#endif