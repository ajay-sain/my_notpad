cmake_minimum_required(VERSION 3.27.3)

project(notepad VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

configure_file(notepadConfig.h.in notepadConfig.h)

option(USE_ADDR "this is a test example" OFF)

add_executable(notepad ./src/Application.cpp ./src/error.cpp ./src/input.cpp ./src/notepad.cpp)

# if(USE_ADDR)
#     add_subdirectory(lib/addr)
#     list(APPEND EXTRA_LIBS lib/addr)
#     list(APPEND EXTRA_INCLUDE_DIR lib/addr/include)
#     list(APPEND EXTRA_LINKS myaddr)
# endif()

target_include_directories(${PROJECT_NAME} 
        PUBLIC lib/glfw/include
        PUBLIC lib/glm/include
        PUBLIC ${PROJECT_BINARY_DIR}
        ${Vulkan_INCLUDE_DIR}
        # ${EXTRA_INCLUDE_DIR}
    )

target_link_directories(${PROJECT_NAME} 
        PRIVATE lib/glfw/src
        # ${EXTRA_LIBS}
    )

target_link_libraries(${PROJECT_NAME} 
        glfw
        glm::glm
        Vulkan::Vulkan
        # ${EXTRA_LINKS}
    )

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/notepadConfig.h" DESTINATION include)
