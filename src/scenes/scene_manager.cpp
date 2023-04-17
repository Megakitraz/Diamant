#include "scenes/scene_manager.h"
#include <assert.h>
#include <iostream>

void scene_manager::add_scene(std::string const& name, std::unique_ptr<scene> scene, bool active)
{
    const bool scene_exists = scenes.count(name);
    assert( !scene_exists && "Scene already exists" );
    scenes.insert(std::make_pair(name, std::move(scene)));
    if (active)
        switch_to(name);
}

void scene_manager::switch_to(std::string const& name)
{
    auto it = scenes.find(name);
    const bool scene_exists = it != scenes.end();
    assert( scene_exists && "Scene not found" );
    current_scene = it->second.get();
    current_scene->activate();
}

scene& scene_manager::get_current_scene() const
{
    const bool active_scene = current_scene != nullptr;
    assert( active_scene && "No active scene");
    return *current_scene;
}