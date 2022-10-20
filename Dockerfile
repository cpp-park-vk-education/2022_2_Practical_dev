# syntax=docker/dockerfile:1
FROM gcc:latest AS base

RUN apt update -y 
RUN apt install -y cppcheck
RUN apt install -y libpqxx-dev 
RUN apt install -y clang-tidy 
RUN apt install -y python3-pip 
RUN apt install -y libc6-dbg 
RUN apt install -y cmake 
RUN apt install -y libboost-dev
RUN apt install -y nlohmann-json3-dev
RUN apt install -y libgtest-dev 
RUN apt install -y clang-format
RUN apt install -y valgrind

RUN pip install cpplint

WORKDIR /project

COPY . . 

