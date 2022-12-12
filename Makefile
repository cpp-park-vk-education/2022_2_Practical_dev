.PHONY: all generate build rebuild lint coverage test valgrind

BUILD_DEV := True

all: build run

clean:
	rm -rf build

generate:
	./set_screen.sh
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
	./set_screen.sh
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
	cmake --build build/ --target full_test_VALGRIND || sh -c "exit 0"
	cmake --build build/ --target full_test_VALGRIND | ./scripts/check_valgrind.py

mock-db:
	PGPASSWORD=slavapswd psql -h 0.0.0.0 -U slava -d slavadb -f sql/mock.sql 

build-docker:
	docker build . -f Dockerfile --rm -t app 
	
dev:
	docker run --rm -it \
		-v $(PWD):/project \
		--user $$(id -u):$$(id -g) \
		--env-file .env \
		app 

dev-db:
	docker run --rm -it \
		-v $(PWD):/project \
		--user $$(id -u):$$(id -g) \
		--env-file .env \
		--network 2022_2_practical_dev_contest-network \
		app 

dev-sudo:
	docker run --rm -it \
		-v $(PWD):/project \
		-v /var/run/docker.sock:/var/run/docker.sock \
		--env-file .env \
		--network 2022_2_practical_dev_contest-network \
		app
