#ifndef PARTITIO_H
#define PARTITIO_H

#include "win32.h"

class Partition {
private:
	string letter;
	int32_t index;	
	string fileSystem;
	uint64_t freeSpace;
	uint64_t size;
	string volumeName;
public:
	Partition() {}
	~Partition() {}

	void setLetter (string v) { letter = v; }
	string getLetter () { return letter; }
	void setFileSystem (string v) { fileSystem = v; }
	string getFileSystem () { return fileSystem; }
	void setVolumeName (string v) { volumeName = v; }
	string getVolumeName () { return volumeName; }
	void setIndex (int32_t v) { index = v; }
	int32_t getIndex () { return index; }
	void setFreeSpace (uint64_t v) { freeSpace = v; }
	uint64_t getFreeSpace () { return freeSpace; }
	void setSize (uint64_t v) { size = v; }
	uint64_t getSize () { return size; }
};
#endif