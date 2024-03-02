
cmake_minimum_required(VERSION 3.5)

project(TestProject LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TARGET_LINK_LIBRARIES PahoMqttCpp)
set(CMAKE_INSTALL_PREFIX /usr)

find_package(PahoMqttCpp REQUIRED)
find_package(Boost REQUIRED)


set(SRCS
    publisher.h
    publisher.cpp
    main.cpp
    parser.h
    parser.cpp
    subscriber.h
    subscriber.cpp
    database.h
    database.cpp)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PahoMqttCpp::paho-mqttpp3)
target_link_libraries(${PROJECT_NAME} pq)
set(PAHO_WITH_SSL=TRUE)
install(TARGETS  ${PROJECT_NAME} DESTINATION bin)
