cmake_minimum_required(VERSION 3.0)

include(ExternalProject)

ExternalProject_Add(boost
  URL               "https://downloads.sourceforge.net/project/boost/boost/1.57.0/boost_1_57_0.tar.bz2"
  URL_MD5           1be49befbdd9a5ce9def2983ba3e7b76
  BUILD_IN_SOURCE   1
  CONFIGURE_COMMAND ./bootstrap.sh --prefix=<INSTALL_DIR> --without-icu
  UPDATE_COMMAND    ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ./b2 install
    --with-system
    --threading=multi
    --link=static
    --runtime-link=shared
    --variant=release
    --build-dir=<BINARY_DIR>
    --prefix=<INSTALL_DIR>)

ExternalProject_Get_Property(boost INSTALL_DIR)

set_target_properties(boost PROPERTIES EXCLUDE_FROM_ALL TRUE)

foreach(LIB boost_system)
  set(PATH "${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}${LIB}${CMAKE_STATIC_LIBRARY_SUFFIX}")
  add_library(${LIB} STATIC IMPORTED)
  add_dependencies(${LIB} boost)
  set_target_properties(${LIB} PROPERTIES
    IMPORTED_LOCATION "${PATH}")
endforeach()

add_executable(foo foo.cc)
target_link_libraries(foo boost_system)
