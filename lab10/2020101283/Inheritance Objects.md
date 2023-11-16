```mermaid

class GeneralObject {
  - x: int
  - y: float
  - z: char
}

class BaseObject {
  - x: int
}

class DerivedObject {
  - y: float
}

class VirtualObject {
  - x: int
  - foo(): void
}

class DerivedVirtualObject {
  - y: float
  - foo(): void
}

class BaseObjectWithVirtualFunctions {
  - x: int
  - foo(): void
  - bar(): void
}

class DerivedObjectWithVirtualFunctions {
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

class DerivedObjectWithMoreVirtualFunctions {
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
