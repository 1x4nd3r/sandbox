#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void printTasks(string tasks[], int taskCount)
{
    cout << "\n--- TO DO ---\n";
    for (int i = 0; i < taskCount; i++)
    {
        cout << i << ". " << tasks[i] << '\n';
    }
}

int main()
{

    string tasks[10] = {""};
    int taskCount = 0;

    int option = -1;
    while (option != 0)
    {
        system("cls");
        cout << "[1] New Task\n";
        cout << "[2] View Tasks\n";
        cout << "[3] Complete Task\n";
        cout << "[0] Exit\n";

        cin >> option;
        switch (option)
        {
        case 1:
        {
            if (taskCount >= 10){
                system("cls");
                cout << "You already have 10 tasks, please remember to rest too.\n";
            } else
            {
                system("cls");
                cout << "New Task Label: ";
                cin.ignore();
                getline(cin, tasks[taskCount]);
                taskCount++;
            }
            break;
        }
        case 2:
        {
            system("cls");
            printTasks(tasks, taskCount);
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            int completedTask = 0;
            printTasks(tasks, taskCount);
            cout << "\nEnter a task to complete: ";
            cin >> completedTask;
            if (completedTask < 0 || completedTask > taskCount)
            {
                cout << "Task does not exist.";
                break;
            }
            for (int i = completedTask; i < taskCount; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid command.";
            break;
        }
    }
}