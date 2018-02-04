cd build
make
sudo make install
build-wrapper-linux-x86-64 --out-dir bw-output make   #The output is written in build
cd ..
sonar-scanner   #sonar-project.properties must access the correct output path
(cd ../.. && ls)
#cp -a  /home/travis/build/Felipe-Thorn/CDC/lib/ /home/travis/.casher
