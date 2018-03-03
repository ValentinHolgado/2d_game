cmake_minimum_required(VERSION 3.6)
project(2DGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${2DGame_SOURCE_DIR}/cmake")

set(SOURCE_FILES main.cpp source/Game.cpp source/Game.h source/utils/Log.h source/GameObject.cpp source/GameObject.h source/TextureManager.h source/TextureManager.cpp source/GameMap.cpp source/GameMap.h source/components/PositionComponent.h source/systems/System.h source/systems/MovementSystem.h source/components/DirectionComponent.h source/systems/RenderSystem.h source/components/SpriteComponent.h source/systems/InputHandler.h source/components/InputComponent.h)
add_executable(2DGame ${SOURCE_FILES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR})

set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${LIB_PATH}/entt)

target_link_libraries(2DGame ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES})