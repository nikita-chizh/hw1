cmake_minimum_required(VERSION 3.2)
MESSAGE(STATUS $ENV{TRAVIS_BUILD_NUMBER})
project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
set(CMAKE_CXX_STANDARD 14)

configure_file(version.h.in ../version.h)

add_executable(helloworld_cli main.cpp)
add_executable(test_version test.cpp)


add_library(helloworld lib.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
        CXX_STANDART 14
        CXX_STANDART_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFENITONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

target_link_libraries(helloworld_cli helloworld pthread)

target_link_libraries(test_version
        ${Boost_LIBRARIES}
        helloworld
        pthread
        )
install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT nikita1993chizh@gmail.com)
include(CPack)
enable_testing()
add_test(test_version test_version)