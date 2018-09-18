#include "Globals.h"
#include "Application.h"
#include "ModuleImGui.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_sdl_gl3.h"
#include "ModuleWindow.h"
#include "Glew\include\glew.h"

#pragma comment( lib, "Glew/libx86/glew32.lib" )

ModuleImGui::ModuleImGui(Application * app, bool start_enabled): Module (app, start_enabled)
{
}

ModuleImGui::~ModuleImGui()
{
}

bool ModuleImGui::Init()
{
	LOG("ImGui version used: %s", ImGui::GetVersion());
	glewInit();
	ImGui_ImplSdlGL3_Init(App->window->GetWindow());


	return true;
}



update_status ModuleImGui::PreUpdate(float dt)
{
	ImGui_ImplSdlGL3_NewFrame(App->window->GetWindow());
	return UPDATE_CONTINUE;
}

update_status ModuleImGui::Update(float dt)
{
	//ImGui::Begin("Hola Ricard");
	if (ImGui::Button("Open Demo", ImVec2(100, 30)))
	{
		demo = true;
	}
	if (ImGui::Button("Close Demo", ImVec2(100, 30)))
	{
		demo = false;
	}
	if (ImGui::Button("Close App", ImVec2(100, 30)))
	{
		return UPDATE_STOP;
	}
	if (demo)
	{
		ImGui::ShowTestWindow();
	}
	//ImGui::End();
	ImGui::Render();
	return UPDATE_CONTINUE;
}

bool ModuleImGui::CleanUp()
{
	ImGui_ImplSdlGL3_Shutdown();
	return true;
}