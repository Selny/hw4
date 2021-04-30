#include <iostream>

using namespace std;

class Computer {
    int object_ID;
    char* model;
    char* vendor;
    char* videocard;
    char* monitor;
    int cpu_hz;
    int core;
    int ram;
    int disk_size;
    bool isSSD;
public:
    static int id;
    
    Computer() = default;
    Computer(const int object_ID, const char* model, const char* vendor, const char* videocard, const char* monitor, const int cpu_hz, const int core, const int ram, const int disk_size, const bool isSSD) {
        ++id;
        SetObjectId(object_ID);
        SetModel(model);
        SetVendor(vendor);
        SetVideocard(videocard);
        SetMonitor(monitor);
        SetCpuHz(cpu_hz);
        SetCore(core);
        SetRam(ram);
        SetDiskSize(disk_size);
        SetIsSSD(isSSD);
    }
    
    int GetID() { return id; }
    int GetObjectID() { return object_ID; }
    char* GetModel() { return model; }
    char* GetVendor() { return vendor; }
    char* GetVideocard() { return videocard; }
    char* GetMonitor() { return monitor; }
    int GetCpuHz() { return cpu_hz; }
    int GetCore() { return core; }
    int GetRam() { return ram; }
    int GetDiskSize() { return disk_size; }
    bool GetIsSSD() { return isSSD; }
    
    void SetObjectId(int oID) { object_ID = oID; }
    void SetModel(const char* model) {
        if (model == nullptr) return;
        strcpy(this->model, model);
    }
    void SetVendor(const char* vendor) {
        if (vendor == nullptr) return;
        strcpy(this->vendor, vendor);
    }
    void SetVideocard(const char* videocard) {
        if (videocard == nullptr) return;
        strcpy(this->videocard, videocard);
    }
    void SetMonitor(const char* monitor) {
        if (monitor == nullptr) return;
        strcpy(this->monitor, monitor);
    }
    void SetCpuHz(int hz) { cpu_hz = hz; }
    void SetCore(int core) { this->core = core; }
    void SetRam(int ram) { this->ram = ram; }
    void SetDiskSize(int size) { disk_size = size; }
    void SetIsSSD(bool b) { isSSD = b; }
    
    friend ostream & operator << (ostream &out, const Computer &c);
    friend istream & operator >> (istream &in, Computer &c);
    
    ~Computer() {
        delete[] model;
        delete[] vendor;
        delete[] videocard;
        delete[] monitor;
    }
    
};

int Computer::id = 0;

ostream & operator << (ostream &out, const Computer &c) {
    out << "Id: " << c.id << endl;
    out << "Object id: " << c.object_ID << endl;
    out << "Model: " << c.model << endl;
    out << "Vendor: " << c.vendor << endl;
    out << "Videocard: " << c.videocard << endl;
    out << "Monitor: " << c.monitor << endl;
    out << "Cpu hz: " << c.cpu_hz << endl;
    out << "Core: " << c.core << endl;
    out << "Ram: " << c.ram << endl;
    out << "Disk size: " << c.disk_size << endl;
    out << "Is ssd: " << c.isSSD << endl;
    return out;
}

istream & operator >> (istream &in, Computer &c) {
    in >> c.id;
    in >> c.object_ID;
    in >> c.model;
    in >> c.vendor;
    in >> c.videocard;
    in >> c.monitor;
    in >> c.cpu_hz;
    in >> c.core;
    in >> c.ram;
    in >> c.disk_size;
    in >> c.isSSD;
    return in;
}

class ComputerStore {
    char* store_name;
    char* store_adress;
    Computer* computers;
public:
    
    ComputerStore() = default;
    ComputerStore(const char* sn, const char* sa, Computer cs) {
        SetStoreName(sn);
        SetStoreAdress(sa);
        SetComputers(&cs);
    }
    
    char* GetStoreName() { return store_name; }
    char* GetStoreAdress() { return store_adress; }
    
    void SetStoreName(const char* sn) {
        if(sn == nullptr) return;
        strcpy(store_name, sn);
    }
    void SetStoreAdress(const char* sa) {
        if(sa == nullptr) return;
        strcpy(store_adress, sa);
    }
    void SetComputers(Computer* cs) {
        computers = new Computer;
        computers->SetObjectId(cs->GetObjectID());
        computers->SetModel(cs->GetModel());
        computers->SetVendor(cs->GetVendor());
        computers->SetVideocard(cs->GetVideocard());
        computers->SetMonitor(cs->GetMonitor());
        computers->SetCpuHz(cs->GetCpuHz());
        computers->SetCore(cs->GetCore());
        computers->SetRam(cs->GetRam());
        computers->SetDiskSize(cs->GetDiskSize());
        computers->SetIsSSD(cs->GetIsSSD());
    }
    
    friend ostream & operator << (ostream &out, const ComputerStore &cs);
    friend istream & operator >> (istream &in, ComputerStore &cs);

    ~ComputerStore() {
        delete[] computers;
    }
    
};

ostream & operator << (ostream &out, const ComputerStore &cs) {
    out << "Store name: " << cs.store_name << endl;
    out << "Store adress: " << cs.store_adress << endl;
    return out;
}

istream & operator >> (istream &in, ComputerStore &cs) {
    in >> cs.store_name;
    in >> cs.store_adress;
    return in;
}

int main() {
    
    
    
    return 0;
}
