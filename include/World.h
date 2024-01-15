#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <cstdint>

#include <raylib.h>

namespace gameCharacteristics
{
    inline constexpr int kScreenWidth{1920};
    inline constexpr int kScreenHeight{1080};
    inline constexpr int kFps{60};
} // namespace gameCharacteristics

namespace mapCharacteristics 
{
    inline constexpr Color kWorldBackground{139, 163, 82};
    inline constexpr uint8_t tileSizePx{10};
} // namespace mapCharacteristics;

class IDrawable
{
public:
    virtual void draw() = 0;
};

class World : IDrawable
{
public:
    World();
    World(const World& world) = delete;
    World(const World&& wolrd) = delete;
    World& operator=(const World& world) = delete;
    World&& operator=(const World&& world) = delete;

    void draw();
};

class Tile : IDrawable
{
public:
    Tile();
    explicit Tile(uint8_t size);
    Tile(const Tile& tile) = delete;
    Tile(const Tile&& tile) = delete;
    Tile& operator=(const Tile& tile) = delete;
    Tile&& operator=(const Tile&& tile) = delete;

    void draw();

private:
    uint8_t size_;
    Texture backgroundTexture_;
    Color backgroundColor_;
};

using TiledScene = std::vector<std::vector<Tile>>;

class Scene : IDrawable
{
public:
    Scene() = default;
    explicit Scene(const uint8_t width, const uint8_t height);
    Scene(const Scene& scene) = delete;
    Scene(const Scene&& scene) = delete;
    Scene& operator=(const Scene& scene) = delete;
    Scene&& operator=(const Scene&& scene) = delete;

    void draw();

private:
    uint8_t width_;
    uint8_t height_;
    TiledScene tiledScene_;
};

#endif // WORLD_H