class LoadShader {
	const char *vertexShaderSource = "#version 460 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char *fragmentShaderSource = "#version 460 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	public:
		int loadVertexShader();
		int loadFragmentShader();
		int loadShaderProgram();
		unsigned int getShaderProgram();
	private:
		char infoLog[512];
		int success;
		unsigned int vertexShader;
		unsigned int fragmentShader;
		unsigned int shaderProgram;
};
