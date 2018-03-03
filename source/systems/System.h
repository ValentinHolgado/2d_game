//
// Created by Valentín Holgado on 2/27/18.
//

#ifndef INC_2DGAME_SYSTEM_H
#define INC_2DGAME_SYSTEM_H

#include <entt.hpp>

class System {
public:
    // virtual dtor and the rule of 6
    System() = default;
    virtual ~System() = default;
    System(const System &) = default;
    System &operator=(const System &) = default;
    System(System &&) = default;
    System &operator=(System &&) = default;

    virtual void Update(entt::DefaultRegistry &registry, double dt) = 0;
};

#endif //INC_2DGAME_SYSTEM_H
