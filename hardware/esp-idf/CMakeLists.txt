# ESP-IDF 项目根 CMake
# 需要已安装并 source 过 ESP-IDF 环境（idf.py / $IDF_PATH）
cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(blink)
