#pragma once
#include <vector>
#include <memory>
#include "RigidBody.h"

class World
{
public:
	std::vector<std::shared_ptr<RigidBody>> bodies;

	std::shared_ptr<RigidBody> AddRigidBody(BodyType type,float mass, const Vector3f pos);
	const std::vector<std::shared_ptr<RigidBody>>& GetBodies() const { return bodies; };
};
