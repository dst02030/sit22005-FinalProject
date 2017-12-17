#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

//Selling: ask for how many item
class Take_quant
{
    public:
    int qty;
    char res;
    
    public:
    Take_quant();
    
    public:
    int tool(char* item);
};

//selling: report decrease amount and show the result
class Sell
{
    public:
    Sell(stock_list, sales_hist);
};


//show what item remain in stock
class Print_stock
{
    public:
    Print_stock(stock_list);
};

//show what item sold
class Print_sales
{
  public:
  Print_sales(sales_hist);
};

//load the text file and convert to list
class Load_stock
{
  public:
  Load_stock(filename);
  returning();
};

//store the elements into txt file
class Store_stock
{
    public:
    Store_stock(stock_list);  
};


//selling : ask for what item
class Take_name
{
    public:
    Take_name(stock_list);
    returning();
    
    private: char* name;
};