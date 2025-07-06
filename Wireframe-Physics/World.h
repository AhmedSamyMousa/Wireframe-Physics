#pragma once
#include <vector>
#include <memory>
#include "RigidBody.h"

class World
{
public:
	tbb::concurrent_vector<std::shared_ptr<RigidBody>> bodies;

	std::shared_ptr<RigidBody> AddRigidBody(BodyType type,float mass, const Vector3f pos);
	const tbb::concurrent_vector<std::shared_ptr<RigidBody>>& GetBodies() const { return bodies; };
};
