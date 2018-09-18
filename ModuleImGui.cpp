#include "Globals.h"
#include "Application.h"
#include "ModuleImGui.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_sdl_gl3.h"
#include "ModuleWindow.h"


ModuleImGui::ModuleImGui(Application * app, bool start_enabled): Module (app, start_enabled)
{
}

ModuleImGui::~ModuleImGui()
{
}

bool ModuleImGui::Init()
{
	LOG("ImGui version used: %s", ImGui::GetVersion());

	ImGui_ImplSdlGL3_Init(App->window->GetWindow());
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = "Game/imgui.ini";

	return true;
}



update_status ModuleImGui::PreUpdate(float dt)
{
	return UPDATE_CONTINUE;
}

update_status ModuleImGui::Update(float dt)
{
	return UPDATE_CONTINUE;
}

bool ModuleImGui::CleanUp()
{
	ImGui_ImplSdlGL3_Shutdown();
	return true;
}