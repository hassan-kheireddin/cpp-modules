The class must not be instantiable (likely means a private or deleted constructor).
It means cannot create projects from it so to achieve that you should make the constructor private or deleted, in our case private.



















static cast:

    static_cast is the “normal” C++ cast — it handles conversions that the compiler can check at compile time. It’s the most common cast you’ll use in well-structured C++ code.

    double pi = 3.14;
    int x = static_cast<int>(pi); // x = 3

Dynamic cast:

    dynamic_cast is used for safe type conversions in class hierarchies (polymorphism).
    Unlike static_cast, it does runtime checking to ensure the cast is valid.

    Safe downcasting (base → derived)

    If you have a Base* but aren’t sure what the actual object is, dynamic_cast checks at runtime.
    If it fails:
    Returns nullptr for pointers.
    Throws std::bad_cast for references.

    class Base { public: virtual ~Base() {} };  // must have at least 1 virtual function
    class Derived : public Base {};

    Base* b1 = new Base();
    Derived* d1 = dynamic_cast<Derived*>(b1); // fails → d1 = nullptr

    Base* b2 = new Derived();
    Derived* d2 = dynamic_cast<Derived*>(b2); // works → d2 points to Derived

    Base class must be polymorphic (have at least one virtual function), otherwise dynamic_cast won’t compile.
    Runtime cost is higher than static_cast, since it checks type information.
    Works only with pointers and references (not with values).


reinterpret_cast

    This is the most low-level cast in C++.
    It tells the compiler: “treat this block of bits as if it were another type.”
    It does no safety checks and usually results in machine-level reinterpretation.

    Casting between pointer and integer
    Sometimes needed in low-level or system programming (e.g., working with memory addresses).

    int* ip = new int(100);
    uintptr_t addr = reinterpret_cast<uintptr_t>(ip); // pointer → integer
    int* ip2 = reinterpret_cast<int*>(addr);          // integer → pointer

const cast:

    this cast is used to add or remove const (or volatile) qualifiers from a type.
    It’s the only C++ cast that can change an object’s constness.







Serialization = Converting an in-memory object into a form that can be stored (e.g., in a file) or transmitted (e.g., over a network).

Deserialization = Reconstructing the object back from that stored/transmitted form.

Simple Pointer Serialization
    In low-level C++, sometimes serialization can mean:
    Convert a pointer (memory address) into an integer type → store/transmit it.
    Convert the integer back into the original pointer type.
    This is not object serialization (like JSON), but pointer serialization for memory handling.