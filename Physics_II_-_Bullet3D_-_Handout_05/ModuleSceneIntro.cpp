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
	/*Cube* leftStart = new Cube(5, 2, 50);
	App->physics->AddBody(*leftStart, 10000)->SetPos(5, 0, 20);
	primitives.PushBack(leftStart);

	Cube *rightStart = new Cube(5, 2, 50);
	App->physics->AddBody(*rightStart, 10000)->SetPos(-5, 0, 20);
	primitives.PushBack(rightStart);*/

	Cube * ramp = new Cube(15, 0.1f, 15);
	ramp->SetRotation(-25, { 1.0f,0.0f,0.0f });
	App->physics->AddBody(*ramp, 0);
	ramp->body.SetPos(0, 2, 80);
	primitives.PushBack(ramp);

	Cube * platform1 = new Cube(15, 2, 40);
	App->physics->AddBody(*platform1, 0)->SetPos(0, 15, 140);
	primitives.PushBack(platform1);

	Cube* wall1 = new Cube(15, 15, 2);
	App->physics->AddBody(*wall1, 0)->SetPos(0, 23, 162);
	primitives.PushBack(wall1);

	Cube* platform2 = new Cube(30, 2, 15);
	App->physics->AddBody(*platform2, 0)->SetPos(-22.5f, 15, 152.5f);
	primitives.PushBack(platform2);

	Cube* ramp2 = new Cube(15, 0.1f, 15);
	ramp2->SetRotation(-25, { 0.0f,0.0f,1.0f });
	App->physics->AddBody(*ramp2, 0);
	ramp2->body.SetPos(-44.0f, 19, 152.5f);
	primitives.PushBack(ramp2);

	Cube* platform3 = new Cube(30, 2, 25);
	App->physics->AddBody(*platform3, 0)->SetPos(-90.0f, 25, 152.5f);
	primitives.PushBack(platform3);

	Cube* wheelLineLeft = new Cube(1.5f, 2, 50);
	App->physics->AddBody(*wheelLineLeft, 0)->SetPos(-90.0f, 25, 190.0f);
	primitives.PushBack(wheelLineLeft);

	Cube* wheelLineRight = new Cube(1.5f, 2, 50);
	App->physics->AddBody(*wheelLineRight, 0)->SetPos(-93.8f, 25, 190.0f);
	primitives.PushBack(wheelLineRight);

	Cube* platform4 = new Cube(30, 2, 25);
	App->physics->AddBody(*platform4, 0)->SetPos(-90.0f, 25, 228.0f);
	primitives.PushBack(platform4);

	Cube* wall2 = new Cube(2, 40, 30);
	App->physics->AddBody(*wall2, 0)->SetPos(-49, 50, 270);
	primitives.PushBack(wall2);

	Cube* wall3 = new Cube(2, 40, 30);
	App->physics->AddBody(*wall3, 0)->SetPos(-126, 50, 270);
	primitives.PushBack(wall3);

	Cube* platform5 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform5, 0)->SetPos(-65, 30, 270);
	primitives.PushBack(platform5);

	Cube* platform6 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform6, 0)->SetPos(-110, 37, 270);
	primitives.PushBack(platform6);

	Cube* platform7 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform7, 0)->SetPos(-65, 44, 270);
	primitives.PushBack(platform7);

	Cube* platform8 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform8, 0)->SetPos(-110, 51, 270);
	primitives.PushBack(platform8);

	Cube* platform9 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform9, 0)->SetPos(-65, 58, 270);
	primitives.PushBack(platform9);

	Cube* ramp3 = new Cube(32, 0.1f, 30);
	ramp3->SetRotation(21, { 0.0f,0.0f,1.0f });
	App->physics->AddBody(*ramp3, 0);
	ramp3->body.SetPos(-65, 64, 270);
	primitives.PushBack(ramp3);

	Cube* platform10 = new Cube(30, 2, 100);
	App->physics->AddBody(*platform10, 0)->SetPos(-20, 72, 310);
	primitives.PushBack(platform10);

	Cube* platform11 = new Cube(30, 2, 100);
	App->physics->AddBody(*platform11, 0)->SetPos(-20, 73, 310);
	primitives.PushBack(platform11);

	/*Cube* wall1 = new Cube(15, 15, 1);
	App->physics->AddBody(*wall1, 100000)->SetPos(0, 5, 115);
	wall1->body.body->setGravity({ 0,0,0 });
	primitives.PushBack(wall1);*/

	/*Cube* jumpObstacle = new Cube(50, 5, 10);
	App->physics->AddBody(*jumpObstacle, 10000)->SetPos(0, 0, 150);
	primitives.PushBack(jumpObstacle);

	jumpObstacle = new Cube(50, 5, 10);
	App->physics->AddBody(*jumpObstacle, 10000)->SetPos(0, 0, 160);
	primitives.PushBack(jumpObstacle);*/

	
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
	//Plane p(0, 1, 0, 0);
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
	if (body1->is_sensor || body2->is_sensor)
	{
		int a = 0;
	}
}

