# Try to find the SFML components
find_package(PkgConfig)
pkg_check_modules(PC_SFML QUIET sfml-2.4.2)
set(LIBSFML2_DEFINITIONS ${PC_SFML_CFLAGS_OTHER})

find_path(LIBSFML2_INCLUDE_DIR sfml/xpath.h HINTS ${PC_LIBSFML_INCLUDEDIR} ${PC_LIBSFML_INCLUDE_DIRS} PATH_SUFFIXES libsfml2)

find_library(LIBSFML2_LIBRARY NAMES sfml sfml2 HINTS ${PC_LIBSFML_LIBDIR} ${PC_LIBSFML_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(LibSFML2 DEFAULT_MSG 
