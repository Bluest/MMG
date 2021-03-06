// <MMG.h> should be included first
#include <MMG.h>

#include <iostream>

#include "Cat.h"
#include "Musician.h"
#include "CameraController.h"

void load(ResourceManager& _resources)
{
	_resources.load<Model>("CuruthersObj", "../assets/curuthers.obj");
	_resources.load<Model>("IvysaurModel", "../assets/ivysaur.obj");
	_resources.load<Material>("CuruthersMat", "../assets/Whiskers_diffuse.png");
	_resources.load<Material>("IvysaurMaterial", "../assets/ivysaur_diffuse.jpg");
	_resources.load<Sound>("TheHorn", "../assets/dixie_horn.ogg");
	_resources.load<Sound>("Tune", "../assets/Tune.ogg");
}

int main(int argc, char* argv[])
{
	std::shared_ptr<Core> core = Core::init("MMG Demo", 640, 480);
	ResourceManager resources(core);

	load(resources);

	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<CameraController>();

	std::shared_ptr<Entity> curuthers = core->addEntity();
	curuthers->addComponent<Cat>();
	curuthers->addComponent<MeshRenderer>(
		resources.use<Model>("CuruthersObj"),
		resources.use<Material>("CuruthersMat"));

	std::shared_ptr<SoundSource> voice = curuthers->addComponent<SoundSource>();
	voice->addSound(resources.use<Sound>("TheHorn"));

	std::shared_ptr<Entity> buddy = core->addEntity();
	buddy->addComponent<Musician>();
	buddy->addComponent<MeshRenderer>(
		resources.use<Model>("IvysaurModel"),
		resources.use<Material>("IvysaurMaterial"));

	std::shared_ptr<SoundSource> music = buddy->addComponent<SoundSource>();
	music->addSound(resources.use<Sound>("Tune"));

	std::cout << std::endl << "Hi! Use WASD to move around, Q to go down and E and go up." << std::endl;
	std::cout << "Left clicking will play the horn." << std::endl;
	std::cout << "Middle clicking will instead play the horb." << std::endl << std::endl;
	core->run();
	
	return 0;
}
