#pragma once

#include "../include/app.hpp"

namespace notepad{
    public: App::run(void){
        while(!window.glfwShouldClose()){
            glfwPollEvents();
        }
    }
}