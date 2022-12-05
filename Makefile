
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

rebuild: clean generate

server:
	./build/server/cmd/Server

client:
	./build/client/cmd/Client

test: build-tests
	cd build && ctest -VV -C $(BUILD_DEV)


testCN: build
	./build/client/internal/network/tests/network_tests

coverage-stat: build-tests
	scripts/coverage_stat.sh

coverage: build-tests
	cmake --build build/ --target full_test_COVERAGE_FILE

lint:
	./run_linters.sh

format:
	./run_format.sh

	cmake --build build/


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
