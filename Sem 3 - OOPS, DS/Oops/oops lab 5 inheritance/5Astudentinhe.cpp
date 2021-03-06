#include <iostream>
using namespace std;

class student
{
protected:
    string name;
    int rollno;

public:
    student()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter rollno: ";
        cin >> rollno;
    }

    string getname()
    {
        return name;
    }

    void display_commoninfo()
    {
        cout << "\nName: " << name << endl;
        cout << "RollNO: " << rollno << endl;
    }
};

class arts : public student
{
private:
    int sketch, colortheory;

public:
    arts()
    {
        cout << "Enter sketch marks: ";
        cin >> sketch;
        cout << "Enter colortheory marks: ";
        cin >> colortheory;
    }

    void displayinfo()
    {
        display_commoninfo();
        cout << "sketch marks: " << sketch << endl;
        cout << "color theory marks: " << colortheory << endl;
    }
};

class medical : public student
{
public:
    int biology, pyschology;
    medical()
    {
        cout << "Enter biology marks: ";
        cin >> biology;
        cout << "Enter pyschology marks: ";
        cin >> pyschology;
    }

    void displayinfo()
    {
        display_commoninfo();
        cout << "biology marks: " << biology << endl;
        cout << "pyschology marks: " << pyschology << endl;
    }
};

class engineering : public student
{
protected:
    int math, workshop;

public:
    engineering()
    {
        cout << "Enter math marks: ";
        cin >> math;
        cout << "Enter workshop marks: ";
        cin >> workshop;
    }

    void display_commoninfo_eng()
    {
        display_commoninfo();
        cout << "math marks: " << math << endl;
        cout << "workshop marks: " << workshop << endl;
    }
};

class mech : public engineering
{
private:
    int thermodynamics;

public:
    mech()
    {
        cout << "Enter thermodynamics marks: ";
        cin >> thermodynamics;
    }

    void displayinfo()
    {
        display_commoninfo_eng();
        cout << "thermodynamics marks: " << thermodynamics << endl;
    }
};

class comp : public engineering
{
private:
    int OOPs;

public:
    comp()
    {
        cout << "Enter OOPs marks: ";
        cin >> OOPs;
    }

    void displayinfo()
    {
        display_commoninfo_eng();
        cout << "OOPs marks: " << OOPs << endl;
    }
};

class etc : public engineering
{
private:
    int digital_electronics;

public:
    etc()
    {
        cout << "Enter digital_electronics marks: ";
        cin >> digital_electronics;
    }

    void displayinfo()
    {
        display_commoninfo_eng();
        cout << "digital_electronics marks: " << digital_electronics << endl;
    }
};

int main()
// make menu. user should be able  choose which data he wants to enter
{
    int narts, ncomp, nmech, netc, nmed;

    while (1)
    {
        int n;
        cout << "1.Enter student details" << endl;
        cout << "2.Display student details" << endl;
        cout << "3.Search a student by roll number" << endl;
        cout << "4.Display total number of students" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            int num;
            cin >> num;
            switch (num)
            {
            case 1:

                break;

            default:
                break;
            }
            cout << "Enter total students in each arts: ";
            cin >> narts;
            arts *a = new arts[narts];

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;

        default:
            break;
        }
    }

    //  creating objects of each:
    cout << "Enter total students in each medical: ";
    cin >> nmed;
    cout << "Enter total students in each computer: ";
    cin >> ncomp;
    cout << "Enter total students in each mechanical: ";
    cin >> nmech;
    cout << "Enter total students in each electronics: ";
    cin >> netc;

    cout << "Enter student info: " << endl;
    cout << "Arts: " << endl;
    cout << "Medical: " << endl;
    medical *m = new medical[nmed];
    cout << "Computer: " << endl;
    comp *c = new comp[ncomp];
    cout << "Mechanical: " << endl;
    mech *me = new mech[nmech];
    cout << "Electronics: " << endl;
    etc *e = new etc[netc];

    // Search wrt name:
    while (1)
    {
        // QUESTION: do I need to search as common or take 'brach' n name/rollno from user?
        string inputname;
        cout << "\nEnter Name to search: ";
        cin >> inputname;

        for (int i = 0; i < 10; i++)
        {
            if (!inputname.compare(a[i].getname()))
                a[i].displayinfo();
            if (!inputname.compare(m[i].getname()))
                m[i].displayinfo();
            if (!inputname.compare(c[i].getname()))
                c[i].displayinfo();
            if (!inputname.compare(me[i].getname()))
                me[i].displayinfo();
            if (!inputname.compare(e[i].getname()))
                e[i].displayinfo();
        }
    }
}
