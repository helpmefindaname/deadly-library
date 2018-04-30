#pragma once
#include "../libimport/glm.h"
#include "../input/inputHandler.h"
#include <shared_mutex>

#include "../Geometry.h"
#include "../physics/PhysicsPipeline.h"

class Player {
public:
	Player(glm::vec3 position, float direction);
	~Player();

private:
	glm::vec3 position;
	float direction;
	std::shared_ptr<Geometry> sun; //SUN
	PxController* playerObject;
	float velocityY;
	
	float playerSpeed = 0.5f;
	float roatationSpeed = 0.1f;
	float jumpPower = 10.0f;
	float gravity = 9.81f;

public:
	void init(std::shared_ptr<TextureMaterial> playerMaterial, PhysicsPipeline& physiX);
	glm::vec3 getPosition();
	float getDirection();
	void update(InputHandler& inputHandler, float dt);
	void draw();

private:

	PxVec3 forward();
};
