```mermaid
classDiagram
    class Shape{
        +getArea(): double
        +getPerimeter(): double
    }
  
    class Circle {
        -radius: double
        +Circle(r: double)
        +getArea(): double
        +getPerimeter(): double
    }
    
    class Rectangle {
        -length: double
        -width: double
        +Rectangle(l: double, w: double)
        +getArea(): double
        +getPerimeter(): double
    }
    
    Shape <|-- Circle
    Shape <|-- Rectangle
