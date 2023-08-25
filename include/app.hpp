#pragma once

#include "notepad.hpp"

namespace notepad{
    class App{
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

        private:
            NotepadWindow _n_window{WIDTH, HEIGHT, "Hello Windo"};

        public: 
            void run(){};
    };
}