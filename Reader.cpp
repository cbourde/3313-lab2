#include <iostream>
#include "SharedObject.h"

struct MyShared{
	int threadID;
	int reportNum;
	time_t timeSinceLastReport;
};

int main(void)
{
	// Declare shared memory object so the program can access it
	Shared<MyShared> sharedMemory("sharedMemory");

	// Get a pointer to the shared memory object
	MyShared* shared = sharedMemory.get();

	std::cout << "I am a reader" << std::endl;

	// Loops continuously until externally terminated (^C or other means)
	while (true)
	{
		// Read shared memory object and output contents
		std::cout << "Thread: " << (shared -> threadID) << "; Report:" << (shared -> reportNum) << "; TimeDiff: " << (shared -> timeSinceLastReport) << std::endl;

		// Wait 1 second before polling again
		sleep(1);
	}
}
