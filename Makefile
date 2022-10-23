.PHONY: all generate build rebuild lint coverage test valgrind

BUILD_DEV := True

all: build run

clean:
	rm -rf build

generate:
	cmake -S src/ -B build/ -DBUILD_DEV=$(BUILD_DEV)

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
	cmake --build build/ --target full_test_COVERAGE

coverage: 
	cmake --build build/ --target full_test_COVERAGE_FILE

lint:
	./run_linters.sh

format:
	./run_format.sh

valgrind:
	cmake --build build/ --target full_test_VALGRIND

build-docker:
	docker build . -f Dockerfile -t app 
	
dev:
	docker run --rm -it \
		-v $(PWD):/project \
		--user $$(id -u):$$(id -g) \
		app 

dev-sudo:
	docker run --rm -it \
		-v $(PWD):/project \
		app
