#ifndef MEMORY_H
#define MEMORY_H

#include <list>
#include "win32.h"
#include "PhysicalMemory.h"

class Memory {
private:
	uint64_t maxSize;
	uint64_t freeSpace;
	uint64_t usage;
	list<PhysicalMemory*> memories;

	void calculate() { 
		list<PhysicalMemory*>::iterator iter;
		list<PhysicalMemory*>::iterator endIter;
		iter = memories.begin();
		endIter = memories.end();
		uint64_t capacity = 0;

		while (iter != endIter) {
			capacity += (*iter)->getCapacity();
		}
		maxSize = capacity;
	}

public:
	Memory() {}
	~Memory() {}

	list<PhysicalMemory*> getPhysicalMemories() { return memories; }
	uint64_t getMaxSize() { return maxSize; }
	uint64_t getFreeSpace() { return freeSpace; }
	uint64_t getUsage() { return usage; }

	void setPhysicalMemories(list<PhysicalMemory*> v) { memories = v; }
	void setMaxSize(uint64_t v) { maxSize = v; }
	void setFreeSpace(uint64_t v) { freeSpace = v; }
	void setUsage(uint64_t v) { usage = v; }
};

#endif