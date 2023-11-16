```mermaid
classDiagram
Class GeneralObject {
  - x: int
  - y: float
  - z: char
}

Class BaseObject {
  - x: int
}

Class DerivedObject <<Derived>> {
  - y: float
}

Class VirtualObject {
  - x: int
  - foo(): void
}

Class DerivedVirtualObject <<Derived>> {
  - y: float
  - foo(): void
}

Class BaseObjectWithVirtualFunctions {
  - x: int
  - foo(): void
  - bar(): void
}

Class DerivedObjectWithVirtualFunctions <<Derived>> {
  - y: float
  - foo(): void
  - bar(): void
}

Class BaseObjectWithMoreVirtualFunctions {
  - x: int
  - foo(): void
  - bar(): void
  - baz(): void
}

Class DerivedObjectWithMoreVirtualFunctions <<Derived>> {
  - y: float
  - foo(): void
  - bar(): void
  - baz(): void
}

GeneralObject --|> BaseObject
BaseObject --|> DerivedObject
VirtualObject --|> DerivedVirtualObject
BaseObjectWithVirtualFunctions --|> DerivedObjectWithVirtualFunctions
BaseObjectWithMoreVirtualFunctions --|> DerivedObjectWithMoreVirtualFunctions
```
