cmake_minimum_required (VERSION 3.8)

add_executable (ImGuiExample  "scene.h" "display.h" "scene.cpp"  "display.cpp" "main.cpp")

set(glad_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glad")
find_package(glad CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE glad::glad)

set(glfw3_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glfw3")
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE glfw)

set(imgui_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/imgui")
find_package(imgui CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE imgui::imgui)

set(GLEW_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glew")
find_package(GLEW REQUIRED)
target_link_libraries(ImGuiExample PRIVATE GLEW::GLEW)