#include <iostream>
#include <string>
#include <vector>
#include <memory>

class ElectronicDevice {
protected:
    std::string brand;
    std::string model;

public:
    ElectronicDevice(std::string brand, std::string model) : brand(brand), model(model) {}

    void display() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
    }
};

class Smartphone : public ElectronicDevice {
protected:
    int storageCapacity;

public:
    Smartphone(std::string brand, std::string model, int storageCapacity) : ElectronicDevice(brand, model), storageCapacity(storageCapacity) {}

    void display() const {
        ElectronicDevice::display();
        std::cout << "Storage capacity: " << storageCapacity << " GB" << std::endl;
    }
};

class Laptop : public ElectronicDevice {
protected:
    int ramSize;

public:
    Laptop(std::string brand, std::string model, int ramSize) : ElectronicDevice(brand, model), ramSize(ramSize) {}

    void display() const {
        ElectronicDevice::display();
        std::cout << "RAM size: " << ramSize << " GB" << std::endl;
    }
};

class GamingLaptop : public Laptop {
protected:
    std::string gpuModel;

public:
    GamingLaptop(std::string brand, std::string model, int ramSize, std::string gpuModel) : Laptop(brand, model, ramSize), gpuModel(gpuModel) {}

    void display() const {
        Laptop::display();
        std::cout << "GPU model: " << gpuModel << std::endl;
    }
};

class Smartwatch : public ElectronicDevice {
protected:
    bool hasGPS;

public:
    Smartwatch(std::string brand, std::string model, bool hasGPS) : ElectronicDevice(brand, model), hasGPS(hasGPS) {}

    void display() const {
        ElectronicDevice::display();
        std::cout << "GPS: " << (hasGPS ? "Yes" : "No") << std::endl;
    }
};

class Store {
private:
    std::vector<std::unique_ptr<ElectronicDevice>> devices;

public:
    void addDevice(std::unique_ptr<ElectronicDevice> device) {
        devices.push_back(std::move(device));
    }

    void displayDevices() const {
        for (const auto& device : devices) {
            device->display();
            std::cout << std::endl;
        }
    }
};

int main() {
    Store store;

    auto smartphone = std::make_unique<Smartphone>("Apple", "iPhone 13", 256);
    auto laptop = std::make_unique<Laptop>("Dell", "XPS 15", 16);
    auto gamingLaptop = std::make_unique<GamingLaptop>("Asus", "ROG Strix", 32, "NVIDIA GeForce RTX 3080");
    auto smartwatch = std::make_unique<Smartwatch>("Samsung", "Galaxy Watch 4", true);

    store.addDevice(std::move(smartphone));
    store.addDevice(std::move(laptop));
    store.addDevice(std::move(gamingLaptop));
    store.addDevice(std::move(smartwatch));

    store.displayDevices();

    return 0;
}
