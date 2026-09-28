#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    cin.ignore();
    map<string,int>mp;
    string line;
    while(getline(cin,line)&&!line.empty()){
        mp[line]++;
    }
    int i=1;
    while(true){
        string code;
        cin>>code;
        if(code=="CL")break;
        string judul;
        cin.ignore();
        getline(cin,judul);
        if(code=="PM"){
            if(mp[judul]>0){
                mp[judul]--;
                cout<<"Pelanggan ke-"<<i<<" : Buku Tersedia & Berhasil Dipinjam"<<endl;
            }else{
                cout<<"Pelanggan ke-"<<i<<" : Maaf Buku Anda Tidak Tersedia, Silahkan Kembali Minggu Depan"<<endl;
            }
        }else{
            cout<<"Pelanggan ke-"<<i<<" : Terima Kasih Telah Membaca :)"<<endl;
            mp[judul]++;
        }
        i++;
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}