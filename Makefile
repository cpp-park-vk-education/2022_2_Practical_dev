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

build-tests:
	cmake -S src/ -B build/ -DSANITIZE_BUILD=ON
	cmake --build build/ --target db_tests

rebuild: clean generate

server:
	./build/cmd/server/Server

client:
	./build/cmd/client/Client

test: build-tests
	cd build && ctest -VV -C $(BUILD_DEV)

coverage-stat: build-tests
	scripts/coverage_stat.sh

coverage: build-tests
	cmake --build build/ --target full_test_COVERAGE_FILE

lint:
	./run_linters.sh

format:
	./run_format.sh

valgrind: build-tests
	cmake --build build/ --target full_test_VALGRIND

build-docker:
	docker build . -f Dockerfile -t app 
	
dev:
	docker run --rm -it \
		-v $(PWD):/project \
		--user $$(id -u):$$(id -g) \
		--env-file .env \
		app 

dev-sudo:
	docker run --rm -it \
		-v $(PWD):/project \
		--env-file .env \
		app
