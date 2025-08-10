1️⃣ Inheritance Basics

    What: How to make one class (ScavTrap) derive from another (ClapTrap) and reuse its code.

    Why: To avoid rewriting the same members/functions in each class.

    You learn:

        How to call the base constructor from a derived constructor.

        How derived classes can access base members (protected vs private).

        How to redefine (or override) methods in derived classes.

💡 This is the jump from standalone classes (Modules 00–02) to relationships between classes.
2️⃣ Method Overriding

    What: Re-implementing a base class function in the derived class with the same signature.

    Why: So each derived class can have specialized behavior.

    Example:

        ClapTrap::attack() → generic message.

        ScavTrap::attack() → “special” attack message.

    Takeaway: You see how the derived class can change the behavior but still share the interface.

3️⃣ Constructor & Destructor Order

    What: Which constructors/destructors run and in what order in inheritance chains.

    Why: So you understand object lifecycle in complex hierarchies.

    You notice:

        Base class constructor runs before derived constructor.

        Derived destructor runs before base destructor.

    Key skill: Always call the right base constructor to initialize inherited parts.

4️⃣ Virtual Functions & the Diamond Problem

    By ex03, you hit the diamond inheritance problem:

        DiamondTrap inherits from both ScavTrap and FragTrap, which both inherit from ClapTrap.

        Without virtual inheritance, you’d have two copies of ClapTrap inside DiamondTrap.

    You learn:

        Virtual inheritance prevents duplicate base subobjects.

        Ambiguity resolution: when two parent classes have the same base, you must tell the compiler which version to use.

        The using keyword can disambiguate method calls.

5️⃣ Multiple Inheritance

    What: A class inheriting from more than one base class.

    Why: Rare in real life, but good to understand for complex hierarchies.

    In this module:

        DiamondTrap takes methods/attributes from both ScavTrap and FragTrap.

        You learn how to combine features from multiple sources.

    Challenge:

        Deciding which base class’s behavior to keep when both define the same method or attribute.

6️⃣ Object Identity in Inheritance

    DiamondTrap has two names:

        Its own DiamondTrap::name

        The ClapTrap::name (set to DiamondTrap_name + "_clap_name")

    Why: To show how base and derived can store different state for different purposes.

    whoAmI() method illustrates referencing both.