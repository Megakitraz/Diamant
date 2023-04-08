#include "scene/scene_manager.h"
#include <assert.h>
#include <iostream>

void scene_manager::add_scene(std::string const& name, std::unique_ptr<scene> scene, bool active)
{
    const bool scene_exists = scenes.count(name);
    assert( !scene_exists && "Scene already exists" );
    scenes.insert(std::make_pair(name, std::move(scene)));
    if (active)
    {
        current_scene = std::move(scene);
    }
}

void scene_manager::switch_to(std::string const& name)
{
    const bool scene_exists = scenes.count(name);
    assert( scene_exists && "Scene not found" );
    current_scene = std::move(scenes.at(name));
}

scene& scene_manager::get_current_scene() const
{
    const bool active_scene = current_scene != nullptr;
    assert( active_scene && "No active scene");
    return *current_scene;
}