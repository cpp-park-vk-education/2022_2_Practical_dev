.PHONY: all generate build rebuild lint coverage test valgrind

BUILD_DEV := True

all: build run

clean:
	rm -rf build

generate:
	cmake -S . -B build/ -DBUILD_DEV=$(BUILD_DEV)

silent-build:
	cmake --build build/ --config $(BUILD_DEV)

build: 
	@make -s silent-build 

rebuild: clean generate

server:
	@echo "Not implemented"

client:
	@echo "Not implemented"

test: build
	cd build && ctest -VV -C $(BUILD_DEV)

coverage-stat:
	@echo "Not implemented"

coverage: 
	@echo "Not implemented"

lint:
	./run_linters.sh

format:
	./run_format.sh

valgrind:
	@echo "Not implemented"

