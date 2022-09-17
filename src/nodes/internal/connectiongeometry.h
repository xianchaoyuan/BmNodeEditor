#pragma once

#include <QPointF>
#include <QRectF>

#include "porttype.h"

class ConnectionGeometry
{
public:
    ConnectionGeometry();

public:
    QPointF const &getEndPoint(PortType portType) const;

    void setEndPoint(PortType portType, QPointF const &point);
    void moveEndPoint(PortType portType, QPointF const &offset);

    QRectF boundingRect() const;

    std::pair<QPointF, QPointF> pointsC1C2() const;

    QPointF source() const { return _out; }
    QPointF sink() const { return _in; }

    double lineWidth() const { return _lineWidth; }

    bool hovered() const { return _hovered; }
    void setHovered(bool hovered) { _hovered = hovered; }

private:
    // local object coordinates
    QPointF _in;
    QPointF _out;

    //int _animationPhase;
    double _lineWidth;
    bool _hovered;
};
