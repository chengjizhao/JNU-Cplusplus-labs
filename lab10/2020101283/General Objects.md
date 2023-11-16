```mermaid
classDiagram
class GeneralObject {
  - x: int
  - y: float
  - z: char
}

class BaseObject {
  - x: int
}

Class DerivedObject <<Derived>> {
  - y: float
}

class VirtualObject {
  - x: int
  - foo(): void
}

Class DerivedVirtualObject <<Derived>> {
  - y: float
  - foo(): void
}

class BaseObjectWithVirtualFunctions {
  - x: int
  - foo(): void
  - bar(): void
}

class DerivedObjectWithVirtualFunctions <<Derived>> {
  - y: float
  - foo(): void
  - bar(): void
}

class BaseObjectWithMoreVirtualFunctions {
  - x: int
  - foo(): void
  - bar(): void
  - baz(): void
}

class DerivedObjectWithMoreVirtualFunctions <<Derived>> {
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

@enduml



```
