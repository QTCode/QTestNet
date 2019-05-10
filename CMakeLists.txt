cmake_minimum_required(VERSION 3.13)

project ( myTestNet )

# declaring files in your project

set ( SOURCES
 main.cpp
 QtTestNet.cpp
)

set ( MOC_HEADERS
 QtTestNet.h
)

set ( UIS
 QtTestNet.ui
)

set ( RESOURCES
 QtTestNet.qrc
)

# Next lines needed for building all Qt projects
# Find the QtWidgets library
  find_package(Qt5 COMPONENTS Core)
  set(CTK_QT5_COMPONENTS Core Gui Concurrent Widgets OpenGL UiTools WebSockets NetWork)
  
  find_package(Qt5 COMPONENTS ${CTK_QT5_COMPONENTS} REQUIRED)
add_definitions( ${QT_DEFINITIONS} )
include_directories( ${CMAKE_BINARY_DIR}
 ${CMAKE_SOURCE_DIR}/Include
 )

 set(KIT_target_libraries 
    ${Qt5Widgets_LIBRARIES} 
	${Qt5Gui_LIBRARIES} 
	${Qt5Widgets_LIBRARIES}
	${Qt5NetWork_LIBRARIES} 
	${Qt5WebSockets_LIBRARIES} 
	${KIT_target_libraries}
	)

# Next, using precompiler, compiler and linker

# using Qt meta-system (precompiler)
QT5_ADD_RESOURCES( RES_SOURCES ${RESOURCES} )
QT5_WRAP_UI( UI_HEADERS ${UIS} )
QT5_WRAP_CPP( MOC_SRCS ${MOC_HEADERS} )

# compile
add_executable( ${PROJECT_NAME} ${SOURCES} ${MOC_SRCS} ${RES_SOURCES} ${UI_HEADERS} )
# or use line below instead, if you using Windows ™ Operating System.
#add_executable( ${PROJECT_NAME} WIN32 ${SOURCES} ${MOC_SRCS} ${RES_SOURCES} ${UI_HEADERS} )

# build it (link libraries)
target_link_libraries( ${PROJECT_NAME} ${KIT_target_libraries}  )