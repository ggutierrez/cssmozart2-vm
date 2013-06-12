set(DEFAULT_GECODE_INSTALL_DIR "${ep_base}/Install/gecode")
set(GECODE_INSTALL_DIR ${DEFAULT_GECODE_INSTALL_DIR} CACHE PATH
  "Path to Gecode installation")

set(GECODE_VERSION 3.7.3)

if("${GECODE_INSTALL_DIR}" STREQUAL "${DEFAULT_GECODE_INSTALL_DIR}" AND
   NOT EXISTS "${GECODE_INSTALL_DIR}/lib/gecode/kernel.hh")

  message(STATUS "Gecode version ${GECODE_VERSION} will be fetch and built")
  set(GECODE_SRC_DIR "${ep_base}/Source/gecode")
  set(GECODE_BUILD_DIR "${ep_base}/Build/gecode")

  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "-stdlib=libc++ ${CMAKE_CXX_FLAGS}")
  endif()

  separate_arguments(GECODE_CONFIGURE_ARGS UNIX_COMMAND
    "CC=${CMAKE_C_COMPILER}
     CXX=${CMAKE_CXX_COMPILER}
     CXX_FLAGS=${CMAKE_CXX_FLAGS}
     CPPFLAGS=${CMAKE_C_FLAGS}
     --enable-static
     --disable-shared
     --prefix=${GECODE_INSTALL_DIR}
     --libdir=${GECODE_INSTALL_DIR}/lib
     --disable-gist
     --disable-flatzinc
     --disable-examples 
     --disable-qt
     --disable-driver
     --disable-minimodel"
  )

  ExternalProject_Add(
    gecode
    URL http://www.gecode.org/download/gecode-${GECODE_VERSION}.tar.gz
    SOURCE_DIR ${GECODE_SRC_DIR}
    BINARY_DIR ${GECODE_BUILD_DIR}
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CONFIGURE_COMMAND ${GECODE_SRC_DIR}/configure 
    ${GECODE_CONFIGURE_ARGS}
    BUILD_COMMAND make -j 4
    INSTALL_COMMAND make install    
  )
endif()

link_directories(${GECODE_INSTALL_DIR}/lib)
set(GECODE_LIBRARIES 
  gecodesearch 
  gecodeset
  gecodeint
  gecodekernel
  gecodesupport
)
set(GECODE_INCLUDES ${GECODE_INSTALL_DIR}/include)

foreach(GECODE_LIB ${GECODE_LIBRARIES})
  add_library(${GECODE_LIB} STATIC IMPORTED)
  set_property(TARGET ${GECODE_LIB} PROPERTY 
               IMPORTED_LOCATION ${GECODE_INSTALL_DIR}/lib/lib${GECODE_LIB}.a)
endforeach()