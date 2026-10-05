/*
    If our class manages resources manually (like dynamic memory, file handles, sockets), and
    we need to define one of the following special member functions, we usually need to define all five:
    In short: The Rule of Five says if your class manually manages resources, you must implement all five special member 
    functions to ensure safe and efficient behavior.

    Rule of Three (pre‑C++11): If we define destructor, copy constructor, or copy assignment, we usually need all three.
    Rule of Zero (modern C++ best practice): Prefer RAII types (std::vector, std::string, std::unique_ptr) so 
    we don’t need to manually implement any of these five functions at all.
    

Function	                    Purpose
Destructor	                    Releases the resource when the object goes out of scope.
Copy Constructor	            Creates a new object as a deep copy of another.
Copy Assignment Operator	    Assigns one object’s resources to another, handling self‑assignment.
Move Constructor	            Transfers ownership of resources from a temporary (rvalue) object.
Move Assignment Operator	    Transfers ownership during assignment from a temporary object.

*/