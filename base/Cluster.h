#ifndef __CLUSTER_H__
#define __CLUSTER_H__
//
#include "queue.h"
#include <time.h>
#include <iostream>
const int MAX_SIZE_CLUSTER = 64;
const int MIN_SIZE_CLUSTER = 1;
using namespace std;

struct Task {
	int numberOfProcessors;
	int numberOfTacts;
};

struct Statistics {
	int tactsSleep;
	int numberTasksInQueue;
	int numberNotCompletedTasks;
	int numberTasks;
	int busyProcessorsOnTact;
	int numberOfCompletedTasks;
};


class Cluster {
	Queue<Task> queue;
	int numberOfProcessorsOnCluster;
	int* masOfBusyProcessors;
public:
	Cluster(int queueSize, int processorsNumbers) : queue(queueSize), 
		numberOfProcessorsOnCluster(processorsNumbers) { 
		if ((numberOfProcessorsOnCluster > MAX_SIZE_CLUSTER)
			|| (numberOfProcessorsOnCluster < MIN_SIZE_CLUSTER)){
			throw numberOfProcessorsOnCluster;
		}
		
		masOfBusyProcessors = new int[numberOfProcessorsOnCluster]

	}
	Statistics clusterJob(double q1, int processors, int time);
	bool checkEmptyOFCluster() {
		int count = 0;
		for (int i = 0; i < numberOfProcessorsOnCluster; i++) {
			if (masOfBusyProcessors[i] != 0) { count++; }
		}
		if (count == 0) { 
			return true;
		}
		return false;
	}
	~Cluster() {
		if (masOfBusyProcessors != nullptr) { delete[] masOfBusyProcessors; }
	}
};

#endif