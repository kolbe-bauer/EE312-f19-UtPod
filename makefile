final: UtPodDriver.o UtPod.o Song.o
	g++ -otest UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ UtPod.cpp
Song.o: Song.cpp Song.h
	g++ Song.cpp