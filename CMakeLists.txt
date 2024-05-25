cmake_minimum_required(VERSION 3.28)
project(SocialClub)

set(CMAKE_CXX_STANDARD 17)

add_executable(SocialClub main.cpp
        Club.cpp
        Club.h
        Member.cpp
        Member.h
        ClubManager.cpp
        ClubManager.h
        db.cpp
        db.h
        structures.cpp
        structures.h)
