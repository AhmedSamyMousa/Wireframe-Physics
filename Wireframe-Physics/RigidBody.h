#pragma once
#include "Include/eigen/Eigen/Dense"
#include <tbb/parallel_for.h>

using namespace Eigen;

enum class BodyType {
	Static,
	Dynamic,
	Kinemtic
};

class RigidBody{
public:
	BodyType type = BodyType::Dynamic;
	float	 mass = 1.0f;
	Vector3f position;
	Vector3f velocity;
	Vector3f forceAccumulator;
	float    colliderRadius = 1.0f;

	RigidBody(BodyType type, float mass, const Vector3f& pos);
};

