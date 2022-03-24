cmake_minimum_required(VERSION 3.13)
project(opencv-experiments CXX)

find_package(OpenCV REQUIRED)
add_library(OpenCV INTERFACE)
target_include_directories(OpenCV INTERFACE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(OpenCV INTERFACE ${OpenCV_LIBS})

# Windows上没找到可以find_package(eigen)的包
add_library(Eigen INTERFACE)
target_include_directories(Eigen INTERFACE "${Eigen_INCLUDE_DIR}")

add_library(common INTERFACE)
target_link_libraries(common INTERFACE OpenCV Eigen)
if(WIN32)
	target_compile_definitions(common INTERFACE /utf-8)
endif()
target_precompile_headers(common INTERFACE <opencv2/opencv.hpp>)
target_compile_definitions(common INTERFACE PRECOMPILE_CMAKE)

function(init_experiment name)
	target_link_libraries(${name} common)
	add_custom_target(run-${name} VERBATIM COMMAND ${name} WORKING_DIRECTORY ${opencv-experiments_SOURCE_DIR})
	set(targets ${name} run-${name})
	if(COPY_DLL AND WIN32 AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.21)
		# Only run when building ALL, otherwise imparts severe delay on run-${name}
		add_custom_target(dependency-${name} ALL COMMAND_EXPAND_LISTS VERBATIM
			COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:${name}> $<TARGET_FILE_DIR:${name}>)
		list(APPEND targets dependency-${name})
	endif()
	set_target_properties(${targets} PROPERTIES FOLDER ${PROJECT_NAME})
	set_target_properties(${name} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${opencv-experiments_SOURCE_DIR})
endfunction()

if(COPY_DLL AND WIN32 AND ${CMAKE_VERSION} VERSION_LESS 3.21)
	message(STATUS "Unable to automatically copy dll dependency on windows with cmake < 3.21.")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


add_subdirectory(window)
add_subdirectory(transparency)
add_subdirectory(eigen)
