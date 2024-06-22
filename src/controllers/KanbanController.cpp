#include "KanbanController.h"

KanbanController::KanbanController(TaskList& model, KanbanBoard& view) : m_model(model), m_view(view) {

}

void KanbanController::addTask(const wxString& title, const wxString& description) {
				m_model.addTask(title, description);
				m_view.update(); // update view
}

void KanbanController::moveTask(wxSharedPtr<Task>& task, TaskStatus newStatus) {
				m_model.moveTask(task, newStatus);
				m_view.update();
}