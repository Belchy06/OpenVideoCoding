cmake_minimum_required (VERSION 3.14)
if(POLICY CMP0056) # added in CMake 3.2
  cmake_policy(SET CMP0056 NEW)
endif()

if(POLICY CMP0091) # added in CMake 3.14
  cmake_policy(SET CMP0091 NEW)
endif()

project (ovc CXX C)

include(GNUInstallDirs)

find_package(Threads REQUIRED)


# Project options
option(BUILD_SHARED_LIBS "Build shared instead of static libraries." OFF)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()


# Target arch detection
if(NOT OVC_TARGET_ARCH)
  # Determine arch based on host cpu and generator used
  if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio .+ ARM$")
    set(OVC_TARGET_ARCH "ARM")
  elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64" OR
    "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64" OR
    "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" OR
    "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i386" OR
    "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86")
    set(OVC_TARGET_ARCH "x86")
  elseif("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "aarch64|armv7")
    set(OVC_TARGET_ARCH "ARM")
  else()
    message(FATAL_ERROR "Unexpected host cpu: ${CMAKE_SYSTEM_PROCESSOR}")
  endif()
else()
  # Extract architecture family from user specified arch
  if("${OVC_TARGET_ARCH}" STREQUAL "x86_64")
    set(OVC_TARGET_ARCH "x86")
  elseif("${OVC_TARGET_ARCH}" MATCHES "^arm")
    set(OVC_TARGET_ARCH "ARM")
  elseif("${OVC_TARGET_ARCH}" MATCHES "^mips")
    set(OVC_TARGET_ARCH "MIPS")
  endif()
endif()
if(NOT "${OVC_TARGET_ARCH}" MATCHES "^(x86|ARM|MIPS)$")
  message(FATAL_ERROR "Unexpected target architecture: ${OVC_TARGET_ARCH}")
endif()

add_subdirectory(src)
add_subdirectory(test)

# pkg-config support
set(PKG_CONFIG_LINK_LIBS "")
foreach(LIB ${CMAKE_CXX_IMPLICIT_LINK_LIBRARIES})
  if(IS_ABSOLUTE ${LIB} AND EXISTS ${LIB})
    set(PKG_CONFIG_LINK_LIBS "${PKG_CONFIG_LINK_LIBS} ${LIB}")
  else()
    set(PKG_CONFIG_LINK_LIBS "${PKG_CONFIG_LINK_LIBS} -l${LIB}")
  endif()
endforeach()
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ovc.pc.in" "${CMAKE_CURRENT_BINARY_DIR}/ovc.pc" @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ovc.pc"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
