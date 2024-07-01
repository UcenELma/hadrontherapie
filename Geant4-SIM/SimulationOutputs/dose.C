{
#include <fstream>
#include<vector>
#include<string>
using namespace std;
    
    ifstream in;
    cout << "This script does not work for secondaries!!" << endl;
    cout << "Enter dose file to analyze: ";
    string filename;
    cin >> filename;
    
    in.open(filename);
    if (!in.is_open()) {
        cerr << "Unable to open " << filename << "\"\n" << endl;
        exit(1);
    }
    else {
        cout << "Reading file \" " << filename << "\" ... " << endl;  
        return;
    }
    
    vector<float> xvec, dosevec;
    Char_t n[4];
    float x, dose;
    in >> n >> n >> n >> n; // to skip i,j,k,dose strings. 
    while (in) {
        xvec.push_back(x);
        in >> x >> n >> n >> dose;
        dosevec.push_back(dose);
    }
    
    in.close();
    
    
    float voxelsize;
    cout << "Please enter the voxel size (normally 0.1mm): ";
    cin >> voxelsize;
    
    for (int i = 0; i < xvec.size(); i++) {
        xvec[i] = xvec[i] * voxelsize;
    }
    
    
    TCanvas *c1 = new TCanvas ("c1","Dose",1600,800);
    TGraph  *g= new TGraph(dosevec.size(), &xvec[0], &dosevec[0]);
    g -> SetMarkerStyle(21);
    g -> SetMarkerSize(0.8);
    g -> SetTitle("Distributed dose;Distance Travelled (mm);Dose (gy)");
    g -> Draw("APL");
    
}
