#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>
#include "glfw3.h"
#include "glm/glm.hpp"
using namespace glm;

int main(){
	if(!glfwInit()){
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	return 0;
}
