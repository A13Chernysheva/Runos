#pragma once
#include "Application.hh"
#include "Loader.hh"

class IPBlock: public Application {
    SIMPLE_APPLICATION(IPBlock, "ipblock");
public:
    void init(Loader* loader, const Config& config) override;
};