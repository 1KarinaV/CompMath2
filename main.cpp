#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <curses.h>

using namespace std;

static double func1(double x);
static double func2(double x);
static double func3(double x);

static double func1pr(double x);
static double func2pr(double x);
static double func3pr(double x);

void IterationMethodSystem(int task){
    int step=1, n;
    double x0=0,y0=0,x,y,d1,d2, e=0.0001;
    cout<< setprecision(6)<< fixed;
    cout<<"Enter precision: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>n;
    cout<<"Enter a: ";
    cin>>x0;
    cout<<"Enter b: ";
    cin>>y0;
    do
    {
        if(task == 1){
            x=sin(y0+2)-15;
            y=0.5-cos(x0-2);
            d1=x-x0;
            d2=y-y0;
            x0=x;
            y0=y;
        }else if(task == 2){
            x=pow(y0,2) + 4;
            y=4-sqrt(x0);
            d1=x-x0;
            d2=y-y0;
            x0=x;
            y0=y;
        }
        step++;
    }while(!(abs(d1)<e) && step < n && !(abs(d2)<e));
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
    cout<<step;
    getchar();

}

void HalfDivisionMethod(double func(double), double a, double b, double *c, double eps){
    *c = (a + b)/2.0;

    while((fabs(b-a)>eps) && (func(*c)!=0))
    {
        if(func(a)*func(*c)<=0 ) {
            b=*c;
        }
        else {
            a= *c;
        }
        *c=(a+b)/2;
    }
    getchar();
}

void TangentMethod( int task, double a, double b, double *c, double eps) {
    *c = (a + b)/2.0;
        if (task == 1) {
            do {
                *c = *c - func1(*c) / func1pr(*c);
            }
            while (fabs(func1(*c)) >= eps);
        }
        if (task == 2) {
            do {
                *c = *c - func2(*c) / func2pr(*c);
            }
            while (fabs(func2(*c)) >= eps );
        }
        if (task == 3) {
            do {
                *c =*c - func3(*c) / func3pr(*c);
            }
            while (fabs(func3(*c)) >= eps);
        }
    }


int main (){

    int choice = 0;
    double A, B, X, ep;
    

    cout << "Choose mode: solve Equation(0) or solve System of equations(1):" << endl;
    cin >> choice;
    if(choice){
        cout << "Simple Iterations Method was chosen" << endl;
        int choose = 0;
        cout << "Choose equation" << endl;
        cout << "(0) x=sin(y+2)-15 : y=0.5-cos(x-2)" << endl;
        cout << "(1) x=y^2+4 : y = 4 - sqrt(x)" << endl;
        cin >> choose;
        if(choose == 0){
            IterationMethodSystem(1);
        }
        if(choose == 1){
            IterationMethodSystem(2);
        }
}   else{
        cout << "Choose method: Half Division (0) or Tangent (1):" << endl;
        cin >> choice;

        if(choice){
            cout << "Tangent Method was chosen" << endl;
            int choose = 0;
            cout << "Choose equation" << endl;
            cout << "(0) x^3+5sin(x)-4" << endl;
            cout << "(1) 3cos(x)-4sin(x)" << endl;
            cout << "(2) 5x^3+8x^2-2.4x-1" << endl;
            cin >> choose;
                if(choose == 0){
                    cout<<"Enter left border: ";
                    cin>>A;
                    cout<<"Enter right border: ";
                    cin>>B;
                    cout<<"Enter precision: ";
                    cin>>ep;
                    TangentMethod(1, A, B, &X, ep);
                    cout << "Tangent Method";
                    cout<<"\nX="<<X<<endl;
                    HalfDivisionMethod(func1, A, B, &X, ep);
                    cout << "Half Division Method";
                    cout<<"\nX=: "<<X<<endl;
                }
                if(choose == 1){
                    cout<<"Enter left border: ";
                    cin>>A;
                    cout<<"Enter right border: ";
                    cin>>B;
                    cout<<"Enter precision: ";
                    cin>>ep;
                    TangentMethod(2,  A, B, &X, ep);
                    cout << "Tangent Method";
                    cout<<"\nX="<<X<<endl;

                    HalfDivisionMethod(func2,A, B, &X, ep);
                    cout << "Half Division Method";
                    cout<<"\nX=: "<<X<<"\n";
                }
                if(choose == 2){
                    cout<<"Enter left border: ";
                    cin>>A;
                    cout<<"Enter right border: ";
                    cin>>B;
                    cout<<"Enter precision: ";
                    cin>>ep;
                    TangentMethod(3, A, B, &X, ep);
                    cout << "Tangent Method";
                    cout<<"\nX=:"<<X<<endl;

                    HalfDivisionMethod(func3, A, B, &X, ep);
                    cout << "Half Division Method";
                    cout<<"\nX=: "<<X<<"\n";
                }
}   else {
            cout << "Half Division Method was chosen" << endl;
            int choose = 0;
            cout << "Choose equation" << endl;
            cout << "(0) x^3+5sin(x)-4" << endl;
            cout << "(1) 3cos(x)-4sin(x)" << endl;
            cout << "(2) 5x^3+8x^2-2.4x-1" << endl;
            cin >> choose;
            if (choose == 0) {
                cout<<"Enter left border: ";
                cin>>A;
                cout<<"Enter right border: ";
                cin>>B;
                cout<<"Enter precision: ";
                cin>>ep;
                cout << "Half Division Method" << endl;
                HalfDivisionMethod(func1, A, B, &X, ep);
                cout << "Half Division Method";
                cout<<"\nX=: "<<X<<"\n";
                TangentMethod(1, A, B, &X, ep);
                cout << "Tangent Method";
                cout<<"\nX="<<X<<endl;
            }
            if (choose == 1) {
                cout<<"Enter left border: ";
                cin>>A;
                cout<<"Enter right border: ";
                cin>>B;
                cout<<"Enter precision: ";
                cin>>ep;
                HalfDivisionMethod(func2, A, B, &X, ep);
                cout << "Half Division Method" ;
                cout<<"\nX=: "<<X<<"\n";

                TangentMethod(2, A, B, &X, ep);
                cout << "Tangent Method";
                cout<<"\nX=="<<X<<endl;

            }
            if (choose == 2) {
                cout<<"Enter left border: ";
                cin>>A;
                cout<<"Enter right border: ";
                cin>>B;
                cout<<"Enter precision: ";
                cin>>ep;
                HalfDivisionMethod(func3, A, B, &X, ep);
                cout << "Half Division Method";
                cout<<"\nX=: "<<X<<"\n";

                TangentMethod(3, A, B, &X, ep);
                cout << "Tangent Method";
                cout<<"\nX=:"<<X<<endl;
            }
        }
    }

return 0;
}


static double func1(double x) //x^3+5sin(x)-4
{
    return 3*pow(x, 3)+5*sin(x) - 4;
}

static double func2(double x) //3cos(x)-4sin(x)
{
    return 3*cos(x)-4*sin(x);
}

static double func3(double x) //5x^3+8x^2-2.4x-1
{
    return 5*pow(x, 3) + 8*pow(x, 2) - 2.4*x - 1;
}

static double func1pr(double x) //6xˆ2+5cox(x)
{
    return 6*pow(x, 2) + 5*cos(x);
}

static double func2pr(double x) //-3sin(x)-4cos(x)
{
    return -3 * sin(x) - 4 * cos(x);
}

static double func3pr(double x) //15x^2+16x-2.4
{
    return 15*pow(x, 2) + 16*x - 2.4;
}

