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

	checkPoint = new Cube(50, 1, 5);
	App->physics->AddBody(*checkPoint, 0)->SetPos(-5, 73, 320);
	checkPoint->body->SetAsSensor(true);
	checkPoint->color.Set(255, 0, 0, 0.2f);
	primitives.add(checkPoint);

	deathSensor = new Cube(300, 1, 600);
	App->physics->AddBody(*deathSensor, 0)->SetPos(0, 0, 400);
	deathSensor->body->SetAsSensor(true);
	deathSensor->color.Set(0, 0, 0, 0.2f);
	primitives.add(deathSensor);

	Cube* ground = new Cube(300, 1, 200);
	App->physics->AddBody(*ground, 0)->SetPos(0, -1, 0);
	ground->body->SetAsSensor(true);
	ground->color.Set(255, 255, 255, 0.2f);
	primitives.add(ground);

	Cube* behindWall = new Cube(300, 500, 1);
	App->physics->AddBody(*behindWall, 0)->SetPos(0, 0, -30);
	behindWall->color.Set(255, 255, 0, 0.2f);
	primitives.add(behindWall);

	Cube* leftWall = new Cube(1, 500, 600);
	App->physics->AddBody(*leftWall, 0)->SetPos(150, 0, 270);
	leftWall->color.Set(255, 255, 0, 0.2f);
	primitives.add(leftWall);

	Cube* rightWall = new Cube(1, 500, 600);
	App->physics->AddBody(*rightWall, 0)->SetPos(-150, 0, 270);
	rightWall->color.Set(255, 255, 0, 0.2f);
	primitives.add(rightWall);


	// SECOND PART OF THE CIRCUIT
	Cube* corridor = new Cube(10, 2, 200);
	App->physics->AddBody(*corridor, 0)->SetPos(-5, 77, 470);
	corridor->color.Set(0, 100, 255, 0);
	primitives.add(corridor);

	for (uint n = 0; n < primitives.count(); n++)
	{
		Primitive *current;
		primitives.at(n, current);
		current->body->collision_listeners.add(App->player);
	}

	hasCheckPoint = false;

	movingBoxX[0].cube = new Cube(8, 10, 5);
	App->physics->AddBody(*movingBoxX[0].cube, 10000000.0)->SetPos(-3, 85, 400);
	movingBoxX[0].cube->body->body->setGravity({ 0,0,0 });
	movingBoxX[0].cube->color.Set(255, 0, 0, 0);
	movingBoxX[0].maxCounter = 1.0f;
	primitives.add(movingBoxX[0].cube);

	movingBoxX[1].cube = new Cube(8, 10, 5);
	App->physics->AddBody(*movingBoxX[1].cube, 10000000.0)->SetPos(-7, 85, 430);
	movingBoxX[1].cube->body->body->setGravity({ 0,0,0 });
	movingBoxX[1].cube->color.Set(255, 0, 0, 0);
	movingBoxX[1].maxCounter = 1.0f;
	movingBoxX[1].goesRight = true;
	primitives.add(movingBoxX[1].cube);

	movingBoxX[2].cube = new Cube(8, 10, 5);
	App->physics->AddBody(*movingBoxX[2].cube, 10000000.0)->SetPos(-3, 85, 460);
	movingBoxX[2].cube->body->body->setGravity({ 0,0,0 });
	movingBoxX[2].cube->color.Set(255, 0, 0, 0);
	movingBoxX[2].maxCounter = 1.0f;
	movingBoxX[2].goesRight = false;
	primitives.add(movingBoxX[2].cube);

	movingBoxX[3].cube = new Cube(8, 10, 5);
	App->physics->AddBody(*movingBoxX[3].cube, 10000000.0)->SetPos(-7, 85, 490);
	movingBoxX[3].cube->body->body->setGravity({ 0,0,0 });
	movingBoxX[3].cube->color.Set(255, 0, 0, 0);
	movingBoxX[3].maxCounter = 1.0f;
	movingBoxX[3].goesRight = true;
	primitives.add(movingBoxX[3].cube);

	movingBoxY[0].cube = new Cube(15, 2, 20);
	App->physics->AddBody(*movingBoxY[0].cube, 10000000.0)->SetPos(-5, 83, 600);
	movingBoxY[0].cube->body->body->setGravity({ 0,0,0 });
	movingBoxY[0].cube->color.Set(0, 100, 255, 0);
	movingBoxY[0].maxCounter = 2.0f;
	movingBoxY[0].velocity = 8.0f;
	movingBoxY[0].goesDown = true;
	primitives.add(movingBoxY[0].cube);

	movingBoxY[1].cube = new Cube(15, 2, 20);
	App->physics->AddBody(*movingBoxY[1].cube, 10000000.0)->SetPos(-5, 75, 625);
	movingBoxY[1].cube->body->body->setGravity({ 0,0,0 });
	movingBoxY[1].cube->color.Set(0, 100, 255, 0);
	movingBoxY[1].maxCounter = 2.0f;
	movingBoxY[1].velocity = 8.0f;
	movingBoxY[1].goesDown = false;
	primitives.add(movingBoxY[1].cube);

	Cube* finalPlatform = new Cube(50, 2, 100);
	App->physics->AddBody(*finalPlatform, 0)->SetPos(-5, 72, 700);
	finalPlatform->color.Set(0, 100, 255, 0);
	primitives.add(finalPlatform);

	impulseSensor = new Cube(50, 3, 5);
	App->physics->AddBody(*impulseSensor, 0)->SetPos(-5, 73, 740);
	impulseSensor->body->SetAsSensor(true);
	impulseSensor->color.Set(0, 255, 0, 0.2f);
	primitives.add(impulseSensor);

	winSensor = new Cube(50, 25, 5);
	App->physics->AddBody(*winSensor, 0)->SetPos(-5, 70, 900);
	winSensor->body->SetAsSensor(true);
	winSensor->color.Set(255, 0, 0, 0.2f);
	primitives.add(winSensor);

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
	p.color.Set(255, 255, 255, 0);

	for (int i = 0; i < 4; ++i)
		movingBoxX[i].Update();

	for (int i = 0; i < 2; ++i)
		movingBoxY[i].Update();

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

void ModuleSceneIntro::CheckPointLogic()
{
	if (hasCheckPoint)
	{
		App->player->RestartCheckPoint();
	}
	else
	{
		App->player->RestartLevel();
	}
}

void MovingBoxX::Update()
{
	counter += -1.0f / 60.f;

	if (counter <= 0.0f)
	{
		counter = maxCounter;

		goesRight = !goesRight;

		if (goesRight)
			cube->body->GetBody()->setLinearVelocity({ velocity, 0.0f, 0.0f });
		else
			cube->body->GetBody()->setLinearVelocity({ -velocity, 0.0f, 0.0f });
	}

	/*btVector3 pos = body->GetBody()->getWorldTransform().getOrigin();
	body->SetPos(pos.x() + 1.0f, pos.y(), pos.z());*/
}

void MovingBoxY::Update()
{
	counter += -1.0f / 60.f;

	if (counter <= 0.0f)
	{
		counter = maxCounter;

		goesDown = !goesDown;

		if (goesDown)
			cube->body->GetBody()->setLinearVelocity({ 0.0f, velocity, 0.0f });
		else
			cube->body->GetBody()->setLinearVelocity({ 0.0f, -velocity, 0.0f });
	}
}
