#include <iostream>

class Quackable {
public:
  virtual void quack() = 0;
};

class Goose {
public:
  void honk() {
    std::cout << "Honk" << std::endl;
  }
};

class GooseAdapter : public Quackable {
private:
  Goose goose;

public:
  GooseAdapter(Goose& goose) : goose(goose) {}

  void quack() override {
    goose.honk();
  }
};

class MallardDuck : public Quackable {
public:
  void quack() override {
    std::cout << "Quack" << std::endl;
  }
};

class RedheadDuck : public Quackable {
public:
  void quack() override {
    std::cout << "Quack" << std::endl;
  }
};

class DuckCall : public Quackable {
public:
  void quack() override {
    std::cout << "Kwak" << std::endl;
  }
};

class RubberDuck : public Quackable {
public:
  void quack() override {
    std::cout << "Squeak" << std::endl;
  }
};

class DuckSimulator {
public:
  void simulate() {
    MallardDuck mallardDuck;
    RedheadDuck redheadDuck;
    RubberDuck rubberDuck;
    DuckCall duckCall;

    Goose goose;
    GooseAdapter gooseDuck(goose);

    std::cout << "\n== duck simulator with goose ==" << std::endl;

    simulate(&mallardDuck);
    simulate(&redheadDuck);
    simulate(&rubberDuck);
    simulate(&duckCall);
    simulate(&gooseDuck);
  }

private:
  void simulate(Quackable *quackable) {
    quackable->quack();
  }
};

int main() {
  DuckSimulator duckSimulator;
  duckSimulator.simulate();

  return 0;
}
