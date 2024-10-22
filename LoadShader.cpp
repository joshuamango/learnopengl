#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LoadShader.h"

using namespace std;

int LoadShader::loadVertexShader()
{
	const char* shaderSource = vertexShaderSource.c_str();
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &shaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
			infoLog << std::endl;
	}
	return success;
}

int LoadShader::loadFragmentShader()
{
	const char* shaderSource = fragmentShaderSource.c_str();
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &shaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
			infoLog << std::endl;
	}
	return success;
}

int LoadShader::loadShaderProgram()
{
	if (!LoadShader::loadVertexShader() || !LoadShader::loadFragmentShader())
	{
		return -1;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" <<
			infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	std::cout << "Loaded shader program" << std::endl;
	return success;
}

unsigned int LoadShader::getShaderProgram()
{
	return shaderProgram;
}

void LoadShader::readVertexShader(string filename)
{
	fstream sourceFile(filename);
	stringstream sourceStream;
	sourceStream << sourceFile.rdbuf();
	vertexShaderSource = sourceStream.str();
}

void LoadShader::readFragmentShader(string filename)
{
	fstream sourceFile(filename);
	stringstream sourceStream;
	sourceStream << sourceFile.rdbuf();
	fragmentShaderSource = sourceStream.str();
}
