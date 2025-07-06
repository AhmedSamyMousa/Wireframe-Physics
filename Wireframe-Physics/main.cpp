#include <iostream>
#include "World.h"

int main() {
	World world;
	auto obj = world.AddRigidBody(BodyType::Dynamic, 5.0f, { 0.0f,1.0f,0.0f });
	auto obj1 = world.AddRigidBody(BodyType::Dynamic, 4.0f, { 8.0f,1.0f,0.0f });
	for (auto i = 0; i < world.bodies.size(); i++)
	{
		std::cout << "Object With ID : " << i << ", Mass : " << world.bodies[i]->mass <<
			", Position : (x)" << world.bodies[i]->position.x() << ", (y)" <<
			world.bodies[i]->position.y() << ", (z)" << world.bodies[i]->position.z() << std::endl;
	}
}