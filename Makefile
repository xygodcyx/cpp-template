PROJECT_NAME	  := myapp
BUILD_DIR_DEBUG   := build/debug
BUILD_DIR_RELEASE := build/release

JOBS := $(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

.DEFAULT_GOAL := debug

.PHONY: config debug release clean

config:
	cmake --preset debug

debug:
	cmake --preset debug
	cmake --build --preset debug -j$(JOBS)
	ln -sfn $(BUILD_DIR_DEBUG)/compile_commands.json compile_commands.json

release:
	cmake --preset release
	cmake --build --preset release -j$(JOBS)
	ln -sfn $(BUILD_DIR_RELEASE)/compile_commands.json compile_commands.json

clean:
	rm -rf build bin compile_commands.json

run: debug
	./build/debug/$(PROJECT_NAME)
