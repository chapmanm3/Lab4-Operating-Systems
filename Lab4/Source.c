#include <stdio.h>
#pragma warning(disable:4996)


struct Process {
	char iD;
	int arrive, service, start, finish, wait, turnaround, done;
}proccess[5];

int processesDone() {
	for (int i = 0; i <= 5; i++) {
		if (proccess[i].done == 0)
			return 0;
	}
	return 1;
}

void printProcesses() {

	//std::cout << std::setw(6) << "Process" << std::setw(6) << "Arrival Time" << std::setw(6) << "Service Time" << std::setw(6) << "Start Time" << std::setw(6) << "Finish Time" << std::setw(6) << "Wait Time" << std::setw(6) << "Turnaround Time \n";
	printf("Process\tArrival Time\tService Time\tStart Time\tFinish Time\tWait Time\tTurnaround Time\n");
	for (int i = 0; i < 5; i++) {
		printf("%-7c %-15d %-15d %-15d %-15d %-15d %-15d\n", proccess[i].iD, proccess[i].arrive, proccess[i].service, proccess[i].start, proccess[i].finish, proccess[i].wait, proccess[i].turnaround);
	}
}

int main() {

	FILE *fp;
	fp = fopen("Processes.txt", "r");
	char temp = ' ';
	int count = 0;
	int currentTime = 0;

	//read in all the processes from the text file
	while (fscanf(fp, "%c", &temp) != EOF) {
		proccess[count].iD = temp;
		fscanf(fp, "%c", &temp);
		fscanf(fp, "%c", &temp);
		proccess[count].arrive = (temp - '0');
		fscanf(fp, "%c", &temp);
		fscanf(fp, "%c", &temp);
		proccess[count].service = (temp - '0');
		fscanf(fp, "%c", &temp);
		count++;
	}

	//First Come First Serve Code
	for (int i = 0; i <= 5; i++) {
		proccess[i].start = currentTime;
		proccess[i].wait = currentTime;
		currentTime += proccess[i].service;
		proccess[i].finish = currentTime;
		proccess[i].turnaround = proccess[i].finish - proccess[i].arrive;
	}

	printf("First Come First Serve: \n");
	printProcesses();

	//Shortest Process Next



	return 0;
}