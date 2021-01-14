#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "ModuleSceneIntro.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	//car.chassis_size.Set(2, 2, 4);
	car.chassis_size.Set(4.5f, 1.75f, 6.5f);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 500.0f;
	//car.suspensionStiffness = 5.88f;
	car.suspensionStiffness = 8.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm =300.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	//float connection_height = 1.2f;
	//float wheel_radius = 0.6f;
	//float wheel_width = 0.5f;
	//float suspensionRestLength = 1.2f;

	float connection_height = 1.0f;
    float wheel_radius = 0.8f;
    float wheel_width = 1.3f;
    float suspensionRestLength = 1.5f;

	// Don't change anything below this line ------------------

	/*float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;*/

	float half_width = car.chassis_size.x * 0.5f;
	float half_length = car.chassis_size.z * 0.6f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];
	
	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;
	
	vehicle = App->physics->AddVehicle(car);
	
	vehicle->SetPos(0, 12,10);
	vehicle->collision_listeners.add(this);
	
	returnMatrix = new float[16];
	vehicle->GetTransform(returnMatrix);
	initialRot = vehicle->vehicle->getChassisWorldTransform().getBasis();
	/*vec3 positionToLook; 
	positionToLook.x = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().x();
	positionToLook.y = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().y();
	positionToLook.z = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().z();

	positionToLook.y += 2;
	positionToLook.z += 12;

	vec3 positionToFollow = positionToLook;
	positionToFollow.z -= 25;
	positionToFollow.y += 10;
		
	App->camera->Look(positionToFollow, positionToLook, true);*/
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

void ModulePlayer::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body1 == vehicle)
	{
		// It is player
		if (body2 == App->physics->ground)
		{
			LOG("GROUND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}

		// It is a platform, wall, etc..
 		for (uint n = 0; n < App->scene_intro->primitives.Count(); n++)
		{
			if (body2 == &App->scene_intro->primitives[n]->body)
			{
				LOG("Plat!!!!!!");
			}
		}
	}
}

void ModulePlayer::RestartCar()
{

}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		vehicle->vehicle->getRigidBody()->clearForces();
		vehicle->SetTransform(returnMatrix);
		vehicle->SetPos(-20, 72, 310);
		vehicle->ApplyEngineForce(0);
	}

	if (App->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)
	{
		vehicle->vehicle->getRigidBody()->clearForces();
		vehicle->SetTransform(returnMatrix);
		vehicle->SetPos(0, 0, 10);
	}

	vec3 positionToLook; 
	positionToLook.x = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().x();
	positionToLook.y = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().y();
	positionToLook.z = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().z();

	if (App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT)
	{
		positionToLook.z += -10;
		positionToLook.y += 10;
	}
	else
	{
		positionToLook.y += 2;
		positionToLook.z += 8;
	}

	vec3 positionToFollow = positionToLook;
	positionToFollow.z -= 25;
	positionToFollow.y += 10;
		
	App->camera->Look(positionToFollow, positionToLook, true);

	//vec3 positionToFollow;
	//positionToFollow.x = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().x();
	//positionToFollow.y = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().y();
	//positionToFollow.z = vehicle->vehicle->getRigidBody()->getWorldTransform().getOrigin().z();

	///*positionToLook.y += 2;
	//positionToLook.z += 12;

	//vec3 positionToFollow = positionToLook;
	//positionToFollow.z -= 25;
	//positionToFollow.y += 10;*/

	//App->camera->CalculateViewMatrix();

	//App->camera->LookAt(positionToFollow);
	
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
	}

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		//App->camera->ModifyViewMatrix(rotationMatrix); //Hacer rotMatrix segun turn
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		//App->camera->ModifyViewMatrix(transRotationMatrix); //Hacer rotMatrix segun turn
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT && vehicle->GetKmh() > 0)
	{
		brake = BRAKE_POWER;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		if (vehicle->GetKmh() > 0)
			//vehicle->ApplyEngineForce(vehicle->GetKmh() * -MAX_ACCELERATION*100000000.0f);
		vehicle->Jump(JUMP_POWER);
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}



