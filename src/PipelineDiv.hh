#include "maple/Runtime.hh"
#include "SwitchConnection.hh"
#include "OFMsgUnion.hh"

using namespace fluid_base;
using namespace runos;

using std::string;
using std::vector;
using std::list;
using std::set;

typedef std::vector< std::pair<std::string, PacketMissHandler> >
    PacketMissPipelineTable;
typedef std::vector< PacketMissPipelineTable >
    PacketMissPipeline;
typedef std::vector< std::pair<std::string, PacketMissHandlerFactory> >
    PacketMissPipelineFactory;

// --------------------from-Controller.cc------------------
class SwitchConnectionImpl : public SwitchConnection {
public:
    SwitchConnectionImpl(OFConnection* ofconn_, uint64_t dpid)
        : SwitchConnection(ofconn_, dpid)
    { }

    void replace(OFConnection* ofconn_)
    { m_ofconn = ofconn_; }
};

typedef std::shared_ptr<SwitchConnectionImpl> SwitchConnectionImplPtr;
typedef std::weak_ptr<SwitchConnectionImpl> SwitchConnectionImplWeakPtr;
//---------------------------------------------------------

/**
    This class discrabes a new application, which appear on every new step.
    It contain sequence of successive applications, which we will write in single table, 
    and it's main fields.
*/
class LittleApp {
    vector<string> apps;
    set<string> fields;

public:
    LittleApp(vector<string> a, set<string> f): apps(a), fields(f) {}

    void concatApp(LittleApp tail);
    bool operator==(LittleApp a);

    vector<string> getApps();
    set<string> getFields();
};

/**
    Discrabes one simmetrical difference for length applications from position.
*/
struct OneAction {
    vector<LittleApp>::iterator position;
    uint8_t length;
    uint8_t symdif;

    OneAction(vector<LittleApp>::iterator p, uint8_t l, uint8_t s): 
                position(p), length(l), symdif(s) {}

    uint8_t balance() const;
    bool operator<(const OneAction &a) const;
};

/**
    Content all actions, which we want to apply on this step. We can add actions, sort them
    by their symdif and length and take by one action from the beginnig.
*/
class Combiner {
    vector<OneAction> actions;

public:
    void putActions(vector<OneAction> a);
    void sort();

    OneAction getAction();

    bool isEmpty();

private:
    // We delite actions, which use already involved applications
    void delRepeat();
};

/**
    This class represents pipeline, where their applications grouped
    by table numbers to be recorded.

*/
class Pipeline {
    vector<LittleApp> apps;

public:
    Pipeline(string name);

    // Apply symmetric difference to every N elements from Pipeline, and give the result
    vector<OneAction> symDifAllByk(uint8_t k);

    // Combine applications
    void applyAction(vector<LittleApp>::iterator position, uint8_t length);

    // Transformed apps from class Pipeline presentation to maple presentation
    PacketMissPipeline getPipeline(PacketMissPipelineFactory pipeline_factory,
                                    SwitchConnectionImplPtr connection);

private:
    // Apply symmetric difference to N elements starting with from
    uint8_t symDif(vector<LittleApp>::iterator from, uint8_t N);
};
