#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct BP {
    double cLow, cHigh;
    int iLow, iHigh;
};

struct HasilPolutan {
    string nama;
    double konsentrasi;
    int aqi;
    string kategori;
};

string kategoriAQI(int aqi) {
    if (aqi <= 50) return "Baik";
    else if (aqi <= 100) return "Sedang";
    else if (aqi <= 150) return "Tidak Sehat (Sensitif)";
    else if (aqi <= 200) return "Tidak Sehat";
    else if (aqi <= 300) return "Sangat Tidak Sehat";
    else return "Berbahaya";
}

int aman(int x) {
    return (x < 0 ? 0 : x);
}

int hitungAQI(double C, BP bp[], int n) {
    if (C < 0) C = 0;

    for (int i = 0; i < n; i++) {
        if (C >= bp[i].cLow && C <= bp[i].cHigh) {
            double aqi = ((bp[i].iHigh - bp[i].iLow) / (bp[i].cHigh - bp[i].cLow))
                        * (C - bp[i].cLow) + bp[i].iLow;
            return aman(round(aqi));
        }
    }
    return 0;
}

int main() {

    BP PM25[] = {
        {0.0,12.0,0,50},{12.1,35.4,51,100},{35.5,55.4,101,150},
        {55.5,150.4,151,200},{150.5,250.4,201,300},{250.5,500.4,301,500}
    };

    BP PM10[] = {
        {0,54,0,50},{55,154,51,100},{155,254,101,150},
        {255,354,151,200},{355,424,201,300},{425,604,301,500}
    };

    BP O3_8h[] = {
        {0.000,0.054,0,50},{0.055,0.070,51,100},{0.071,0.085,101,150},
        {0.086,0.105,151,200},{0.106,0.200,201,300}
    };

    BP CO[] = {
        {0.0,4.4,0,50},{4.5,9.4,51,100},{9.5,12.4,101,150},
        {12.5,15.4,151,200},{15.5,30.4,201,300},{30.5,50.4,301,500}
    };

    BP SO2[] = {
        {0,35,0,50},{36,75,51,100},{76,185,101,150},
        {186,304,151,200},{305,604,201,300},{605,1004,301,500}
    };

    BP NO2[] = {
        {0,53,0,50},{54,100,51,100},{101,360,101,150},
        {361,649,151,200},{650,1249,201,300},{1250,2049,301,500}
    };

    HasilPolutan P[6] = {
        {"PM2.5", 0, 0, ""},
        {"PM10",  0, 0, ""},
        {"O3",    0, 0, ""},
        {"CO",    0, 0, ""},
        {"SO2",   0, 0, ""},
        {"NO2",   0, 0, ""}
    };

    cout << "Masukkan data polutan:\n";
    cout << "PM2.5 (ug/m3): "; cin >> P[0].konsentrasi;
    cout << "PM10 (ug/m3):  "; cin >> P[1].konsentrasi;
    cout << "O3 (ppm):      "; cin >> P[2].konsentrasi;
    cout << "CO (ppm):      "; cin >> P[3].konsentrasi;
    cout << "SO2 (ppb):     "; cin >> P[4].konsentrasi;
    cout << "NO2 (ppb):     "; cin >> P[5].konsentrasi;

    P[0].aqi = hitungAQI(P[0].konsentrasi, PM25, 6);
    P[1].aqi = hitungAQI(P[1].konsentrasi, PM10, 6);
    P[2].aqi = hitungAQI(P[2].konsentrasi, O3_8h, 5);
    P[3].aqi = hitungAQI(P[3].konsentrasi, CO, 6);
    P[4].aqi = hitungAQI(P[4].konsentrasi, SO2, 6);
    P[5].aqi = hitungAQI(P[5].konsentrasi, NO2, 6);

    for (int i = 0; i < 6; i++)
        P[i].kategori = kategoriAQI(P[i].aqi);

    int aqiTotal = P[0].aqi;
    for (int i = 1; i < 6; i++)
        if (P[i].aqi > aqiTotal)
            aqiTotal = P[i].aqi;

    cout << "\n==============================================================\n";
    cout << "                 TABEL HASIL PERHITUNGAN AQI                  \n";
    cout << "==============================================================\n";
    cout << left << setw(10) << "Polutan"
         << setw(15) << "Konsentrasi"
         << setw(10) << "AQI"
         << setw(25) << "Kategori" << endl;
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < 6; i++) {
        cout << left << setw(10) << P[i].nama
             << setw(15) << P[i].konsentrasi
             << setw(10) << P[i].aqi
             << setw(25) << P[i].kategori << endl;
    }

    cout << "==============================================================\n";

    cout << "AQI TOTAL : " << aqiTotal << endl;
    cout << "Kategori  : " << kategoriAQI(aqiTotal) << endl;
    cout << "==============================================================\n";

    return 0;
}
