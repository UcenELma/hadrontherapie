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
    
    
    vector<float> xvec, dosevec, normvec;
    Char_t n[4];
    float x, dose;
    in >> n >> n >> n >> n; // to skip i,j,k,dose strings. 
    
    while (in) {
        xvec.push_back(x);
        dosevec.push_back(dose);
        in >> x >> n >> n >> dose;
    }
    in.close();
    
    float min = *min_element(dosevec.begin(),dosevec.end());
    float max = *max_element(dosevec.begin(),dosevec.end());
    float norm;
    
    for (int i = 0; i < dosevec.size(); i++) {
        norm = (dosevec[i]-min) / (max - min);
        normvec.push_back(norm);
    }
    
    float voxelsize;
    cout << "Please enter the voxel size (normally 0.1mm): ";
    cin >> voxelsize;
    
    for (int i = 0; i < xvec.size(); i++) {
        xvec[i] = xvec[i] * voxelsize;
    }
    
    
    TCanvas *c1 = new TCanvas ("c1","Dose",1600,800);
    
    TGraph *g= new TGraph(normvec.size()-1, &xvec[1], &normvec[1]);
    g -> SetMarkerStyle(21);
    g -> SetMarkerSize(0.8);
    g -> SetTitle("Distributed dose;Distance Travelled (mm);Normalized dose");
    g -> Draw("APL");
}
