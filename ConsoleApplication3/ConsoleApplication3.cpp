#include <iostream>
#include <fstream>
using namespace std;

struct paralelipiped {
    int ID;
    int length, width, height;
    int color, material;

};

paralelipiped arr[10];
void p_3(int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i].length * arr[i].width * arr[i].height;
    }
    sum = sum / n;
    cout << sum<<endl;
}

void file_out(int n)
{
    ofstream comoare("comoare.in");
    for (int i = 0; i < n; i++)
    {
        comoare << arr[i].ID << " ";
        comoare << arr[i].length << " ";
        comoare << arr[i].width << " ";
        comoare << arr[i].height << " ";
        comoare << arr[i].color << " ";
        comoare << arr[i].material << endl;
    }
}

void in(int n) {

    cout << "ID : "; cin >> arr[n].ID;
    cout << "Lenght : "; cin >> arr[n].length;
    cout << "Width : "; cin >> arr[n].width;
    cout << "Height : "; cin >> arr[n].height;
    cout << "Color : "; cin >> arr[n].color;
    cout << "Material : "; cin >> arr[n].material;

}
void out(int n)
{
    for (int i = 0; i < n; i++) {
        cout << "ID : " << arr[i].ID << endl;
        cout << "Lenght : " << arr[i].length << endl;
        cout << "Width : " << arr[i].width << endl;
        cout << "Height : " << arr[i].height << endl;
        cout << "Color : " << arr[i].color << endl;
        cout << "Material : " << arr[i].material << endl << endl;
    }
}

void volume_color(int n)
{
    int a; paralelipiped arrq[10];
    cout << "Input color : "; cin >> a;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].color == a)
        {
            arrq[i] = arr[i]; cnt++;
        }
    }
    bool swapq = 1;
    while (swapq) {
        swapq = 0;
        for (int i = 0; i < n; i++)
        {
            if (arrq[i].height * arrq[i].length * arrq[i].width > arrq[i + 1].height * arrq[i + 1].length * arrq[i + 1].width) {
                paralelipiped swapp = arrq[i]; arrq[i] = arrq[i + 1]; arrq[i + 1] = arrq[i]; swapq = 1;
            }
        }
    }
    cout << "_______" << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << arrq[i].ID << endl;
    }
}

void min_max(int n)
{
    int m,min,max,minid,maxid;
    cout << "Input material : "; cin >> m;
    for (int i = 0; i < n; i++) {
        if (arr[i].material = m) {
            min = arr[i].height * arr[i].length * arr[i].width; max = min; maxid = i; minid = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i].material = m) {
            if (arr[i].height * arr[i].length * arr[i].width > max) { max = arr[i].height * arr[i].length * arr[i].width; maxid = i; }
            if (arr[i].height * arr[i].length * arr[i].width < min) { min = arr[i].height * arr[i].length * arr[i].width; minid = i; }
        }
    }
    cout << "Max : " << arr[maxid].ID << "\nMin : " << arr[minid].ID << endl;
}

void not_more(int n)
{
    int m,max;
    cout << "Input material : "; cin >> m; cout << "Input max volume : "; cin >> max;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].material == m) 
        {
            if (arr[i].height * arr[i].length * arr[i].width <= max)
            {
                cout << arr[i].ID << endl;
            }
        }
    }
    cout << endl;
}

void color(int n)
{
    int c;
    cout << "Input color : "; cin >> c;
    ofstream color("color.txt");
    for (int i = 0; i < n; i++)
    {
        if (arr[i].color == c) {
            color << arr[i].ID << " ";
            color << arr[i].length << " ";
            color << arr[i].width << " ";
            color << arr[i].height << " ";
            color << arr[i].color << " ";
            color << arr[i].material << endl;
        }
    }

}

void snatch()
{
    paralelipiped snatch[10];
    int n;
    cout << "Input the number of gold ingots : "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        snatch[i].ID = i;
        snatch[i].color = 999;
        snatch[i].material = 999;
        cout << "Height : "; cin >> snatch[i].height;
        cout << "Width : "; cin >> snatch[i].width;
        cout << "Lenght : "; cin >> snatch[i].length;
        cout << endl;
    }
    int min, max = 0;
    for (int i = 0; i < n; i++) {
        min = snatch[i].height;
        if (min > snatch[i].length) { min = snatch[i].length; }
        if (min > snatch[i].width) { min = snatch[i].width; }
        if (max < min) { max = min; }
    }
    ofstream comout("comoare.out");
    comout << max;
}
int main()
{

    ifstream inc("comoare.in");
    ofstream comoare("comoare.in", ios::app);
    int i = 0;
    int n = 0;
    while (!inc.eof()) { n++; inc.ignore(100, '\n'); } n--; inc.seekg(0);
    for (int i = 0; i < n; i++)
    {

        inc >> arr[i].ID;
        inc >> arr[i].length;
        inc >> arr[i].width;
        inc >> arr[i].height;
        inc >> arr[i].color;
        inc >> arr[i].material;
    }


    int menu=1;
    while (menu != 0)
    {
        cout << "Introduce the number of the desired function : " << endl;
        cout << "1. Introduce a new paralelepiped" << endl;
        cout << "2. Check all of the existing paralelepipeds" << endl;
        cout << "3. Average volume" << endl;
        cout << "4. Check volume by color (sorted) " << endl;
        cout << "5. Min max " << endl;
        cout << "6. Material" << endl;
        cout << "7. Color" << endl;
        cout << "8. Gold" << endl;
        cin >> menu; cout << endl;

        switch (menu)
        {
        case 1: {in(n); n++; break; }
        case 2: {out(n); break; }
        case 3: {p_3(n); break; }
        case 4: {volume_color(n); break; }
        case 5: {min_max(n); break; }
        case 6: {not_more(n); break; }
        case 7: {color(n); break; }
        case 8: {snatch(); break; }
        default: {cout << "Bad input" << endl; break; }
            break;
        }
    }
    file_out(n);
}
