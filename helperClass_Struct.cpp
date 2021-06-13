#include <iostream>
#include <vector>

using namespace std;

struct Person
{
    string fname;
    string sname;
};

void func(struct Person p);

int main()
{
    struct Person p;

    p.fname = "Divyan";
    p.sname = "Hirasen";

    vector<Person> vect;
    vect.push_back(p);

    vect.push_back({"Shuruka", "Ramuraru"});

    for (int count = 0; count < vect.size(); count++)
    {
        cout << "\nfname: " << vect[count].fname << "\nsname: " << vect[count].sname << endl;
    }
    cout << endl;

    return 0;
}
void func(struct Person p)
{
    cout << "fname: " << p.fname << endl;
    cout << "sname: " << p.sname;
}