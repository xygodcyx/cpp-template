.PHONY: debug release clean

config:
	cmake -B build/debug -DCMAKE_BUILD_TYPE=Debug
	ln -sf build/debug/compile_commands.json compile_commands.json

debug:
	cmake -B build/debug -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/debug -j$$(nproc)
	ln -sf build/debug/compile_commands.json compile_commands.json

release:
	cmake -B build/release -DCMAKE_BUILD_TYPE=Release
	cmake --build build/release -j$$(nproc)
	ln -sf build/release/compile_commands.json compile_commands.json

clean:
	rm -rf build bin compile_commands.json

run: debug
	./build/debug/app
