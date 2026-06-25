/*
    Function that may or may not return a value there we use return type as std::optional<T>
    std::optional<T> → A wrapper that may contain a value of type T or be empty.
    has_value() → Checks if a value is present.
    value() / *opt → Access the contained value (throws if empty).
    value_or(default) → Returns the value if present, otherwise returns a default.
    std::nullopt → Represents an empty optional.

    Commonly used in parsing, lookups, or functions that may fail to produce a result.
*/ 

#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> findUserName(int id){
    if(id == 1)
        return "Rajesh";
    else
        return std::nullopt;
}

int main(){

    std::optional<int> maybeNumber; //
    //std::cout<<"Number: "<< maybeNumber<<std::endl;
    maybeNumber = 40;
    if(maybeNumber.has_value()){
        std::cout<<"Number: "<< maybeNumber.value()<<std::endl;
    }
    
    auto name = findUserName(1);
    if(name){
        std::cout<<"User name: "<<*name<<std::endl;
    }else{
        std::cout<<"No user found\n";
    }
    
    auto missing = findUserName(2);
    std::cout << "Result: " << missing.value_or("Unknown") << std::endl;
    
    return 0;
}