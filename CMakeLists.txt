cmake_minimum_required(VERSION 2.8)
PROJECT(scan-registration-app)
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(sra_SOURCES src/main.cpp src/mainwindow.cpp)
SET(sra_HEADERS include/mainwindow.h)
SET(sra_FORMS include/mainwindow.ui)

# Invoking MOC for headers
QT4_WRAP_CPP(sra_HEADERS_MOC ${sra_HEADERS})

# Invoking UIC for forms
QT4_WRAP_UI(sra_FORMS_HEADERS ${sra_FORMS})

# Set Output Directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(scanRegistrationApp ${sra_SOURCES} ${sra_HEADERS_MOC} ${sra_FORMS})
TARGET_LINK_LIBRARIES(scanRegistrationApp ${QT_LIBRARIES})
