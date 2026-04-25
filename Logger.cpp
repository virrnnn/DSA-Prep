#include<iostream>
#include"Logger.hpp"
using namespace std;
int Logger::counter = 0;
Logger::Logger(){
    counter++;
    cout<<"New Instance created No of instances-"<<counter<<endl;
}

void Logger::Log(string s){
    cout<<s<<endl;
}