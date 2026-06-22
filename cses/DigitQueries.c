#include <stdio.h>
#include <stdlib.h>
#define ll long long
void findGroup(ll indeksDiminta, ll *startDigitTertentu,
               ll *jumlahAngkaDariDigitTertentu, ll *digitLength) {
  while (indeksDiminta > *startDigitTertentu +
                             *jumlahAngkaDariDigitTertentu * *digitLength - 1) {
    *startDigitTertentu =
        *startDigitTertentu + *jumlahAngkaDariDigitTertentu * *digitLength;
    *jumlahAngkaDariDigitTertentu *= 10;
    (*digitLength)++;
  }
}
 
ll CariAngkaDariQuery(ll indeksDiminta, ll *startDigitTertentu,
                      ll *digitLength) {
  ll angkaPertamaDariDigit = 1;
  for (int i = 1; i < *digitLength; i++) {
    angkaPertamaDariDigit *= 10;
  }
  ll offsetStartKeQuery =
      (indeksDiminta - *startDigitTertentu) / (*digitLength);
  ll AngkaPertamaDigitKeOffset = angkaPertamaDariDigit + offsetStartKeQuery;
  return AngkaPertamaDigitKeOffset;
}
ll cariUrutanHasilAngkaDariQuery(ll *AngkaPertamaDigitKeOffset,
                                 ll indeksDiminta, ll *startDigitTertentu,
                                 ll *digitLength) {
 
  ll temp = *AngkaPertamaDigitKeOffset;
  ll n = 0;
  while (temp > 0) {
    temp /= 10;
    n++;
  }
  ll *angka = malloc(sizeof(ll) * n);
  for (int i = 0; i < n; i++) {
    ll pembagi = 1;
    for (int j = 0; j < n - i; j++) {
      pembagi *= 10;
    }
    angka[i] = (*AngkaPertamaDigitKeOffset % pembagi) / (pembagi / 10);
  }
  ll offsetDariQueryKeStart = indeksDiminta - *startDigitTertentu;
  ll indeksBerdasarkanOffsetAwalKeAkhir =
      offsetDariQueryKeStart % (*digitLength);
  ll hasil = angka[indeksBerdasarkanOffsetAwalKeAkhir];
  free(angka);
  return hasil;
}
int main() {
  ll n;
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    ll m;
    scanf("%lld", &m);
 
    ll startDigitTertentu = 1;
    ll jumlahAngkaDariDigitTertentu = 9;
    ll digitLength = 1;
    findGroup(m, &startDigitTertentu, &jumlahAngkaDariDigitTertentu,
              &digitLength);
    ll angkaDariQuery =
        CariAngkaDariQuery(m, &startDigitTertentu, &digitLength);
    ll jawaban = cariUrutanHasilAngkaDariQuery(
        &angkaDariQuery, m, &startDigitTertentu, &digitLength);
    printf("%lld\n", jawaban);
  }
}