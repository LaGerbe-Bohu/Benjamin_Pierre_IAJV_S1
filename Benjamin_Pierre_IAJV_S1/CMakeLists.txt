# CMakeList.txt : CMake project for Benjamin_Pierre_IAJV_S1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
file(GLOB_RECURSE Classes
     "*.h"
     "*.cpp"
)

add_executable (Benjamin_Pierre_IAJV_S1 ${Classes})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Benjamin_Pierre_IAJV_S1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
