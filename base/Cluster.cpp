#include "Cluster.h"
const int MAX_TACTS = 1000;
const int MIN_TACTS = 10;
//
Statistics Cluster::clusterJob(double q1, int processors, int runTime) {
	if ((runTime > MAX_TACTS) || (runTime < MIN_TACTS)) { throw runTime; }
	Statistics stat;
	stat.tactsSleep = 0;
	stat.numberTasksInQueue = 0;
	stat.busyProcessorsOnTact = 0;
	stat.numberTasks = 0;
	stat.numberOfCompletedTasks = 0;
	stat.numberNotCompletedTasks = 0;
	for (int i = 0; i < processors; i++) { masOfBusyProcessors[i] = 0; }
	int numberOfFreeProcessors = numberOfProcessorsOnCluster; 
	srand(time(NULL));
	for (int tact = 0; tact < runTime; tact++){
		double chanceOfTask = ((double)rand() / (RAND_MAX));
		if (chanceOfTask < q1){
			Task t;
			t.numberOfProcessors = rand() % processors + 1;
			t.numberOfTacts = rand() % runTime + 1;
			stat.numberTasks++;
			if (queue.isFull()) { stat.numberNotCompletedTasks++; }
			else { queue.push(t); }
		}
		if (queue.isEmpty() == false){
			int necessaryProcForTask;
			int necessaryTactForTask;
			necessaryProcForTask = queue.get().numberOfProcessors;
			necessaryTactForTask = queue.get().numberOfTacts;
			int remainingProcessorsForTask = necessaryProcForTask;
			if (numberOfFreeProcessors >= remainingProcessorsForTask) {
				for (int i = 0; i < processors; i++) {
					if ((masOfBusyProcessors[i] == 0) && (remainingProcessorsForTask > 0)){
						masOfBusyProcessors[i] = necessaryTactForTask;  
						remainingProcessorsForTask--; 
					}
					if (remainingProcessorsForTask == 0) { break;}
				}
				numberOfFreeProcessors = numberOfFreeProcessors - necessaryProcForTask; 
				queue.change(); 
			}
			if (checkEmptyOFCluster() == true) { stat.tactsSleep++; }
			for (int i = 0; i < processors; i++) {
				if (masOfBusyProcessors[i] > 0) {
					masOfBusyProcessors[i]--; 
					if (masOfBusyProcessors[i] == 0) { numberOfFreeProcessors++; }
				}
			}
			stat.busyProcessorsOnTact = stat.busyProcessorsOnTact + (processors - numberOfFreeProcessors);
		}
	}
	stat.numberTasksInQueue = queue.count(); 
	stat.numberOfCompletedTasks = stat.numberTasks - stat.numberTasksInQueue - stat.numberNotCompletedTasks;
	return stat;
}