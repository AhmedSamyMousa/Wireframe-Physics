#include "RigidBody.h"

RigidBody::RigidBody(BodyType type, float mass, const Vector3f& pos)
: type(type), mass(mass), position(pos) {}
