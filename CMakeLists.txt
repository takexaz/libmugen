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

# allegro
set(DEPS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/deps")
target_link_libraries(${PROJECT_NAME} "${DEPS_DIR}/ALLEG40.lib")

target_include_directories(
	${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
	${DEPS_DIR}
    ${DEPS_DIR}/allegro/include
)
