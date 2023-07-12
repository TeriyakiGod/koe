#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameBehaviour.h"
#include <string>

namespace koe {

    class GameObject : public GameBehaviour {
    public:
        GameObject();
        ~GameObject();

        std::string name;
    };

} // namespace koe

#endif // GAMEOBJECT_H
