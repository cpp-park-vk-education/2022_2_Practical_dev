# syntax=docker/dockerfile:1
FROM ubuntu:20.04 AS base

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update -y
RUN apt install -y gcc
RUN apt install -y libpqxx-dev 
RUN apt install -y clang-tidy 
RUN apt install -y python3-pip 
RUN apt install -y cppcheck
RUN apt install -y libc6-dbg 
RUN apt install -y cmake
RUN apt install -y libboost-dev
RUN apt install -y nlohmann-json3-dev
RUN apt install -y libgtest-dev 
RUN apt install -y clang-format
RUN apt install -y valgrind
RUN apt install -y git
RUN apt install -y qt5-default
RUN apt install -y libboost-all-dev
RUN apt-get update -y
RUN apt install -y xvfb
RUN pip install gcovr
RUN pip install cpplint

WORKDIR /project

COPY . . 
