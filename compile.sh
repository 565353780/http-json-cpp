rm -rf build
mkdir build
cd build
cmake .. \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=on \
	-DCMAKE_BUILD_TYPE=Release
make -j
