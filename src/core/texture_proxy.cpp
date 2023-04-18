#include "core/texture_proxy.h"
#include "utils/constants.h"
#include "exceptions/file_not_found_exception.h"
#include <filesystem>

const Texture2D diamant::texture_proxy::load(const std::string& texture_path)
{
    const std::string path = ASSETS_PATH + texture_path;
    if (!std::filesystem::exists(path))
        throw file_not_found_exception(path);
    const Texture2D texture = LoadTexture(path.c_str());
    return texture;
}