#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "p2List.h"
#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

struct MovingBoxX
{
	MovingBoxX() {};
	Cube* cube = nullptr;

	bool goesRight = false;

	void Update();

	float velocity = 10.0f;
	float maxCounter = 0;
	float counter = maxCounter;
};

struct MovingBoxY
{
	MovingBoxY() {};
	Cube* cube = nullptr;

	bool goesDown = false;

	void Update();

	float velocity = 10.0f;
	float maxCounter = 0;
	float counter = maxCounter;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

	void CheckPointLogic();

public:
	Plane p = Plane(0, 1, 0, 0);

	Cube* checkPoint = nullptr;
	Cube* deathSensor = nullptr;
	Cube* impulseSensor = nullptr;
	Cube* winSensor = nullptr;

	bool hasCheckPoint = false;
	p2List<Primitive*> primitives;

	MovingBoxX movingBoxX[4];
	MovingBoxY movingBoxY[2];
};
