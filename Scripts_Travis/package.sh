pwd
cp -a $HOME/lib/cache $HOME/build/Felipe-Thorn/CDC/lib/
(cd lib && ls)
cd src/install/example
mkdir build
ls
cd build
cmake ..
make
sudo make install
sudo make package
