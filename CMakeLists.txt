#################################################################
cmake_minimum_required (VERSION 2.6 FATAL_ERROR) 
#set (CMAKE_VERBOSE_MAKEFILE ON)

set (App_Name "sdl-collision-events") 
if(App_Name STREQUAL "")
	message(FATAL_ERROR "You Must set the App_Name varable")
endif() 

project (${App_Name})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


##################################################################

set (Build_Dir_OK "TRUE")
string (REGEX MATCH "^${CMAKE_SOURCE_DIR}" In_Sub_Dir ${CMAKE_BINARY_DIR})
if (In_Sub_Dir)
  string (REGEX MATCH "^${CMAKE_SOURCE_DIR}" In_Build_Dir ${CMAKE_BINARY_DIR})
  if (NOT In_Build_Dir)
    set (Build_Dir_OK "FALSE")
  endif ()
endif ()

if (NOT Build_Dir_OK)
  message (FATAL_ERROR "You must run cmake from a directory that is not in your source tree, or that is in a special subdirectory of the tree whose name begins with ‘build’.")
endif ()

###########################################################################


if (CMAKE_BUILD_TYPE STREQUAL "") 
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE) 
endif() 

###############################################################################

file (GLOB SRCS sdl-collision-events-src/*.c sdl-collision-events-src/*.cpp)
file (GLOB HDRS sdl-collision-events-src/*.h sdl-collision-events-src/*.hpp)

link_directories(
)

include_directories(
	${CMAKE_SOURCE_DIR}/include
	)

if(WIN32)
	add_executable(${App_Name} WIN32
	${SRCS}
	${HDRS}
	)

	SET_TARGET_PROPERTIES(${App_Name} PROPERTIES COMPILE_FLAGS "/Od /ZI")
	SET_TARGET_PROPERTIES(${App_Name} PROPERTIES LINK_FLAGS "/DEBUG")
	
else ()
	add_executable (${App_Name}
	${SRCS}
	${HDRS}
	)
endif () 

target_link_libraries(${App_Name} 
) 

#################################################################3


option(Option_SDL_Dev "" ON)

if (Option_SDL_Dev) 
	find_package(SDL2)
	if (NOT SDL2_FOUND)
		message (FATAL_ERROR "SDL not found!") 
	endif (NOT SDL2_FOUND)

	find_package(SDL2_image)
	if (NOT SDL2IMAGE_FOUND)
		message (FATAL_ERROR "SDL_Image not found!") 
	endif (NOT SDL2IMAGE_FOUND)

	include_directories(
		${SDL2_INCLUDE_DIR}
		${INCLUDE_DIRECTORIES}
		)
	target_link_libraries(${App_Name}
		${SDL2_LIBRARY}
		${SDL2MAIN_LIBRARY}
		${SDL2IMAGE_LIBRARY}
		${TARGET_LINK_LIBRARIES}
		)
	
endif(Option_SDL_Dev) 

#message("${CMAKE_SOURCE_DIR}/assets")
#message("${CMAKE_BINARY_DIR}")

file(COPY "${CMAKE_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}")




