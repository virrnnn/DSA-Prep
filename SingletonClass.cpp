#include<iostream>
#include<mutex>
using namespace std;
//Logger old fashioned
class logger
{
    private:
        logger()
        {
            cout<<"Logger constructor called"<<endl;
        }
        static logger* inst;
        static mutex mtx;
    public:
        static logger* getlogger()
        {
            if(inst == nullptr)
            {
                lock_guard<mutex> lock(mtx);
                if(inst == nullptr)
                {
                    inst = new logger();
                }
            }
            return inst;
        }
};
logger* logger::inst = nullptr;
mutex logger::mtx;
//Singleton thread safe c++ 11
class Singleton{
    private:
        Singleton(){
            cout<<"Singleton constructor called"<<endl;
        }
    public:
        static Singleton& GetSingleton(){
            static Singleton instance;
            return instance;
        }
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};
int main(){
    Singleton& Obj1 = Singleton::GetSingleton();
    Singleton& Obj2 = Singleton::GetSingleton();
    if(&Obj1 == &Obj2){
        cout<<"Same singleton"<<endl;
    }
    logger* Obj3 = logger::getlogger();
    logger* Obj4 = logger::getlogger();
    if(Obj3 == Obj4){
        cout<<"Same logger"<<endl;
    }
}