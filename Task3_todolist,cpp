#include <iostream>
#include <vector>
#include <algorithm>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available. Add some tasks first.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << " - "
                          << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
            }
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 1 && static_cast<size_t>(taskIndex) <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[taskIndex - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index. Please enter a valid index.\n";
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && static_cast<size_t>(taskIndex) <= tasks.size()) {
            std::cout << "Task removed: " << tasks[taskIndex - 1].description << std::endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            std::cout << "Invalid task index. Please enter a valid index.\n";
        }
    }
};

int main() {
    ToDoManager todoManager;

    while (true) {
        std::cout << "\n===== ToDo List Manager =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice (1-5): ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore();  // Clear the newline character from the buffer
                std::getline(std::cin, taskDescription);
                todoManager.addTask(taskDescription);
                break;
            }
            case 2:
                todoManager.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> taskIndex;
                todoManager.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> taskIndex;
                todoManager.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Thank you for using the ToDo List Manager. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
