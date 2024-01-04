class Shape {
public:
    virtual void draw() const = 0; 
};

class Circle : public Shape {
public:
    void draw() const override {
    }
};

int main() {
    Circle c;
    c.draw(); 
    return 0;
}