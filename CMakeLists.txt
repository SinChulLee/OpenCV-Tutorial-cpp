# CMake 최소버전 입력
cmake_minimum_required(VERSION 3.10)

# 프로젝트명 입력 (특수문자 사용 불가)
# EX) project(Project_Name)
project(LoadAndDisplayImage)

# OpenCV 찾기
find_package(OpenCV REQUIRED)

# 헤더 파일 포함
include_directories(${OpenCV_INCLUDE_DIRS})

# 실행 파일 생성
# EX) add_executable(Project_Name .cpp file경로)
add_executable(LoadAndDisplayImage "1. Load & Display Image/LoadAndDisplayImage.cpp")

# OpenCV 라이브러리 링크
# EX) target_link_libraries(Project_Name ${OpenCV_LIBS})
target_link_libraries(LoadAndDisplayImage ${OpenCV_LIBS})
