
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <vector>
using namespace std;


template <class IF>
class sc_port{
    public:
    string name;
    IF* _int;
    sc_port(string n) {
        name = n;
    }
    sc_port() {
        name = "null";
    }
    void operator()(IF* _interface) {
        _int = _interface;
    }
    void write(int w) {
        _int->write(4);
    }


    int read() {
        return _int->read();
    }
};
class outp {
    public:
    int rd;
    outp (){
        cout<<"Constructed outp"<<endl;
    }
    void write(int x) {
        rd=x;
        cout<<"Writing X from Outp"<<x;
    }
    int read() {
        cout<<"Reading back "<<rd<<endl;
        return rd;
    }
};


class my_op {
    public:
    sc_port<outp> my_port;
    int x;
    string a[2];
    string b;
    string *p;
    //constructor
    my_op():my_port("my_port") {
        x=1;
        b="New string";
    }
   
    my_op(const my_op& c):x(c.x),a(c.a),b(c.b) {
        p = new string[20];
        cout<<" Size of p is "<<sizeof(c.p)<<endl;
        //strcpy(c.p,p);
        string::iterator it = c.p->begin();
        string::iterator it_d = p->begin();
        cout<<endl<<"--------------------------------"<<endl;
        int i=0;
        while(it != c.p->end()) {
            cout<<*it;
            it_d[i] = *it;
            it++;
            it_d++;
            i++;
        }
        cout<<endl<<"--------------------------------"<<endl;
        //std::copy(c.p->begin(),c.p->end(),p->begin());
        /*
        cout<<endl<<"--------------------------------"<<endl;
        while(it != p->end()) {
            cout<<*it;
            it++;
        }
        cout<<endl<<"--------------------------------"<<endl;
        */
    }
string operator[](const int i) {
    return a[i];
}


my_op& operator+=(const string x) {
    this->b=this->b+" " + x;
    return *this;
}


friend ostream& operator<<(ostream& os,my_op& op);


string operator<<(const my_op& op) {
    string tmp=op.a[0] + " " + op.a[1];
    return tmp;
}
/*
ostream& operator<<(ostream& os,my_op& op) {
    os<<op.a;
}*/
};


ostream& operator<<(ostream& os,my_op& op) {
    os<<"Data from class is A="<<op.a<<" and "<<op.b<<endl;
    int a=op.x;
}


string readfile(ifstream& f) {


    string s;
    string line;
    while(getline(f,line)){
        //std::transform(line.begin(),line.end(),line.begin(),tolower);
        s+=line;
    }
    return s;
}
   
   


int main() {
    ifstream file("myfile.txt");
    my_op m;
    m.a[0] = "Hey";
    m.a[1] = "there";
    m.b = "Second line ";
    string c=readfile(file);
    cout<<c<<endl;
    cout << "Hello world" << endl;
    cout.operator<<("Hey there");
    cout << "Hello world" << endl;


    cout<<m.operator[](1)<<endl;
    m+=" is great";
    cout<<m.b<<endl;


    cout<<"Using ostream"<<endl;
    cout<<m;


    my_op str1;
    string a =" Hey there";
    str1.p = &a;
    my_op str2=str1;
    cout<<"Address of str1 "<<str1.p<<" and of Str2 "<<str2.p<<endl;
    cout<<"str1 is "<<*str1.p<<" and str2 is "<<*str2.p<<endl;
    //cout<<m;
    my_op my_op_obj_master,my_op_obj_slave;
    outp int_outp;
    my_op_obj_master.my_port(&int_outp);
    my_op_obj_slave.my_port(&int_outp);
    my_op_obj_master.my_port.write(4);
    cout<<my_op_obj_slave.my_port.read();
    return 0;
}
