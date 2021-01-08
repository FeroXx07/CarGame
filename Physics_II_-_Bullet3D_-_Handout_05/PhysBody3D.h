#ifndef __PhysBody3D_H__
#define __PhysBody3D_H__

#include "p2List.h"

class btRigidBody;
class Module;

class Sphere;
class Cube;
class Cylinder;
class Plane;

class Primitive;

// =================================================
struct PhysBody3D
{
	friend class ModulePhysics3D;
	friend class ModulePlayer;
	friend class ModuleSceneIntro;
public:
	PhysBody3D(btRigidBody* body);
	~PhysBody3D();

	void Push(float x, float y, float z);
	void GetTransform(float* matrix) const;
	void SetTransform(const float* matrix) const;
	void SetPos(float x, float y, float z);
	void PhysBody3D::SetAsSensor(bool is_sensor);
private:
	btRigidBody* body = nullptr;
	Primitive* parentPrimitive;
public:
	p2List<Module*> collision_listeners;
	bool is_sensor = false;
};

#endif // __PhysBody3D_H__