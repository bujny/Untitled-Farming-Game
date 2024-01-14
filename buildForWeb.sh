echo "Building for Web"
echo "-----------------"
rm -rf build
source ../emsdk/emsdk_env.sh
emcmake cmake -S . -B build -DPLATFORM=Web
cmake --build build