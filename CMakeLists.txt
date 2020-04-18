cmake_minimum_required (VERSION 2.6)
project (SDL_Tutorial)
INCLUDE(FindPkgConfig)
set(CMAKE_CXX_STANDARD 11)

### Dependencies
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})
set(SDL2TTF_LDFLAGS ${SDL2_LIBRARIES}) 

find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
set(SDL2MIXER_LDFLAGS ${SDL2_LIBRARIES}) 

set(GAME_EXE pong)
add_executable(${GAME_EXE} src/main.cpp src/SdlSession.cpp src/SdlWindow.cpp src/Paddle.cpp src/InputManager.cpp src/Ball.cpp src/Score.cpp)

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
target_link_libraries(${GAME_EXE} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
