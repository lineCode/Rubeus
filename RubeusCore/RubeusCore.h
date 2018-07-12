// RubeusCore.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

// TODO: Reference additional headers your program requires here.
#ifdef _DEBUG
#ifdef VLD
#include <vld.h>
#endif
#endif

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <rubeus_maths_library.h>

#include <loader_component.h>
#include <logger_component.h>
#include <window_component.h>
#include <shader_component.h>
#include <master_component.h>
#include <simple_renderer_component.h>
#include <guerrilla_renderer_component.h>
#include <renderable_object.h>
#include <sprite_object.h>
#include <static_sprite_object.h>
#include <timer_component.h>
#include <static_layer_object.h>
