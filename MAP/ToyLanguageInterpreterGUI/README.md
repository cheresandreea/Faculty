# ToyLanguageInterpreter
A custom "toy" language interpreter built on Java

## Used Concepts
+ Layered architecture
+ JavaFX for GUI
+ Encapsulation, interfaces, streams
+ MVC pattern

## Instructions:
+ Logical expressions
+ Arithmetical expressions
+ Relational expressions
+ Variable declaration & assignment
+ Printing
+ If
+ While
+ File opening, closing and reading
+ Fork (multi-threading)
+ Heap allocation, reading and writing

## Variables Types:
+ Bool
+ Int
+ String
+ Reference

## Functionalities
+ Storing instructions in execution stacks
+ Storing local variables in symbol tables
+ Storing BufferedReader objects into a file table used for file operations
+ Shared heap across all the states created by a program - allocation, reading, writing and garbage collector
+ Storing printing output in an output table
+ While forking, a new program state is being created with a unique ID
+ Program states: each state has a unique ID, a symbol table and an execution stack


![image](https://github.com/cheresandreea/Faculty/assets/115451911/e24a21e4-5f5b-4bd7-b4db-e6b0ef90f8d2)
