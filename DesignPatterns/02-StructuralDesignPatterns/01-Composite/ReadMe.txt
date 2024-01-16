Reference: https://www.geeksforgeeks.org/composite-method-software-design-pattern/

It allows you to have a tree structure.
Composite: Composite means it can have other objects below it.
Leaf: leaf means it has no objects below it.

Advantages of the Composite Design Pattern:
Hierarchical Structure: You can create tree-like structures where both individual objects and composite objects (objects that contain other objects) can be treated uniformly.
Simplified Client Code: Clients (code that uses the composite structure) can work both with individual objects and composites without needing to know the difference. 
This simplifies client code, making it more intuitive and easier to maintain.
Flexibility: The pattern allows you to add and remove objects in the hierarchy without affecting the client code
Scalability: You can easily create more complex structures by nesting composites within composites, making it a scalable solution for modeling part-whole hierarchies.

Disadvantages of Composite Design Pattern
Complex Implementation: Implementing the Composite Pattern can be more complex compared to a non-composite approach. 
It involves creating a common interface for both individual objects and compositions, which can make the code more intricate.


