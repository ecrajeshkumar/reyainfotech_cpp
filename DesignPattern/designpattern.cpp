#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

/*
    1. Singleton Pattern:
    Ensures only one instance of a class exists.
*/
class Singleton{
    public:
        static Singleton& getinstance(){
            static Singleton instance;
            return instance;
        }
        void log(int id){
            lock_guard<mutex>lck(mtx);
            cout<<"Thread ID : "<<id
                <<" Singleton instance address: "
                << static_cast<const void*>(this) <<"\n";
        }
    
    private:
        mutex mtx;
        Singleton(){
            cout<<"Singleton inilitize\n";
        }
        // Prevent copy/move
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator = (const Singleton&) = delete;
        Singleton& operator = (Singleton&&) = delete;
};

void worker(int tid){
    Singleton::getinstance().log(tid);
}


/*
    2. Factory Pattern:
    Creates objects without exposing creation logic.
*/

class Product{
    public:
        virtual void use() = 0;
        virtual ~Product() = default;
};

class CreateProductA : public Product{
    public:
        void use() override{
            cout<<"use product A\n";
        }
};

class CreateProductB : public Product{
    void use() override{
        cout<<"use product B\n";
    }
};

class Factory{
    public:
        static unique_ptr<Product>CreateProduct(string product){
            if(product == "A") return make_unique<CreateProductA>();
            else return make_unique<CreateProductB>();
        }
};

/*
    3. Observer Pattern:
    Creates objects without exposing creation logic.
*/
class Subscriber{
    public:
        virtual void update(const std::string& msg) = 0;
        virtual ~Subscriber() = default;
};

class MusicChannel{
    private:
        vector<Subscriber*> subscribers;
    public:
        void attach(Subscriber& subscriber){
                subscribers.push_back(&subscriber);
        }
        void notify(const string& msg){
            for(auto* subscriber: subscribers){
                subscriber->update(msg);
            }
        }
};

class MusicSubscriber : public Subscriber{
    private:
        string name;
    public:
        MusicSubscriber(string str):name(move(str)){
        }
        void update(const string& msg) override{
            cout<<name << " received: "<<msg <<"\n";
        }
};


int main(){
    constexpr int NUM_THREADS = 5;
    vector<thread>threads;
    
    for(int i = 0; i < NUM_THREADS; ++i){
        threads.emplace_back(worker, i);
    }
    for(auto& th : threads){
        th.join();
    }
    cout<<"Singleton Pattern end.\n";
    /////////////////////////////////////////////////////////////
    // unique_ptr<Product> factory = Factory::CreateProduct("A");
    auto factory = Factory::CreateProduct("A");
    factory->use();
    cout<<"Factory Pattern end.\n";
    /////////////////////////////////////////////////////////////
    MusicChannel musicChannel;
    
    MusicSubscriber musicSubscriber1("Rajesh");
    MusicSubscriber musicSubscriber2("Rakesh");
    MusicSubscriber musicSubscriber3("Manoj");

    musicChannel.attach(musicSubscriber1);
    musicChannel.attach(musicSubscriber2);
    musicChannel.attach(musicSubscriber3);

    musicChannel.notify("Hero song added");
    musicChannel.notify("Don song added");
    cout<<"Observer Pattern end.\n";
    /////////////////////////////////////////////////////////////





    return 0;
}