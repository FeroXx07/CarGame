#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 2000.0f
//#define TURN_DEGREES 15.0f * DEGTORAD
#define TURN_DEGREES 22.0f * DEGTORAD
#define BRAKE_POWER 200.0f
#define JUMP_POWER 140000.0f
class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

	void RestartCar();
public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float lastAcceleration;
	float brake;

	float rotationMatrix[9] = { 0.9271839f, 0.0000000f, 0.3746066f, 0.0000000f, 1.0000000f, 0.0000000f, -0.3746066f, 0.0000000f, 0.9271839f };
	float transRotationMatrix[9] = { 0.9271839f, 0.0000000f, -0.3746066f, 0.0000000f, 1.0000000f, 0.0000000f, 0.3746066f, 0.0000000f, 0.9271839f };

	float* returnMatrix;
};