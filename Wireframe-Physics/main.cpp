#include <iostream>
#include <sstream>
#include <mutex>
#include <chrono>
#include "World.h"
// MultiThreading 7856.94 ms 
// Normal         58722.1 ms
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    World world;
    std::mutex add_mutex;

    tbb::parallel_for(tbb::blocked_range<size_t>(0, 100001), [&](const tbb::blocked_range<size_t>& range)
        {
            for (size_t i = range.begin(); i != range.end(); ++i) {
                float x = static_cast<float>(i % 100);
                float y = 1.0f;
                float z = static_cast<float>(i / 100);
                float mass = 1.0f + (i % 10);

                std::lock_guard<std::mutex> lock(add_mutex);
                world.AddRigidBody(BodyType::Dynamic, mass, { x, y, z });
            }
        }
    );
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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution Time: " << duration.count() << " ms\n ";
}