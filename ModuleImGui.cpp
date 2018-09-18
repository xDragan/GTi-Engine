#include "Globals.h"
#include "Application.h"
#include "ModuleImGui.h"
#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_sdl_gl3.h"
#include "Glew\include\glew.h"
#include "ModuleWindow.h"

#pragma comment( lib, "Glew/libx86/glew32.lib" )

ModuleImGui::ModuleImGui(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleImGui::~ModuleImGui()
{}

bool ModuleImGui::Start()
{
	LOG("Starting glew & ImGui");
	glewInit();
	ImGui_ImplSdlGL3_Init(App->window->GetWindowPtr());

	return true;
}

update_status ModuleImGui::PreUpdate(float dt)
{
	ImGui_ImplSdlGL3_NewFrame(App->window->GetWindowPtr());
	return(UPDATE_CONTINUE);
}

update_status ModuleImGui::Update(float dt)
{

	ImGui::Render();
	return UPDATE_CONTINUE;
}

bool ModuleImGui::CleanUp()
{
	LOG("Unloading Intro scene");
	ImGui_ImplSdlGL3_Shutdown();
	return true;
}
