#include <iostream>
#include <sstream>
#include <mutex>
#include "World.h"

int main() {
	World world;
	auto obj = world.AddRigidBody(BodyType::Dynamic, 5.0f, { 0.0f,1.0f,0.0f });
	auto obj1 = world.AddRigidBody(BodyType::Dynamic, 4.0f, { 8.0f,1.0f,0.0f });
	std::vector<std::string> BodiesLogLines(world.bodies.size());
	tbb::parallel_for(size_t(0), world.bodies.size(), size_t(1), [&](size_t i)
	{
			std::ostringstream ss;
			ss << "Object With ID : " << i <<
			", Mass : " << world.bodies[i]->mass <<
			", Position : (x)" << world.bodies[i]->position.x() 
			<< ", (y)" << world.bodies[i]->position.y() << 
			", (z)" << world.bodies[i]->position.z();
			BodiesLogLines[i] = ss.str();
	});
	for (const auto& line : BodiesLogLines) { std::cout << line << '\n'; }
}