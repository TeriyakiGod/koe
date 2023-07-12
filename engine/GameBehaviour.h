#ifndef KOE_GAMEBEHAVIOUR_H
#define KOE_GAMEBEHAVIOUR_H

namespace koe {

    class GameBehaviour {
    public:
        virtual void OnStart() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnRender() = 0;
        virtual void OnCleanup() = 0;
    };

} // namespace koe

#endif // KOE_GAMEBEHAVIOUR_H
