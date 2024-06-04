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

set(DEPS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/deps")

# allegro
set(ALLEGRO_DIR "${DEPS_DIR}/allegro")
target_link_libraries(${PROJECT_NAME} "${ALLEGRO_DIR}/ALLEG40.lib")
# jgmod
set(JGMOD_DIR "${ALLEGRO_DIR}/jgmod")

# zlib
 set(ZLIB_DIR "${DEPS_DIR}/zlib")
target_link_libraries(${PROJECT_NAME} "${ZLIB_DIR}/zlib.lib")

target_include_directories(
	${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ALLEGRO_DIR}
    ${ALLEGRO_DIR}/include
    ${JGMOD_DIR}
    ${JGMOD_DIR}/include
    ${ZLIB_DIR}
    ${ZLIB_DIR}/include
)
