#include "../include/app.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
int main(int argc, char const *argv[])
{
    /* code */
    notepad::App app{};
    try{
        app.run();
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
