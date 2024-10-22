#include <string>

class LoadShader {
	public:
		unsigned int getShaderProgram();
		int loadVertexShader();
		int loadFragmentShader();
		int loadShaderProgram();
		void readVertexShader(std::string filename);
		void readFragmentShader(std::string filename);
		void fragmentVertexShader();
	private:
		char infoLog[512];
		int success;
		unsigned int vertexShader;
		unsigned int fragmentShader;
		unsigned int shaderProgram;
		std::string vertexShaderSource;
		std::string fragmentShaderSource;
};
