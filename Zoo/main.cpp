#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Animal {
protected:
    std::string name;
    int age;
    double weight;

public:
    Animal(std::string name, int age, double weight) : name(name), age(age), weight(weight) {}

    void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }
};

class Mammal : public Animal {
protected:
    bool isHerbivore;

public:
    Mammal(std::string name, int age, double weight, bool isHerbivore) : Animal(name, age, weight), isHerbivore(isHerbivore) {}

    void display() const {
        Animal::display();
        std::cout << "Herbivore: " << (isHerbivore ? "Yes" : "No") << std::endl;
    }
};

class Reptile : public Animal {
protected:
    bool isVenomous;

public:
    Reptile(std::string name, int age, double weight, bool isVenomous) : Animal(name, age, weight), isVenomous(isVenomous) {}

    void display() const {
        Animal::display();
        std::cout << "Venomous: " << (isVenomous ? "Yes" : "No") << std::endl;
    }
};

class CarnivoreMammal : public Mammal {
protected:
    bool isPredator;

public:
    CarnivoreMammal(std::string name, int age, double weight, bool isPredator) : Mammal(name, age, weight, false), isPredator(isPredator) {}

    void display() const {
        Mammal::display();
        std::cout << "Predator: " << (isPredator ? "Yes" : "No") << std::endl;
    }
};

class Zoo {
private:
    std::vector<std::unique_ptr<Animal>> animals;

public:
    void addAnimal(std::unique_ptr<Animal> animal) {
        animals.push_back(std::move(animal));
    }

    void displayAnimals() const {
        for (const auto& animal : animals) {
            animal->display();
            std::cout << std::endl;
        }
    }
};

int main() {
    Zoo zoo;

    auto elephant = std::make_unique<Mammal>("Elephant", 10, 5000.0, true);
    auto snake = std::make_unique<Reptile>("Snake", 3, 10.0, true);
    auto lion = std::make_unique<CarnivoreMammal>("Lion", 5, 200.0, true);

    zoo.addAnimal(std::move(elephant));
    zoo.addAnimal(std::move(snake));
    zoo.addAnimal(std::move(lion));

    zoo.displayAnimals();

    return 0;
}
