#include"Logger.hpp"
using namespace std;
int main(){
    Logger* log1 = new Logger();
    log1->Log("Virendra is my name");

    Logger* log2 = new Logger();
    log2->Log("Laptop is my name");
}