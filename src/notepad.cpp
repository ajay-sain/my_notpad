#include "../include/notepad.hpp"

namespace notepad{
    NotepadWindow::NotepadWindow(int h, int w, std::string n):height(h), width(w), name(n){
        initWindow();
    }

    NotepadWindow::~NotepadWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    
    void NotepadWindow::initWindow(){
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    }
}