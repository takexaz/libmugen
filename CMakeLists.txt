cmake_minimum_required (VERSION 3.23.2)

project (libmugen VERSION 0.0.1 LANGUAGES CXX)

file (GLOB source source/*.cpp source/*.c)
file (GLOB include include/*.hpp include/*.h)

add_library (
	${PROJECT_NAME} STATIC
	${source}
	${include}
)

target_compile_features (${PROJECT_NAME} PUBLIC cxx_std_20)
target_compile_definitions(${PROJECT_NAME} PRIVATE ALLEGRO_MSVC)

# allegro
set(ALLEGRO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/deps/allegro")
target_link_libraries(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/include/deps/ALLEG40.lib")

target_include_directories(
	${PROJECT_NAME}
    PUBLIC 
    ${ALLEGRO_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
