#pragma once

#include <vector>
#include <unordered_map>

#include <QUuid>

#include "porttype.h"
#include "nodedata.h"
#include "memory.h"

class Connection;
class NodeDataModel;

/**
 * @brief 包含连接的输入和输出连接的向量，存储用于对悬停连接作出反应的bool
 */
class NodeState
{
public:
    enum ReactToConnectionState
    {
        REACTING,
        NOT_REACTING
    };

public:
    NodeState(std::unique_ptr<NodeDataModel> const &model);

public:
    using ConnectionPtrSet =
    std::unordered_map<QUuid, Connection *>;

    //! Returns vector of connections ID.
    //! Some of them can be empty (null)
    std::vector<ConnectionPtrSet> const &getEntries(PortType) const;
    std::vector<ConnectionPtrSet> &getEntries(PortType);

    ConnectionPtrSet connections(PortType portType, PortIndex portIndex) const;

    void setConnection(PortType portType, PortIndex portIndex, Connection &connection);
    void eraseConnection(PortType portType, PortIndex portIndex, QUuid id);

    ReactToConnectionState reaction() const;
    PortType reactingPortType() const;

    NodeDataType reactingDataType() const;

    void setReaction(ReactToConnectionState reaction,
                     PortType reactingPortType = PortType::None,
                     NodeDataType reactingDataType = NodeDataType());

    bool isReacting() const;
    void setResizing(bool resizing);

    bool resizing() const;

private:
    std::vector<ConnectionPtrSet> _inConnections;
    std::vector<ConnectionPtrSet> _outConnections;

    ReactToConnectionState _reaction;
    PortType     _reactingPortType;
    NodeDataType _reactingDataType;

    bool _resizing;
};
