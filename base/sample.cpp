#include "Cluster.h"
#include <string>

using namespace std;
///

int main() {
	setlocale(LC_ALL, "Russian");
	system("title КЛАСТЕР");
	int time;
	int queue;
	double q1; 
	int processors;

	cout << "Число тактов: ";
	cin >> time;
	cout << "Размер очереди: ";
	cin >> queue;
	cout << "Интенсивность: ";
	cin >> q1;
	cout << "Число процессоров: ";
	cin >> processors;
 
	Cluster p(queue, processors);
	auto s = p.clusterJob(q1, processors, time);

	cout << "\n"; 
	cout << " __________________________________________________________________________" <<  endl;
	cout << "  Всего заданий: " << s.numberTasks << endl;
	cout << "  Всего заданий не выполненно: " << s.numberNotCompletedTasks << endl;
	cout << "  Средняя загруженность процессоров: " << s.busyProcessorsOnTact / time + 1 << " из " << processors << endl;
	cout << "  Число тактов простоя кластера: " << s.tactsSleep << endl;
	cout << "  Число выполняющихся задач: " << s.numberTasks - s.numberOfCompletedTasks - s.numberNotCompletedTasks - s.numberTasksInQueue << endl;
	cout << "  Число задач, оставшихся в очереди: " << s.numberTasksInQueue << endl;
	cout << "  Число успешно выполненных задач: " << s.numberOfCompletedTasks << endl;
	system("pause");


	return 0;
}