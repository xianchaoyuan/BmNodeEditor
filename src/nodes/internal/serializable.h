#pragma once

#include <QJsonObject>

/**
 * @brief ε―εΊεε
 */
class Serializable
{
public:
    virtual ~Serializable() = default;
    virtual QJsonObject save() const = 0;

    virtual void restore(QJsonObject const &/*p*/) {}
};
