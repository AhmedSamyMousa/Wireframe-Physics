#include "World.h"

std::shared_ptr<RigidBody> World::AddRigidBody(BodyType type, float mass, const Vector3f pos)
{
	auto body = std::make_shared<RigidBody>(type, mass, pos);
	bodies.push_back(body);
	return body;
}