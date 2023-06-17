#ifndef QUADROCOPTER_H
#define QUADROCOPTER_H

#pragma once
#include <string>
#include "QuadroCopterModel.h"
#include "WayPointContainer.h"

class QuadroCopter final : public QuadroCopterModel {
private:
    std::string m_name;
    WayPoint m_home;

public:
    QuadroCopter(const std::string& name, const WayPoint& home, const std::string& model, double range);

    void configure(const std::string& model, double range) override;
    void add(const WayPoint& arg) override;
    double distance() const override;
    void print(bool contentFlag = true) const override;
};

#endif // QUADROCOPTER_H