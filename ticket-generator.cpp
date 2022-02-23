#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include<ctime>
#include <chrono>
#include <string.h>
using namespace std;
class Ticket {
    private:
        string description,arriTime;
        int priority;
    public:
    Ticket( string t_description = "not set", int t_priority = 0,string a_time = "not set " ){
        description=t_description;
        arriTime=a_time;
        priority=t_priority;
    }
        
    friend bool operator <(const Ticket& c1, const Ticket& c2){
        if(c1.priority<c2.priority){
            return true;
        }
        else return false;
    }
    friend bool operator >(const Ticket& c1,const Ticket& c2){
        if(c1.priority>c2.priority){
            return true;
        }
        else return false;
    }
    friend bool operator >=(const Ticket& c1,const Ticket& c2){
        if(c1.priority>=c2.priority){
            return true;
        }
        else return false;
    }
    friend bool operator ==(const Ticket& c1,const Ticket& c2){
        if(c1.priority==c2.priority){
            return true;
        }
        else return false;
    }
    friend ostream& operator <<(ostream& outs,const Ticket& rhs){
        outs<<"Priority: "<<rhs.priority<<endl;
        outs<<"Description: "<<rhs.description<<endl;
        outs<<"Arrival Time : "<<rhs.arriTime<<endl;
        return outs;
    }
    
  };


        template <class T>
        class PQ {
        private:
            vector<T> v;
            void heapify(int);
            void insert(T);
        public:
            void push(T newData)
            {
                insert(newData);
            }
            void pop()
            {
                swap(v[0], v[v.size() - 1]);
                v.pop_back();
                heapify(0);
            }
            T& top()
            {
                return v[0];
            }
        void print(ostream& os)
            {
                for (int i = 0; i < v.size(); i++) os << i << ":" << v[i] << "  ";
                os << endl;
            }
        bool empty()
            {
                return v.size() == 0;
            }
        };


template<class T>
ostream& operator<<(ostream& os, PQ<T>& Q) {
    Q.print(os);
    return os;
}

template <class T>
void PQ<T>::heapify(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= v.size()) return;
    int largerChild = left;
    if (right < v.size())
        if (v[right] > v[left])
            largerChild = right;
    if (v[largerChild] >= v[i]) swap(v[i], v[largerChild]);
    heapify(largerChild);
}


    template<class T>
    void PQ<T>::insert(T item)
    {
        v.push_back(item);
        int i = v.size() - 1;
        if (v.size() == 1) return;
        int parent;
        while (i > 0) {
            parent = (i - 1) / 2;
            if (v[i] > v[parent]) swap(v[i], v[parent]); else break;
            i = parent;
        }
    }

    void printMenu() {
        cout << endl;
        cout << "1. Add a ticket. " << endl;
        cout << "2. Serve Ticket. " << endl;
        cout << "3. Display pending tickets. " << endl;
        cout << "4. Exit. " << endl;
    
    }
    void input(string& desc, int& prio, string &arrtime){
        cout<<"Enter ticket priority:";
        cin>>prio;
        while(prio<1 || prio>10){
            cout<<"Priority must be between 1 to 10 only";
            cin>>prio;
        }
        cout<<"Enter ticket description:";
        cin.ignore();
        getline(cin, desc);
        #include <chrono>
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        cout <<"Arriving Time : "<< ctime(&timenow) << endl;
        arrtime= ctime(&timenow);
    }
    
    
int main() {
    PQ <Ticket> hds; //hds= help_desk_system
    char x;
    while(true){
    printMenu();
        cout<<"Select your option: ";
        cin>>x;
        cout<<endl;
        if(x=='1'){
            string desc; int prio; string arrtime;
            input(desc, prio, arrtime);
            Ticket A(desc, prio, arrtime);
            hds.push(A);
        }
        if(x=='2'){
            cout<<"Serving ticket: ";
            cout<<hds.top();
            hds.pop();
        }
        if(x=='3'){
            cout<<"Displaying Pending tickets"<<endl;
            cout<<hds;
            }
        if(x=='4'){
            break;
        }
        else continue;
    }
}

