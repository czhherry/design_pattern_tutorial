#include <iostream>

using namespace std;

class IDrawStrategy {
public:
  virtual void draw() const = 0;
};

class Grapher {
public:
  Grapher(IDrawStrategy* drawStrategy = 0) : _drawStrategy(drawStrategy) {}
  
public:
  void drawShape() const;
  void setShape(IDrawStrategy* drawStrategy);
  
protected:
  IDrawStrategy* _drawStrategy;
};

void Grapher::drawShape() const {
  if (_drawStrategy)
      _drawStrategy->draw();
}

void Grapher::setShape(IDrawStrategy* drawStrategy) {
  _drawStrategy = drawStrategy;
}

class Triangle : public IDrawStrategy {
public:
  void draw() const;
};

void Triangle::draw() const {
  cout << "Draw Triangle" << endl;
}

class Circle : public IDrawStrategy {
public:
  void draw() const;
};

void Circle::draw() const {
  cout << "Draw Circle" << endl;
}

class Square : public IDrawStrategy {
public:
  void draw() const;
};

void Square::draw() const {
  cout << "Draw Square" << endl;
}

int main() {
  auto square = Square();
  Grapher grapher(&square);
  grapher.drawShape();
  
  auto circle = Circle();
  grapher.setShape(&circle);
  grapher.drawShape();
}