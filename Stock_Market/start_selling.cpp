#pragma once
#include <iostream>
#include "stock_market.h"

//main menu
int show_manu(char* selection){
    std::cout<<"\n"<<"What would you like to do?"<<std::endl;
    std::cout<<"    S: Sell an item"<<std::endl;
    std::cout<<"    P: Print stock"<<std::endl;
    std::cout<<"    R: Report sales"<<std::endl;
    std::cout<<"    E: Exit"<<std::endl;
    std::cout<<"Enter your choice  (S, P, R, or E)>>>";
    std::cin>>selection;
}

//if user input wrong value
int input_error(char* selection){
    std::cout<<selection<<"?, I beg your pardon.";
}

//main
int main(){
    char selection[10];
    show_manu(selection);
    //std::cout<<selection;
   
    while (True){
        show_manu(selection);
        if (selection == "E"){
            break;
        }
        
        else if (selection == "S" ){
            Sell(stock_list, sales_hist);
        }
        
        else if (selection == "P"){
            Print_stock(stock_list);
        }
        
        else if (selection == "R"){
            Print_sales(sales_hist);
        }
        else:
        input_error(selection);
        
    }
    Store_stock(stock_list);
}