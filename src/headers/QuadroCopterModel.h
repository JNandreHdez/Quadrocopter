#pragma once
#include <string>
#include "WayPointContainer.h"

class QuadroCopterModel {
protected:
    std::string m_model;
    double m_range{ 0 };
    WayPointContainer m_container;
    virtual void configure(const std::string& model, double range) = 0;

public:
    virtual void add(const WayPoint& arg) = 0;
    virtual void print(bool contentFlag = true) const = 0;
    virtual double distance() const = 0;
};