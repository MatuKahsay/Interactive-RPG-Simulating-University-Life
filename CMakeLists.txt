cmake_minimum_required (VERSION 3.8)

add_executable (ImGuiExample  
"main.cpp"
"scene.h" 
"display.h" 
"scene.cpp"  
"display.cpp"
"inventory.h"
"inventory.cpp"
"Combat.h"
"Combat.cpp"
"Character.h"
"Character.cpp"
 "Enemy.h" 
 "Enemy.cpp"
"item.h"
"item.cpp"
"Player.h"
"Player.cpp"
"Stats.h"
"Stats.cpp"
"GameLogic.h"
"GameLogic.cpp"
)

set(glad_DIR "C:/Users/zan/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glad")
find_package(glad CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE glad::glad)

set(glfw3_DIR "C:/Users/zan/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glfw3")
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE glfw)

set(imgui_DIR "C:/Users/zan/Desktop/VCPKG/vcpkg/installed/x64-windows/share/imgui")
find_package(imgui CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE imgui::imgui)

set(GLEW_DIR "C:/Users/zan/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glew")
find_package(GLEW REQUIRED)
target_link_libraries(ImGuiExample PRIVATE GLEW::GLEW)