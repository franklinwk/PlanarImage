cmake_minimum_required(VERSION 2.8.9)

#-----------------------------------------------------------------------------
project(PlanarImage)

#-----------------------------------------------------------------------------
set(EXTENSION_HOMEPAGE "")
set(EXTENSION_CATEGORY "Radiotherapy") #change
set(EXTENSION_CONTRIBUTORS "Franklin King (PerkLab, Queen's University), Csaba Pinter (Perklab, Queen's University), Andras Lasso (Perklab, Queen's University)")
set(EXTENSION_DESCRIPTION "")
set(EXTENSION_ICONURL "")
set(EXTENSION_SCREENSHOTURLS "")
set(EXTENSION_STATUS "Experimental")
set(EXTENSION_DEPENDS "NA") # Specified as a space separated list or 'NA' if any

#-----------------------------------------------------------------------------
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
add_subdirectory(PlanarImage)

#-----------------------------------------------------------------------------
INCLUDE(${Slicer_EXTENSION_CPACK})
