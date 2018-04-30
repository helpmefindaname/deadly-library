#pragma once
#include "..\libimport\glew.h"
#include "..\libimport\glfw.h"

#include "..\GameImport.h"
#include GAMESTATE_H

#include "..\physics\PhysicsPipeline.h"

#include "..\graphics\camera.h"
#include "..\input\inputHandler.h"
#include "..\input\debugCameraHandler.h"
//#include "..\input\GameCameraHandler.h" //IF

class Gameloop {
public:
	Gameloop(unsigned int fps);
	~Gameloop();

private:
	unsigned int fps;
	float sPerFrame;
	Glfw glfw;
	Window window;
	Glew glew;
	InputHandler inputHandler;
	bool isDebug;
	bool isWireframe;
	bool isCulling;
	Camera debugCamera;
	DebugCameraHandler debugCameraHandler;
	//Camera gameCamera; //IF
	//GameCameraHandler gameCameraHandler; //IF
	GAMESTATE state;
	PhysicsPipeline physixPipe;

public:
	void run();

private:
	void init();
	void update();
	void render();

	static void APIENTRY DebugCallbackDefault(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const GLvoid* userParam);
	static std::string FormatDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, const char* msg);
};