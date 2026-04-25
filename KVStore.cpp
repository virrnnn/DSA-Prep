#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;bnjhu
//KV Structure
//Current time
//Put 
//Get
//File log


class KVStore{
    private:
        struct Entry{
            string value;
            long long Expiry;        
        };
        unordered_map<string,Entry> Kstore;
        ofstream WAL;
        shared_mutex mtx;
    public:
        KVStore() {
            WAL.open("KVLog.txt", ios::app);
        }
        long long now(){
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }
        void LogPut(const string &key, const string &value, long long expiry){
            WAL << "PUT "<<key<<" "<<value<<" "<<expiry<<"\n";
            WAL.flush();
        }
        void LogDelete(const string &key){
            WAL << "DEL "<<key<<"\n";
            WAL.flush();
        }
        void Put(const string &key, const string &value, int ttl = -1){
            unique_lock lock(mtx);
            long long expiry = -1;
            if(ttl != -1){
                expiry = now() + ttl*1000;
            }
            LogPut(key,value,expiry);
            Kstore[key] = {value,expiry};
        }
         void recover(){
            ifstream in("KVLog.txt");
            string line;
            while(getline(in,line)){
                stringstream ss(line);
                string cmd;
                ss>>cmd;
                if(cmd == "PUT"){
                    string key,value;
                    long long expiry;
                    ss>>key>>value>>expiry;
                    if(expiry != -1 && now()>expiry){
                        continue;
                    }
                    Kstore[key] = {value,expiry};
                }
                else if(cmd == "DEL"){
                    string key;
                    ss>>key;
                    Kstore.erase(key);
                }
            }
        }
        string Get(const string& key){
            {
                shared_lock lock(mtx);
                auto it = Kstore.find(key);
                Entry e = it->second;// If shared lock reference can work
                if(e == Kstore.end()){
                    return "NOT FOUND";
                }
                return e.value;
            }
            {
                unique_lock lock(mtx);
                auto it = Kstore.find(key);
                Entry e = it->second;// Copy is must otherwise it will create race condition
                if(e.Expiry != -1 && now() > e.Expiry){
                    Kstore.erase(key);
                    return "NOT FOUND";
                }
            }
        }

        void Delete(const string& key){
            LogDelete(key);
            unique_lock lock(mtx);
            Kstore.erase(key);
        }           
};


int main(){

}