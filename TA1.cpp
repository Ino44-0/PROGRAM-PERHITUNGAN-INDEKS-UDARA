#include <iostream>
#include <iomanip>
using namespace std;

// =====================
// Fungsi menghitung AQI
// =====================
int AQI_PM25(float c) {
    float Clow, Chigh; int Ilow, Ihigh;
    if (c <= 12.0) {Clow=0;Chigh=12;Ilow=0;Ihigh=50;}
    else if (c <= 35.4) {Clow=12.1;Chigh=35.4;Ilow=51;Ihigh=100;}
    else if (c <= 55.4) {Clow=35.5;Chigh=55.4;Ilow=101;Ihigh=150;}
    else if (c <= 150.4) {Clow=55.5;Chigh=150.4;Ilow=151;Ihigh=200;}
    else if (c <= 250.4) {Clow=150.5;Chigh=250.4;Ilow=201;Ihigh=300;}
    else if (c <= 350.4) {Clow=250.5;Chigh=350.4;Ilow=301;Ihigh=400;}
    else {Clow=350.5;Chigh=500.4;Ilow=401;Ihigh=500;}

    return (int)((Ihigh-Ilow)/(Chigh-Clow)*(c-Clow) + Ilow);
}

int AQI_PM10(float c) {
    float Clow, Chigh; int Ilow, Ihigh;
    if (c <= 54) {Clow=0;Chigh=54;Ilow=0;Ihigh=50;}
    else if (c <= 154) {Clow=55;Chigh=154;Ilow=51;Ihigh=100;}
    else if (c <= 254) {Clow=155;Chigh=254;Ilow=101;Ihigh=150;}
    else if (c <= 354) {Clow=255;Chigh=354;Ilow=151;Ihigh=200;}
    else if (c <= 424) {Clow=355;Chigh=424;Ilow=201;Ihigh=300;}
    else if (c <= 504) {Clow=425;Chigh=504;Ilow=301;Ihigh=400;}
    else {Clow=505;Chigh=604;Ilow=401;Ihigh=500;}

    return (int)((Ihigh-Ilow)/(Chigh-Clow)*(c-Clow) + Ilow);
}

int AQI_CO(float c) {
    float Clow, Chigh; int Ilow, Ihigh;
    if (c <= 4.4) {Clow=0;Chigh=4.4;Ilow=0;Ihigh=50;}
    else if (c <= 9.4) {Clow=4.5;Chigh=9.4;Ilow=51;Ihigh=100;}
    else if (c <= 12.4) {Clow=9.5;Chigh=12.4;Ilow=101;Ihigh=150;}
    else if (c <= 15.4) {Clow=12.5;Chigh=15.4;Ilow=151;Ihigh=200;}
    else if (c <= 30.4) {Clow=15.5;Chigh=30.4;Ilow=201;Ihigh=300;}
    else if (c <= 40.4) {Clow=30.5;Chigh=40.4;Ilow=301;Ihigh=400;}
    else {Clow=40.5;Chigh=50.4;Ilow=401;Ihigh=500;}

    return (int)((Ihigh-Ilow)/(Chigh-Clow)*(c-Clow) + Ilow);
}

int AQI_SO2(float c) {
    float Clow, Chigh; int Ilow, Ihigh;
    if (c <= 35) {Clow=0;Chigh=35;Ilow=0;Ihigh=50;}
    else if (c <= 75) {Clow=36;Chigh=75;Ilow=51;Ihigh=100;}
    else if (c <= 185) {Clow=76;Chigh=185;Ilow=101;Ihigh=150;}
    else if (c <= 304) {Clow=186;Chigh=304;Ilow=151;Ihigh=200;}
    else if (c <= 604) {Clow=305;Chigh=604;Ilow=201;Ihigh=300;}
    else if (c <= 804) {Clow=605;Chigh=804;Ilow=301;Ihigh=400;}
    else {Clow=805;Chigh=1004;Ilow=401;Ihigh=500;}

    return (int)((Ihigh-Ilow)/(Chigh-Clow)*(c-Clow) + Ilow);
}

int AQI_NO2(float c) {
    float Clow, Chigh; int Ilow, Ihigh;
    if (c <= 53) {Clow=0;Chigh=53;Ilow=0;Ihigh=50;}
    else if (c <= 100) {Clow=54;Chigh=100;Ilow=51;Ihigh=100;}
    else if (c <= 360) {Clow=101;Chigh=360;Ilow=101;Ihigh=150;}
    else if (c <= 649) {Clow=361;Chigh=649;Ilow=151;Ihigh=200;}
    else if (c <= 1249) {Clow=650;Chigh=1249;Ilow=201;Ihigh=300;}
    else if (c <= 1649) {Clow=1250;Chigh=1649;Ilow=301;Ihigh=400;}
    else {Clow=1650;Chigh=2049;Ilow=401;Ihigh=500;}

    return (int)((Ihigh-Ilow)/(Chigh-Clow)*(c-Clow) + Ilow);
}

