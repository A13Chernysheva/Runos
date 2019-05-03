#pragma once
#include "Application.hh"
#include "Loader.hh"

class Mirror: public Application {
    SIMPLE_APPLICATION(Mirror, "mirror");
public:
    void init(Loader* loader, const Config& config) override;
};