#include "IPBlock.hh"

#include "api/Packet.hh"
#include "api/PacketMissHandler.hh"
#include "oxm/openflow_basic.hh"

#include "Flow.hh"
#include "Controller.hh"
#include "SwitchConnection.hh"

REGISTER_APPLICATION(IPBlock, {"controller", ""})

void IPBlock::init(Loader* loader, const Config& config) {
    Controller* ctrl = Controller::get(loader);
    ctrl->registerHandler("ipblock", [](SwitchConnectionPtr connection) {

        const auto ofb_eth_type = oxm::eth_type();

        return [=](Packet& pkt, FlowPtr, Decision decision) {

            auto eth_type = pkt.load(ofb_eth_type); ///??????? Без этой строчки не работает, не понятно почему

            if (pkt.test(ofb_eth_type == 0x0800) and (connection->dpid() == 1)) {

                if (pkt.test(oxm::ipv4_src() == "10.0.0.1")) {
                    return decision.drop().return_();
                }
            }
            return decision;
        };

    });
}