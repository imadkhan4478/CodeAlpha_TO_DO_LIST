#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string description;
    bool isCompleted;
};

void addTask(Task tasks[], int& taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full.\n";
        return;
    }
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, tasks[taskCount].description);
    tasks[taskCount].isCompleted = false;
    taskCount++;
    cout << "Task added successfully.\n";
}

void markTaskCompleted(Task tasks[], int taskCount) {
    cout << "Enter task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
    } else {
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << (tasks[i].isCompleted ? " [Completed]" : "") << '\n';
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        cout << "\nTo-Do List Application\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                markTaskCompleted(tasks, taskCount);
                break;
            case 3:
                viewTasks(tasks, taskCount);
                break;
            case 4:
                cout << "Exiting application.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
