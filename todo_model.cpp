#include "todo_model.h"

TodoModel::TodoModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_todo.setFileImmediateFlush();
}

int TodoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_todo.getAllTasks().size();
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_todo.getAllTasks().size()) {
        const TodoPP::Task& task {m_todo.getAllTasks()[index.row()]};
        switch((Role) role) {
        case TaskDesc:
            return QString::fromStdString(static_cast<std::string>(task.getDesc()));
        case TaskPriority:
            if(task.getPriority())
            {
                // return QString::fromStdString(static_cast<std::string>(*task.getPriority()));
                return QString(QChar(*task.getPriority()));
            }
            break;
        case TaskIndex:
            // return index.row();
            return task.getId();
            // return QString::fromStdString(static_cast<std::string>(task.getPriority()));
        // case TaskCreationDate:
        //     return task.getCreationDate();
        case IsTaskCompleted:
            return task.isCompleted();
        }
    }

    return {};

}
QHash<int, QByteArray> TodoModel::roleNames() const
{
    QHash<int, QByteArray> result;

    result[TaskDesc] = "description";
    result[TaskPriority] = "priority";
    result[TaskIndex] = "index";
    // result[TaskCreationDate] = "taskCreationDate";
    result[IsTaskCompleted] = "completed";

    return result;

}

QString TodoModel::myAppName() const
{
    return m_myAppName;
}

void TodoModel::setmyAppName(const QString &newMyAppName)
{
    if (m_myAppName == newMyAppName)
        return;
    m_myAppName = newMyAppName;
    emit myAppNameChanged();
}

void TodoModel::toggleCompletion(const int index)
{
    // beginMoveRows();
    layoutAboutToBeChanged();
    // beginResetModel();
    // changePersistentIndexList(0, m_todo.getAllTasks().size());
    // auto todo = m_todo.getAllTasks();
    auto task = m_todo.getTaskById(index);
    task->toggleCompleted();
    // modelReset();
    // endResetModel();
    layoutChanged();
    // m_todo.add("New Task");
}

void TodoModel::deleteTask(const int id)
{
    layoutAboutToBeChanged();
    m_todo.remove(id);
    layoutChanged();
}

void TodoModel::addTask(const QString &text)
{
    beginResetModel();
    m_todo.add(text.toStdString());
    endResetModel();
}
