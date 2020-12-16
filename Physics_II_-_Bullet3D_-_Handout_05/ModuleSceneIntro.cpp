#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// Z LEFT RIGHT  // X FORWARD REAR
	Cube* leftStart = new Cube(5, 2, 50);
	App->physics->AddBody(*leftStart, 10000)->SetPos(5, 0, 20);
	primitives.PushBack(leftStart);

	Cube *rightStart = new Cube(5, 2, 50);
	App->physics->AddBody(*rightStart, 10000)->SetPos(-5, 0, 20);
	primitives.PushBack(rightStart);

	Cube * rightObstacle = new Cube(10, 2, 10);
	App->physics->AddBody(*rightObstacle, 10000)->SetPos(-5, 0, 80);
	primitives.PushBack(rightObstacle);

	Cube * lefObstacle = new Cube(10, 2, 10);
	App->physics->AddBody(*lefObstacle, 10000)->SetPos(5, 0, 110);
	primitives.PushBack(lefObstacle);

	Cube* jumpObstacle = new Cube(50, 5, 10);
	App->physics->AddBody(*jumpObstacle, 10000)->SetPos(0, 0, 150);
	primitives.PushBack(jumpObstacle);

	jumpObstacle = new Cube(50, 5, 10);
	App->physics->AddBody(*jumpObstacle, 10000)->SetPos(0, 0, 160);
	primitives.PushBack(jumpObstacle);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	for (uint n = 0; n < primitives.Count(); n++)
		primitives[n]->Update();

	for (uint n = 0; n < primitives.Count(); n++)
		primitives[n]->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

