#pragma once

#include <utils/singleton.h>
#include "scene/scene.h"
#include <unordered_map>
#include <memory>
#include <string>

class scene_manager : public singleton<scene_manager>
{
    public:
        void add_scene(std::string const& name, std::unique_ptr<scene> scene, bool active = false);
        void switch_to(std::string const& name);

        scene& get_current_scene() const;

    private:
        std::unordered_map<std::string, std::unique_ptr<scene>> scenes;
        std::unique_ptr<scene> current_scene = nullptr;
};