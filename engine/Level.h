#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "GameBehaviour.h"
#include "GameObject.h"

namespace koe {

    class Level : public GameBehaviour {
    public:
        Level();

        void AddObject(GameObject* object);

    private:
        std::vector<GameObject*> objects;
    };

} // namespace koe

#endif // LEVEL_H
