#include "TaskList.h"
#include <algorithm>
#include <wx/sharedptr.h> 

void TaskList::addTask(const wxString& title, const wxString& description) {
				wxSharedPtr<Task> taskCard(new Task(title, description));
    tasks.push_back(taskCard);
}

void TaskList::moveTask(const wxSharedPtr<Task>& task, TaskStatus newStatus) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [task](const wxSharedPtr<Task>& t) {
        return *t == *task;
    });
    
    if (it != tasks.end()) {
        (*it)->setStatus(newStatus);
    }
}
