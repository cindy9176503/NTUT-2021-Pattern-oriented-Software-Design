#include <iostream>
#include <fstream>

#include "input_handler.h"

void InputHandler::handle() {
    int instruction;

    while (isContinued) {
        printEditorInstructions();

        std::cin >> instruction;

        handleEditorInstructions(instruction);
    }
}

void InputHandler::printEditorInstructions() {
    std::cout << "Please enter the following instruction number to start building:" << std::endl;
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
        compoundNum ++;
        builder->buildCompoundBegin();
        addCompound();
        break;
    case 5:
        save();
        break;
    case 6:
        builder->reset();
        isContinued = false; 
        break;
    default:
        std::cout << "Invalid instruction. Please try again." << std::endl;
        break;
    }
}

void InputHandler::save() {
    std::string result = {}, fileName;
    std::ofstream ofs;

    Shape* shape = builder->getShape();

    std::cout << "Please enter the file name to save the shape: " << std::endl;
    std::cin >> fileName;

    if(shape == nullptr) {
        std::cout << "No shape, txt is empty.\n" << std::endl;
    }else{
        ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    
        shape->accept(visitor);
        result = visitor->getResult();

        delete visitor;
    }

    std::cout << "Save complete." << std::endl;

    ofs.open(fileName + ".txt");

    if (!ofs.is_open()) {
        std::cout << "Failed to open file.\n";
    } else {
        ofs << result;
        ofs.close();
    }
    
    builder->reset();
}

void InputHandler::addCircle() {
    double radius;

    std::cout << "Please enter the information of circle: \nRadius of circle: ";
    std::cin >> radius;
       
    try{
        builder->buildCircle(radius);
        std::cout << "Circle added." << std::endl;
    }catch (const char* e) {
        std::cout << "Invalid argument. Please try again."<< std::endl;
    }
}

void InputHandler::addRectangle() {
    double height, width;

    std::cout << "Please enter the information of retangle: " << std::endl;
    std::cout << "Width of rectangle: ";
    std::cin >> width;
    std::cout << "Height of rectangle: ";
    std::cin >> height;
       
    try{
        builder->buildRectangle(width, height);
        std::cout << "Rectangle added." << std::endl;
    }catch (const char* e) {
        std::cout << "Invalid argument. Please try again."<< std::endl;
    }
}

void InputHandler::addTriangle() {
    double x1, y1, x2, y2;

    std::cout << "Please enter the information of triangle: " << std::endl;
    std::cout << "X1 of triangle: ";
    std::cin >> x1;
    std::cout << "Y1 of triangle: ";
    std::cin >> y1;
    std::cout << "X2 of triangle: ";
    std::cin >> x2;
    std::cout << "Y2 of triangle: ";
    std::cin >> y2;
       
    try{
        builder->buildTriangle(x1, y1, x2, y2);
        std::cout << "Triangle added." << std::endl;
    }catch (const char* e) {
        std::cout << "Invalid argument. Please try again." << std::endl;
    }
}

void InputHandler::printCompoundInstructions() {
    std::cout << "Please enter the following instruction number to build the compound: "<< std::endl;
    std::cout << "1. 'add circle': to add a circle"<< std::endl;
    std::cout << "2. 'add rectangle': to add a rectangle"<< std::endl;
    std::cout << "3. 'add triangle': to add a triangle"<< std::endl;
    std::cout << "4. 'add compound': to add a compound"<< std::endl;
    std::cout << "5. 'exit': to exit the program"<< std::endl;
}

void InputHandler::handleCompoundInstructions(int compoundInstruction) {
    switch (compoundInstruction)
    {
    case 1:
        addCircle();
        addCompound();
        break;
    case 2:
        addRectangle();
        addCompound();
        break;
    case 3:
        addTriangle();
        addCompound();
        break;
    case 4:
        compoundNum ++;
        builder->buildCompoundBegin();
        addCompound();
        break;
    case 5:
        std::cout << "Compound added." << std::endl;

        compoundNum --;
        builder->buildCompoundEnd();

        if(compoundNum == 0) {
            handle();
        }else{
            addCompound();
        }
        break;
    default:
        std::cout << "Invalid instruction. Please try again." << std::endl;
        handle();
        break;
    }
}

void InputHandler::addCompound() {
    int compoundInstruction;

    printCompoundInstructions();
    
    std::cin >> compoundInstruction;

    handleCompoundInstructions(compoundInstruction);
}