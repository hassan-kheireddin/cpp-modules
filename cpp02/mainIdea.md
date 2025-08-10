This module teaches:

    Orthodox Canonical Form — the “Big Four” in C++ classes:

        Default constructor

        Copy constructor

        Copy assignment operator

        Destructor

    Ad-hoc polymorphism — mainly via operator overloading (so objects can use +, -, <<, etc.).

    Building a reusable class — starting simple and extending step-by-step.

    Encapsulation & immutability — using private members, constants, and controlled constructors.

    Applying math logic with custom types — in ex03, you use your own Fixed class for geometric checks.

You go from a minimal class → to constructors for multiple types → to full operator overloading → to applying it in a small geometry problem.
📝 Exercise-by-Exercise Idea
ex00 — My First Class in Orthodox Canonical Form

    Goal: Learn how to properly define a class with the “Big Four”.

    Concepts:

        Class definition split into .hpp and .cpp.

        Private data (int _value, static const int _fractionalBits).

        Implement default, copy, assignment, destructor.

        Basic getters/setters.

    Why: This sets the foundation for all later exercises — you practice correct object creation, copying, and destruction.

ex01 — Towards a more useful fixed-point number class

    Goal: Add functionality so your class can represent actual values (int and float).

    Concepts:

        Overloaded constructors: Fixed(int), Fixed(float).

        Type conversion methods: toFloat(), toInt().

        Overload << operator for printing.

    Why: You learn how to convert between internal fixed-point representation and normal int/float for I/O and computation.

ex02 — Now we’re talking

    Goal: Make the class behave like a number type with full arithmetic and comparison support.

    Concepts:

        Overload comparison operators: >, <, >=, <=, ==, !=.

        Overload arithmetic operators: +, -, *, /.

        Pre/post increment & decrement.

        min / max static methods for both mutable and const refs.

    Why: This introduces operator overloading deeply so your type can integrate with C++ syntax naturally, like built-in types.

ex03 — BSP

    Goal: Apply your Fixed class in a real-world type problem (geometry).

    Concepts:

        Create an immutable Point class (const Fixed x, y).

        Write a function bsp(a,b,c,point) to check if a point lies strictly inside a triangle.

        Use math (area method or barycentric coordinates) with your Fixed arithmetic.

    Why: This step connects your class work to actual problem solving, forcing you to use your own operators and conversions.

🎯 What you should be able to do after Module 02

    Write classes in Orthodox Canonical Form correctly.

    Use operator overloading to make custom types feel like built-in types.

    Create immutable objects using const members.

    Apply your own classes in calculations instead of relying on built-in primitives.

    Split and organize C++ code cleanly across .hpp and .cpp files.