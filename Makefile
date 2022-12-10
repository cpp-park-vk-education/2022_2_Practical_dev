.PHONY: all generate build rebuild lint coverage test valgrind

BUILD_DEV := True

all: build run

clean:
	rm -rf build

generate:
	cmake -S src/ -B build/

silent-build:
	cmake --build build/ --config $(BUILD_DEV)

build: 
	@make -s silent-build 

build-tests:
	cmake -S src/ -B build/  -DBUILD_DEV=$(BUILD_DEV) -DSANITIZE_BUILD=False
	cmake --build build/

rebuild: clean generate

server:
	./build/server/cmd/Server

client:
	./build/client/cmd/Client

checker:
	./build/server/cmd/Checker

test: build
	cd build && ctest -VV -C $(BUILD_DEV)

coverage-stat: build-tests
	scripts/coverage_stat.sh

coverage: build-tests
	cmake --build build/ --target full_test_COVERAGE_FILE -s

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
		-v /var/run/docker.sock:/var/run/docker.sock \
		--env-file .env \
		app
