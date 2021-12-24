#include <iostream>

#include "input_handler.h"

void InputHandler::handle() {
    int instruction;

    while (isContinued)
    {
        printEditorInstructions();

        std::cin >> instruction;

        handleEditorInstructions(instruction);
    }
}

void InputHandler::printEditorInstructions() {
    std::cout << "Please enter the following instruction number number to start building:" << std::endl;
    std::cout << "1. 'add circle': to add a circle" << std::endl;
    std::cout << "2. 'add rectangle': to add a rectangle" << std::endl;
    std::cout << "3. 'add triangle': to add a triangle" << std::endl;
    std::cout << "4. 'add compound': to add a compound" << std::endl;
    std::cout << "5. 'save': output shape to file" << std::endl;
    std::cout << "6. 'exit': to exit the program" << std::endl;
}

void InputHandler::handleEditorInstructions(int instruction) {
    switch (instruction)
    {
    case 1:
        addCircle();
        break;
    case 2:
        addRectangle();
        break;
    case 3:
        addTriangle();
        break;
    case 4:
        handleCompoundInstructions(instruction);
        break;
    case 5:
        printCompoundInstructions();
        break;
    case 6:
        isContinued = false;
        builder->reset();
        break;
    default:
        std::cout << "Invalid instruction. Please try again." << std::endl;
        handle();
        break;
    }
}

void InputHandler::save() {

}

void InputHandler::addCircle() {
    double radius;

    std::cout << "Please enter the information of circle:\nRadius of circle:";
    std::cin >> radius;
       
    try{
        builder->buildCircle(radius);
    }catch (const char* e) {
        std::cout << "Invalid argument. Please try again."<< std::endl;
    }
}

void InputHandler::addRectangle() {
    double height, width;

    std::cout << "Please enter the information of retangle:" << std::endl;
    std::cout << "Width of rectangle:";
    std::cin >> width;
    std::cout << "Height of rectangle:";
    std::cin >> height;
       
    try{
        builder->buildRectangle(height, width);
    }catch (const char* e) {
        std::cout << "Invalid argument. Please try again."<< std::endl;
    }
}

void InputHandler::addTriangle() {
    double x1, y1, x2, y2;

    std::cout << "Please enter the information of triangle:" << std::endl;
    std::cout << "X1 of triangle:";
    std::cin >> x1;
    std::cout << "Y1 of triangle:";
    std::cin >> y1;
    std::cout << "X2 of triangle:";
    std::cin >> x2;
    std::cout << "Y2 of triangle:";
    std::cin >> y2;
       
    try{
        builder->buildTriangle(x1, y1, x2, y2);
    }catch (const char* e) {
        std::cout << "Invalid argument. Please try again."<< std::endl;
    }
}

void InputHandler::printCompoundInstructions() {
    std::string result = builder->getShape()->info();
    std::cout << result << std::endl;
}

void InputHandler::handleCompoundInstructions(int instruction) {
    switch (instruction)
    {
    case 1:
        addCircle();
        break;
    case 2:
        addRectangle();
        break;
    case 3:
        addTriangle();
        break;
    case 4:
        addCompound();
        break;
    case 5:
        handle();
        break;
    default:
        std::cout << "Invalid instruction. Please try again." << std::endl;
        handle();
        break;
    }
}

void InputHandler::addCompound() {
    int instruction;

    std::cout << "Please enter the following instruction number to build the compound:"<< std::endl;
    std::cout << "1. 'add circle': to add a circle"<< std::endl;
    std::cout << "2. 'add rectangle': to add a rectangle"<< std::endl;
    std::cout << "3. 'add triangle': to add a triangle"<< std::endl;
    std::cout << "4. 'add compound': to add a compound"<< std::endl;
    std::cout << "5. 'exit': to exit the program"<< std::endl;

    std::cin >> instruction;

    handleCompoundInstructions(instruction);
}