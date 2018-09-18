#ifndef __MODULEIMGUI__
#define __MODULEIMGUI__

#include "Module.h"


class ModuleImGui : public Module
{
public:

	ModuleImGui(Application* app, bool start_enabled = true);
	~ModuleImGui();

	bool Init();
	bool CleanUp();

	update_status PreUpdate(float dt) override;
	update_status Update(float dt) override;
};


#endif // __MODULE_IMGUI__			