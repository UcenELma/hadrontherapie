{
#include <fstream>
#include<vector>
#include<string>
using namespace std;
    
    ifstream in;
    string filename;
    int colums;
    cout << "Enter LET file to analyze: ";
    cin >> filename;

    
    in.open(filename);
    if (!in.is_open()) {
        cerr << "Unable to open " << filename << "\"\n" << endl;
        exit(1);
    }
    else {
        cout << "Reading file \" " << filename << "\" ... " << endl;  
        cout << "Enter number of colums in LET.out file: ";
        cin >> colums;
        return;
    }
    

    vector<float> xvec, letvec;
    Char_t n[100];
    float x, let;
    
    for (int i = 0; i < colums; i++) {
        in >> n; // skip i,j,k,...,....,.... lines
    }
    
    while (in) {
        
        xvec.push_back(x);
        in >> x >> n >> n >> let;
        letvec.push_back(let);
        for (int i = 0; i < colums - 4; i++) {
            in >> n;
        }
        
        if (let == 0) {
         break;   
        }
        
    }
    
    in.close();
    
    float voxelsize;
    cout << "Please enter the voxel size (normally 0.1mm): ";
    cin >> voxelsize;
    
    for (int i = 0; i < xvec.size(); i++) {
        xvec[i] = xvec[i] * voxelsize;
    }
    
    TCanvas *c1 = new TCanvas ("c1","LET",1600,800);
    TGraph  *g= new TGraph(letvec.size(), &xvec[0], &letvec[0]);
    g -> SetMarkerStyle(21);
    g -> SetMarkerSize(0.8);
    g -> SetTitle("LET;Distance Travelled (mm);Stopping power");
    g -> Draw("AP");
    
}
