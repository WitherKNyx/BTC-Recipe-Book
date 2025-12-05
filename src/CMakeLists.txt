add_executable(RecipeBook "main.cpp")

# add_subdirectory("")

target_link_libraries(RecipeBook ncursesw)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET RecipeBook PROPERTY CXX_STANDARD 20)
endif()