int AQI_O3(float c) {
    float Clow, Chigh; int Ilow, Ihigh;
    if (c <= 0.054) {Clow=0;Chigh=0.054;Ilow=0;Ihigh=50;}
    else if (c <= 0.070) {Clow=0.055;Chigh=0.070;Ilow=51;Ihigh=100;}
    else if (c <= 0.085) {Clow=0.071;Chigh=0.085;Ilow=101;Ihigh=150;}
    else if (c <= 0.105) {Clow=0.086;Chigh=0.105;Ilow=151;Ihigh=200;}
    else if (c <= 0.200) {Clow=0.106;Chigh=0.200;Ilow=201;Ihigh=300;}
    else {Clow=0.201;Chigh=0.604;Ilow=301;Ihigh=500;}

    return (int)((Ihigh-Ilow)/(Chigh-Clow)*(c-Clow) + Ilow);
}

// =====================
// Kategori AQI
// =====================
string kategoriAQI(int aqi) {
    if (aqi <= 50) return "Baik";
    else if (aqi <= 100) return "Sedang";
    else if (aqi <= 150) return "Tdk Sehat";
    else if (aqi <= 200) return "Sgt Tdk Sehat";
    else if (aqi <= 300) return "Berbahaya";
    else return "Sgt Berbahaya";
}

// =====================
// MAIN PROGRAM
// =====================
int main() {
    string bulan[12] = {"Jan","Feb","Mar","Apr","Mei","Jun","Jul","Agu","Sep","Okt","Nov","Des"};

    float pm25[12], pm10[12], co[12], so2[12], no2[12], o3[12];
    int aqi25[12], aqi10[12], aqico[12], aqiso2[12], aqino2[12], aqio3[12], aqiFinal[12];
    string kategori[12];

    cout << "=== INPUT DATA (12 BULAN) ===\n";
    for (int i = 0; i < 12; i++) {
        cout << "\n--- " << bulan[i] << " ---\n";
        cout << "PM2.5 : "; cin >> pm25[i];
        cout << "PM10  : "; cin >> pm10[i];
        cout << "CO    : "; cin >> co[i];
        cout << "SO2   : "; cin >> so2[i];
        cout << "NO2   : "; cin >> no2[i];
        cout << "O3    : "; cin >> o3[i];

        aqi25[i] = AQI_PM25(pm25[i]);
        aqi10[i] = AQI_PM10(pm10[i]);
        aqico[i] = AQI_CO(co[i]);
        aqiso2[i] = AQI_SO2(so2[i]);
        aqino2[i] = AQI_NO2(no2[i]);
        aqio3[i] = AQI_O3(o3[i]);

        // AQI Final = yang tertinggi
        aqiFinal[i] = aqi25[i];
        if (aqi10[i] > aqiFinal[i]) aqiFinal[i] = aqi10[i];
        if (aqico[i] > aqiFinal[i]) aqiFinal[i] = aqico[i];
        if (aqiso2[i] > aqiFinal[i]) aqiFinal[i] = aqiso2[i];
        if (aqino2[i] > aqiFinal[i]) aqiFinal[i] = aqino2[i];
        if (aqio3[i] > aqiFinal[i]) aqiFinal[i] = aqio3[i];

        kategori[i] = kategoriAQI(aqiFinal[i]);
    }

    // =====================
    // TABEL OUTPUT
    // =====================
    cout << "\n\n=== TABEL MONITORING POLUSI UDARA ===\n";
    cout << left << setw(8) << "Bulan"
         << setw(8) << "AQI25"
         << setw(8) << "AQI10"
         << setw(8) << "CO"
         << setw(8) << "SO2"
         << setw(8) << "NO2"
         << setw(8) << "O3"
         << setw(10) << "Final"
         << "Kategori\n";

    cout << string(75, '-') << endl;

    for (int i = 0; i < 12; i++) {
        cout << left << setw(8) << bulan[i]
             << setw(8) << aqi25[i]
             << setw(8) << aqi10[i]
             << setw(8) << aqico[i]
             << setw(8) << aqiso2[i]
             << setw(8) << aqino2[i]
             << setw(8) << aqio3[i]
             << setw(10) << aqiFinal[i]
             << kategori[i]
             << endl;
    }

    return 0;
}

8
