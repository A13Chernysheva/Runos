#include "maple/Runtime.hh"
#include "PipelineDiv.hh"

#include <math.h>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace runos;

using std::string;
using std::vector;
using std::list;
using std::set;
using std::ifstream;
using std::ofstream;
using std::stringstream;

void LittleApp::concatApp(LittleApp tail) {
    vector<string> tail_apps = tail.getApps();
    set<string> tail_fields = tail.getFields();

    for(string i: tail_apps) {
        apps.push_back(i);
    }

    for(string i: tail_fields) {
        if (fields.find(i) == fields.end()) {
            fields.insert(i);
        }
    }
}

bool LittleApp::operator==(LittleApp a) {
    return (apps == a.apps);
}

vector<string> LittleApp::getApps() {
    return apps;
}

set<string> LittleApp::getFields() {
    return fields;
}

uint8_t OneAction::balance() const {
    uint8_t max = 0, m;
    for(auto i = position; i < position + length; i++) {
        for(auto j = i + 1; j < position + length; j++) {
            m = abs((*i).getFields().size() - (*j).getFields().size());
            if (m > max)
                max = m;
        }
    }
    return max;
}

bool OneAction::operator<(const OneAction &a) const {
    if (symdif != a.symdif) 
        return (symdif < a.symdif);
    if (length != a.length)
        return (length > a.length);
    return (balance() > a.balance());
}

void Combiner::putActions(vector<OneAction> a){
    for(auto i: a) {
        actions.push_back(i);
    }
}

void Combiner::sort(){
    std::sort(actions.begin(), actions.end());
    reverse(actions.begin(), actions.end());
    delRepeat();
}

OneAction Combiner::getAction() {
    OneAction a = *actions.end();
    actions.pop_back();
    return a;
}

void Combiner::delRepeat(){
    vector<LittleApp> done;
    vector<LittleApp> done_curr;
    vector<LittleApp>::iterator j;
    uint8_t i = actions.size();
    do {
        i--;
        OneAction curr = actions[i];
        bool del = false;
        j = curr.position;
        while (j < curr.position + curr.length) {
            if (find(done.begin(), done.end(), *j) != done.end()) {
                del = true;
                break;
            }
            done_curr.push_back(*j);
            j++;
        }
        if (del) {
            actions.erase(actions.begin() + i);
        }
        else {
            done.insert(done.end(), done_curr.begin(), done_curr.end());
        }
        done_curr.clear();
    } while (i != 0);
}

bool Combiner::isEmpty() {
    return actions.empty();
}

Pipeline::Pipeline(string name) {
    ifstream file(name);
    if (file.is_open()) {
        while(!file.eof()) {
            string s, app_name, field_name;
            getline(file,s);
            if (!s.empty()) {
                stringstream ss(s);
                vector<string> a;
                set<string> f;
                ss >> app_name;
                a.push_back(app_name);
                while(ss >> field_name) {
                    f.insert(field_name);
                }
                LittleApp little_app(a, f);
                apps.push_back(little_app);
            }
        }
        file.close();
    }
}

vector<OneAction> Pipeline::symDifAllByk(uint8_t k){
    vector<OneAction> actions;
    for (auto i = apps.begin(); i <= apps.end() - k; i++) {
        actions.push_back(OneAction(i, k, symDif(i, k)));
    }
    return actions;
}

void Pipeline::applyAction(vector<LittleApp>::iterator position, uint8_t length){
    for(auto tail = position + 1; tail < position + length; tail++) {
        (*position).concatApp(*tail);
    }
    auto tail = position + 1;
    for(uint8_t i = 0; i < length - 1; i++) {
        auto ttail = tail;
        apps.erase(ttail);
    }
}

PacketMissPipeline Pipeline::getPipeline(PacketMissPipelineFactory pipeline_factory,
                                        SwitchConnectionImplPtr connection) {
    PacketMissPipeline new_pipeline;
    PacketMissPipelineTable curr;
    ofstream file("solution.txt", std::ios::app);
    if (file.is_open()) {
        for(auto little_app: apps) {
            vector<string> app = little_app.getApps();
            for(auto a: app) {
                for (uint8_t i = 0; i < pipeline_factory.size(); i++ ) {
                    if(pipeline_factory[i].first == a) {
                        file << pipeline_factory[i].first << " ";
                        curr.emplace_back(pipeline_factory[i].first,
                                          std::move(pipeline_factory[i].second(connection)));
                        break;
                    }
                }
            }
            file << '\n';
            new_pipeline.emplace_back(curr);
            curr.clear();
        }
        file.close();
    }
    return new_pipeline;
}


uint8_t Pipeline::symDif(vector<LittleApp>::iterator from, uint8_t N){
    set<string> a = (*from).getFields(), c;
    from++;
    for (uint8_t i = 1; i < N; i++) {
        set<string> b  = (*from).getFields();
        set_symmetric_difference( a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
        a = c;
        from++;
    }
    return a.size();
}