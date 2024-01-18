#include "World.hpp"
#include "Logger.hpp"

using namespace world;

Tile::Tile() : size_{10U}, backgroundTexture_{}, backgroundColor_{0, 0, 0} {}

Tile::Tile(uint8_t size) : size_{size}, backgroundTexture_{}, backgroundColor_{0, 0, 0} {}

void Tile::draw()
{
}

Scene::Scene(const uint8_t width, const uint8_t height) : width_{width}, height_{height}
{
    // tiledScene_.reserve(width_);
    // for (auto& tileBelt : tiledScene_)
    // {
    //     tileBelt.reserve(height_);
    // }
    logger::Logger::getLogger().print(logger::LogType::logDebug, "Scene created");
}

void Scene::draw() {}