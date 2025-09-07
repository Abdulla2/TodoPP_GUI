#ifndef TODO_MODEL_H
#define TODO_MODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "todo.h"

class TodoModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString myAppName READ myAppName WRITE setmyAppName NOTIFY myAppNameChanged FINAL)

public:
    enum Role {
        TaskDesc = Qt::UserRole + 1,
        TaskPriority,
        TaskIndex,
        // TaskCreationDate,
        IsTaskCompleted,
    };

    explicit TodoModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    QString myAppName() const;

public slots:
    void setmyAppName(const QString &newMyAppName);
    void toggleCompletion(const int id);
    void deleteTask(const int id);
    void addTask(const QString& text);

signals:
    void myAppNameChanged();

    // QAbstractItemModel interface
public:

private:
    TodoPP::Todo m_todo{"/home/abdulla/cpp_learn/projects/todo_test.txt"};
    QString m_myAppName{"The Model is Working?"};

};

#endif // TODO_MODEL_H
