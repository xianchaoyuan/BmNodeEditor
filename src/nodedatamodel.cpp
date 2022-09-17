#include "nodedatamodel.h"
#include "stylecollection.h"

NodeDataModel::NodeDataModel()
    : _nodeStyle(StyleCollection::nodeStyle())
{
    // Derived classes can initialize specific style here
}

QJsonObject NodeDataModel::save() const
{
    QJsonObject modelJson;
    modelJson["name"] = name();

    return modelJson;
}

NodeStyle const &NodeDataModel::nodeStyle() const
{
    return _nodeStyle;
}

void NodeDataModel::setNodeStyle(NodeStyle const &style)
{
    _nodeStyle = style;
}
