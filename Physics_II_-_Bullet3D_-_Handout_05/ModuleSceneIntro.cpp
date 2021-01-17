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
	ramp->body->SetPos(0, 2, 80);
	ramp->color.Set(100, 100, 0, 0);
	primitives.add(ramp);

	Cube * platform1 = new Cube(15, 2, 40);
	App->physics->AddBody(*platform1, 0)->SetPos(0, 15, 140);
	platform1->color.Set(0, 100, 255, 0);
	primitives.add(platform1);

	Cube* wall1 = new Cube(15, 15, 2);
	App->physics->AddBody(*wall1, 0)->SetPos(0, 23, 160);
	wall1->color.Set(0, 0, 255, 0);
	primitives.add(wall1);

	Cube* platform2 = new Cube(30, 2, 15);
	App->physics->AddBody(*platform2, 0)->SetPos(-22.5f, 15, 152.5f);
	platform2->color.Set(0, 100, 255, 0);
	primitives.add(platform2);

	Cube* ramp2 = new Cube(15, 0.1f, 15);
	ramp2->SetRotation(-25, { 0.0f,0.0f,1.0f });
	App->physics->AddBody(*ramp2, 0);
	ramp2->body->SetPos(-44.0f, 19, 152.5f);
	ramp2->color.Set(0, 0, 255, 0);
	primitives.add(ramp2);

	Cube* platform3 = new Cube(30, 2, 25);
	App->physics->AddBody(*platform3, 0)->SetPos(-90.0f, 25, 152.5f);
	platform3->color.Set(0, 100, 255, 0);
	primitives.add(platform3);

	Cube* wheelLineLeft = new Cube(1.5f, 2, 50);
	App->physics->AddBody(*wheelLineLeft, 0)->SetPos(-90.0f, 25, 190.0f);
	wheelLineLeft->color.Set(100, 100, 0, 0);
	primitives.add(wheelLineLeft);

	Cube* wheelLineRight = new Cube(1.5f, 2, 50);
	App->physics->AddBody(*wheelLineRight, 0)->SetPos(-93.8f, 25, 190.0f);
	wheelLineRight->color.Set(100, 100, 0, 0);
	primitives.add(wheelLineRight);

	Cube* platform4 = new Cube(30, 2, 25);
	App->physics->AddBody(*platform4, 0)->SetPos(-90.0f, 25, 228.0f);
	platform4->color.Set(0, 100, 255, 0);
	primitives.add(platform4);

	Cube* wall2 = new Cube(2, 40, 30);
	App->physics->AddBody(*wall2, 0)->SetPos(-49, 50, 270);
	wall2->color.Set(0, 0, 255, 0);
	primitives.add(wall2);

	Cube* wall3 = new Cube(2, 40, 30);
	App->physics->AddBody(*wall3, 0)->SetPos(-126, 50, 270);
	wall3->color.Set(0, 0, 255, 0);
	primitives.add(wall3);

	Cube* platform5 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform5, 0)->SetPos(-65, 30, 270);
	platform5->color.Set(0, 100, 255, 0);
	primitives.add(platform5);

	Cube* platform6 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform6, 0)->SetPos(-110, 37, 270);
	platform6->color.Set(0, 100, 255, 0);
	primitives.add(platform6);

	Cube* platform7 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform7, 0)->SetPos(-65, 44, 270);
	platform7->color.Set(0, 100, 255, 0);
	primitives.add(platform7);

	Cube* platform8 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform8, 0)->SetPos(-110, 51, 270);
	platform8->color.Set(0, 100, 255, 0);
	primitives.add(platform8);

	Cube* platform9 = new Cube(30, 2, 30);
	App->physics->AddBody(*platform9, 0)->SetPos(-65, 58, 270);
	platform9->color.Set(0, 100, 255, 0);
	primitives.add(platform9);

	Cube* ramp3 = new Cube(32, 0.1f, 30);
	ramp3->SetRotation(21, { 0.0f,0.0f,1.0f });
	App->physics->AddBody(*ramp3, 0);
	ramp3->body->SetPos(-65, 64, 270);
	ramp3->color.Set(0, 0, 255, 0);
	primitives.add(ramp3);

	Cube* platform10 = new Cube(50, 2, 100);
	App->physics->AddBody(*platform10, 0)->SetPos(-5, 72, 310);
	platform10->color.Set(0, 100, 255, 0);
	primitives.add(platform10);

	finalSensor = new Cube(50, 2, 20);
	App->physics->AddBody(*finalSensor, 0)->SetPos(-5, 73, 350);
	finalSensor->body->SetAsSensor(true);
	finalSensor->color.Set(255, 0, 0, 0.2f);
	primitives.add(finalSensor);

	deathSensor = new Cube(300, 1, 200);
	App->physics->AddBody(*deathSensor, 0)->SetPos(0, 1, 200);
	deathSensor->body->SetAsSensor(true);
	deathSensor->color.Set(0, 0, 0, 0.2f);
	primitives.add(deathSensor);

	for (uint n = 0; n < primitives.count(); n++)
	{
		Primitive *current;
		primitives.at(n, current);
		current->body->collision_listeners.add(App->player);
	}
		
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

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		Sphere* s = new Sphere(1);
		s->SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
		float force = 30.0f;
		App->physics->AddBody(*s, 1.0f);
		primitives.add(s);
		s->body->Push(-(App->camera->Z.x * force), -(App->camera->Z.y * force), -(App->camera->Z.z * force));
	}

	for (uint n = 0; n < primitives.count(); n++)
	{
		Primitive* current;
		primitives.at(n, current);
		current->Update();
		current->Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body1->is_sensor || body2->is_sensor)
	{
		int a = 0;
	}
}

