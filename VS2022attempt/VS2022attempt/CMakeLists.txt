cmake_minimum_required (VERSION 3.8)

add_executable (ImGuiExample "ImGuiExample.cpp"  "UseImGui.h" "UseImGui.cpp")

set(glad_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glad")
find_package(glad CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE glad::glad)

set(glfw3_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/glfw3")
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE glfw)

set(imgui_DIR "C:/Users/Alex/Desktop/VCPKG/vcpkg/installed/x64-windows/share/imgui")
find_package(imgui CONFIG REQUIRED)
target_link_libraries(ImGuiExample PRIVATE imgui::imgui)
# TODO: Add tests and install targets if needed.