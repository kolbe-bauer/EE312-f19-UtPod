final: myDriver.o UtPod.o Song.o
	g++ -otest myDriver.o UtPod.o Song.o
driver: myDriver.cpp UtPod.h Song.h
	g++ -c myDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp