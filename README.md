# Prioritizing data-oriented design paradigms in your code
This code shows examples of data-oriented and object-oriented approaches in the design of a stock portfolio management system. It is not designed to be used for anything other than to showcase differences between software design paradigms explained in a Medium article I wrote. Nonetheless, I hope it can be a very useful educational resource to developers.

## Running the code
If you want to see the code run for yourself, clone the repository and run ```make``` from the root directory in a Linux terminal. Assuming you have g++ and make installed, this will build the project using the directions in the Makefile. Once the project is built, run ```./main``` to run the generated program that performs calculations using fake-stock-portfolio.csv. If you want to run the program on a different portfolio, you can run ```make generate-portfolio``` and ```./generate-portfolio``` to generate a new fake-stock-portfolio.csv randomly. 
