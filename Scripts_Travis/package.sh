(cd lib && ls)
cd src/install/example
mkdir build
ls
cd build
cmake ..
make
sudo make install
sudo make package
