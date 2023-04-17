#include "core/texture_proxy.h"
#include "utils/constants.h"
#include <filesystem>

const Texture2D diamant::texture_proxy::load(const std::string& texture_path)
{
    const std::string path = ASSETS_PATH + texture_path;
    if (!std::filesystem::exists(path))
        return { 0 };
    const Texture2D texture = LoadTexture(path.c_str());
    return texture;
}