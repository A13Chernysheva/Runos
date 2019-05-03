#include "Mirror.hh"

#include "api/Packet.hh"
#include "api/PacketMissHandler.hh"
#include "oxm/openflow_basic.hh"

#include "Flow.hh"
#include "Controller.hh"
#include "SwitchConnection.hh"

REGISTER_APPLICATION(Mirror, {"controller", ""})

void Mirror::init(Loader* loader, const Config& config) {
    Controller* ctrl = Controller::get(loader);
    ctrl->registerHandler("mirror", [](SwitchConnectionPtr connection) {

        const auto ofb_in_port = oxm::in_port();

        return [=](Packet& pkt, FlowPtr, Decision decision) {
            if (connection->dpid() == 3) {
                if (pkt.test(ofb_in_port == 1)) {
                    return decision.unicast(10)
                                   .idle_timeout(std::chrono::seconds(60))
                                   .hard_timeout(std::chrono::minutes(30));
                }
            }
            return decision;
        };

    });
}