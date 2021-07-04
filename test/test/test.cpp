#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {
        name = "fregfterd";
        age = 4;
    }

    Person(string n, int a) {
        name = n;
        age = a;
    }

    bool operator==(const Person& p) const
    {
        return name == p.name && age == p.age;
    }
};

struct hash_name {
    size_t operator()(const Person& p) const {
        return hash<string>()(p.name) ^ hash<int>()(p.age);
    }
};

void prim(int m, int n){
    cout << m << " " << n << endl;
    if (m >= n){
        while (m%n) n++;
        m /= n;
        prim(m, n);
        cout << n << endl;
    }
    else {
        return;
    }
}

void example(char acWelcome[]) {
    printf("%d", sizeof(acWelcome));
    cout << acWelcome[4] << endl;
    return;
}


void Func(char str_arg[100])
{
    printf("%d\n", sizeof(str_arg));
}
int test1(void)
{
    char str[] = "Hello";
    printf("%d\n", sizeof(str));
    printf("%d\n", strlen(str));
    char* p = str;
    printf("%d\n", sizeof(p));
    Func(str);
    return -1;
}


vector<int> test2() {
    vector<int> res(2);
    vector<int> X, Y;
    int x = 1, y = 1;
    while (9 * x < 95) {
        X.push_back(x);
        x++;
    }
    while (16 * y < 95) {
        Y.push_back(y);
        y++;
    }
    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j < Y.size(); j++) {
            if ((9 * X[i] + 16 * Y[j]) == 95) {
                res[0] = X[i];
                res[1] = Y[j];
                return res;
            }
        }
    }

    return res;
}


int main() {
    //unordered_map<int, Person> ids; //不需要把哈希函数传入构造器
    //ids[6] = Person("Mark", 17);
    //ids[7] = Person("Andrew", 16);
    ///*for (auto ii = ids.begin(); ii != ids.end(); ii++)
    //    cout << ii->first.name
    //    << " " << ii->first.age
    //    << " : " << ii->second
    //    << endl;*/
    //return 0;

    /*int* p1 = new int[10];
    int* p2 = new int[10]();

    for (int i = 0; i < 10; i++) {
        cout << *p2 << endl;
        p2++;
    }*/

    // prim(10, 2);

   /* enum string {
        x1,
        x2,
        x3 = 10,
        x4,
        x5,
    } x;

    x = x2;
    string y = x2;

    cout << y << endl;*/

    //unsigned char* p1;
    //unsigned long* p2;
    //p1 = (unsigned char*)0x801000;
    //p2 = (unsigned long*)0x810000;

    //// cout << p1 + 9 << endl;
    //cout << p2 + 5 << endl;
    //test1();
    /*vector<int> res = test2();
    cout << res[0] << " " << res[1] << endl;
    
    double a = 200 * 0.53 * 12;
    double b = (100 * 0.28 + 100 * 0.56) * 12 + 100;
    cout << a - b << endl;*/

    cout << '0' * 4 << endl;


}

