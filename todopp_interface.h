#ifndef TODOPP_INTERFACE_H
#define TODOPP_INTERFACE_H

#include <QObject>

class TodoPPInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myAppName READ myAppName WRITE setmyAppName NOTIFY myAppNameChanged FINAL)

public:
    TodoPPInterface(QObject *parent = nullptr);

    QString myAppName() const;
    // QVector var;

public slots:

    void setmyAppName(const QString &newMyAppName);

signals:
    void myAppNameChanged();

private:
    QString m_myAppName;
};

#endif // TODOPP_INTERFACE_H
