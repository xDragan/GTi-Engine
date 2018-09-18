#ifndef __MODULEIMGUI__
#define __MODULEIMGUI__

#include "Module.h"

#pragma comment( lib, "Glew/libx86/glew32.lib" )

class ModuleImGui : public Module
{
public:

	ModuleImGui(Application* app, bool start_enabled = true);
	~ModuleImGui();

	bool Init();
	bool CleanUp();

	update_status PreUpdate(float dt) override;
	update_status Update(float dt) override;

	bool demo = false;
};


#endif // __MODULE_IMGUI__			