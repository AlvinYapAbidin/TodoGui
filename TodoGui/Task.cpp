#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName)
{
    std::ofstream ostream(fileName);
    ostream << tasks.size(); // number of tasks

    for (const Task& task : tasks)
    {
        std::string description = task.description;
        std::replace(description.begin(), description.end(), ' ', '_'); // simplify building tasks

        ostream << '\n' << description << ' ' << task.done; // write current task to the file
    }
}

std::vector<Task> loadTasksFromFile(const std::string& fileName)
{
    if (!std::filesystem::exists(fileName))        // Check if the given text file exists or not
    {
        return std::vector<Task>();
    }

    std::vector<Task> tasks;
    std::ifstream istream(fileName);

    int n;
    istream >> n;
    
    for (int i = 0; i < n; i++)
    {
        std::string description;
        bool done;

        istream >> description >> done;
        std::replace(description.begin(), description.end(), '_', ' ');
        tasks.push_back(Task{ description, done });
    }

    return tasks;
}
