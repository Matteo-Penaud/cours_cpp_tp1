cmake_minimum_required(VERSION 3.0.0)
project(TP1 VERSION 0.1.0)


add_executable(subscriber src/subscriber.cpp)
target_include_directories(subscriber PRIVATE inc)

add_executable(publisher src/publisher.cpp)
target_include_directories(publisher PRIVATE inc)

target_link_libraries(subscriber paho-mqttpp3 paho-mqtt3a)
target_link_libraries(publisher paho-mqttpp3 paho-mqtt3a)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
