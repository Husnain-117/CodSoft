#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task> &taskList)
{
    Task newTask;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view tasks in the list
void viewTasks(const vector<Task> &taskList)
{
    cout << "Task List:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i)
    {
        cout << "[" << i + 1 << "] " << (taskList[i].completed ? "[X] " : "[ ] ") << taskList[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task> &taskList)
{
    size_t taskIndex;
    cout << "Enter the task number to mark as completed: ";
    while (!(cin >> taskIndex) || taskIndex <= 0 || taskIndex > taskList.size())
    {

        cout << "Invalid input. Enter a valid task number: ";
    }

    taskList[taskIndex - 1].completed = true;
    cout << "Task marked as completed!" << endl;
}

// Function to remove a task from the list
void removeTask(vector<Task> &taskList)
{
    size_t taskIndex;
    cout << "Enter the task number to remove: ";
    while (!(cin >> taskIndex) || taskIndex <= 0 || taskIndex > taskList.size())
    {

        cout << "Invalid input. Enter a valid task number: ";
    }

    taskList.erase(taskList.begin() + taskIndex - 1);
    cout << "Task removed successfully!" << endl;
}

// Function to save tasks to a file
void saveToFile(const vector<Task> &taskList, const string &fileName)
{
    ofstream file(fileName);
    if (file.is_open())
    {
        for (const auto &task : taskList)
        {
            file << task.description << "," << task.completed << endl;
        }
        cout << "Tasks saved to " << fileName << " successfully!" << endl;
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

// Function to load tasks from a file
void loadFromFile(vector<Task> &taskList, const string &fileName)
{
    ifstream file(fileName);
    if (file.is_open())
    {
        taskList.clear();
        Task task;
        string line;
        while (getline(file, line))
        {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos)
            {
                task.description = line.substr(0, commaPos);
                task.completed = (line.substr(commaPos + 1) == "1");
                taskList.push_back(task);
            }
        }
        cout << "Tasks loaded from " << fileName << " successfully!" << endl;
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}

int main()
{
    vector<Task> taskList;
    int choice;
    string fileName = "tasks.txt";

    loadFromFile(taskList, fileName);

    do
    {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Save Tasks to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";

        while (!(cin >> choice) || choice < 1 || choice > 6)
        {

            cout << "Invalid input. Enter a number between 1 and 6: ";
        }

        switch (choice)
        {
        case 1:
            addTask(taskList);
            break;
        case 2:
            viewTasks(taskList);
            break;
        case 3:
            markCompleted(taskList);
            break;
        case 4:
            removeTask(taskList);
            break;
        case 5:
            saveToFile(taskList, fileName);
            break;
        case 6:
            cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}
