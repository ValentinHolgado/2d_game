//
// Created by Valentín Holgado on 3/2/18.
//

#ifndef INC_2DGAME_RENDERCOMPONENT_H
#define INC_2DGAME_RENDERCOMPONENT_H

#include <string>

struct SpriteComponent {
    std::string texturePath;
    int w = 32, h = 32;
};

#endif //INC_2DGAME_RENDERCOMPONENT_H
