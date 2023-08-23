cmake_minimum_required(VERSION 3.27.3)

project(notepad VERSION 0.1.0 LANGUAGES C CXX)

configure_file(notepadConfig.h.in notepadConfig.h)

option(USE_ADDR "this is a test example" OFF)

add_executable(notepad ./src/main.cpp ./src/error.cpp ./src/input.cpp)

if(USE_ADDR)
    add_subdirectory(external/addr)
    list(APPEND EXTRA_LIBS external/addr)
    list(APPEND EXTRA_INCLUDE_DIR external/addr/include)
    list(APPEND EXTRA_LINKS myaddr)
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
        PUBLIC external/glfw/include
        PUBLIC ${PROJECT_BINARY_DIR}
        ${EXTRA_INCLUDE_DIR}
    )

target_link_directories(${PROJECT_NAME} 
        PRIVATE external/glfw/src
        ${EXTRA_LIBS}
    )

target_link_libraries(${PROJECT_NAME} glfw ${EXTRA_LINKS})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/notepadConfig.h" DESTINATION include)
