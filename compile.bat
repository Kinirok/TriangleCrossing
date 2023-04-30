mkdir _build
cd _build
git submodule update --init --recursive
cmake -G "Visual Studio 16 2019" ..

