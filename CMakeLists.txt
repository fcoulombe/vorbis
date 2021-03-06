# Copyright (C) 2007-2012 LuaDist.
# Created by Peter Kapec
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

PROJECT(ogg C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
include ( cmake/dist.cmake )

include ( CheckIncludeFile )

# Specify library include directories
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include/vorbis")
include_directories("${PROJECT_SOURCE_DIR}/lib")

include_directories("${OGG_ROOT}/include")

IF(${MSVC})
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4305")  #conversion double to float
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244")  #conversion double to float
ENDIF()

# First, compiler definitions for building the library
ADD_DEFINITIONS(-D_USRDLL)
ADD_DEFINITIONS(-DLIBVORBIS_EXPORTS)

set(VORBIS_SRCS
       lib/analysis.c
        lib/bitrate.c
        lib/block.c
        lib/codebook.c
        lib/envelope.c
        lib/floor0.c
        lib/floor1.c
        lib/info.c
        lib/lookup.c
        lib/lpc.c
        lib/lsp.c
        lib/mapping0.c
        lib/mdct.c
        lib/psy.c
        lib/registry.c
        lib/res0.c
        lib/sharedbook.c
        lib/smallft.c
        lib/synthesis.c
        lib/vorbisenc.c
        lib/window.c)

IF (${BUILD_SHARED_LIBS})
	ADD_LIBRARY(vorbis SHARED ${VORBIS_SRCS} )
ELSE()
    ADD_LIBRARY(vorbis STATIC ${VORBIS_SRCS} )
ENDIF()

# Install Vorbis Library
	install_library(vorbis)

# Install Vorbis Headers
	install_header(include/)



set(VORBISFILE_SRCS
    lib/vorbisfile.c)
    
IF (${BUILD_SHARED_LIBS})
	ADD_LIBRARY(vorbisfile SHARED ${VORBISFILE_SRCS} )
ELSE()
    ADD_LIBRARY(vorbisfile STATIC ${VORBISFILE_SRCS} )
ENDIF()

# Install Vorbis Library
	install_library(vorbisfile)

# Install Vorbis Headers
	install_header(include/)
