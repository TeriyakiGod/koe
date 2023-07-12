#include "Level.h"

namespace koe {

    Level::Level() {}

    void Level::AddObject(GameObject* object) {
        objects.push_back(object);
    }

} // namespace koe
