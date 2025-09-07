#include "todopp_interface.h"

TodoPPInterface::TodoPPInterface(QObject *parent)
    : QObject{parent}
{

}

QString TodoPPInterface::myAppName() const
{
    return m_myAppName;
}

void TodoPPInterface::setmyAppName(const QString &newMyAppName)
{
    if (m_myAppName == newMyAppName)
        return;
    m_myAppName = newMyAppName;
    emit myAppNameChanged();
}
