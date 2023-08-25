#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace notepad{
    class NotepadWindow{
        private:
            int height;
            int width;
            std::string name;
            GLFWwindow* window;

        public:
            NotepadWindow(int height, int width,std::string name);
            void initWindow();
            ~NotepadWindow();
    };
}