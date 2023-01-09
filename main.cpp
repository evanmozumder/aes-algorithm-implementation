#include<bits/stdc++.h>
using namespace std;

void printArray(string name,string arr[4][4]){
  cout<<name<<endl;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

string decToHexa(int n){
  string ans = "";
  int m=n;
  while (n != 0) {
    int rem = 0;
    char ch;
    rem = n % 16;
    if (rem < 10) {
      ch = rem + 48;
    }
    else {
      ch = rem + 55;
    }
    ans += ch;
    n = n / 16;
  }
  if(m<16)ans+="0";
  if(m==0)ans="00";
  int i = 0, j = ans.size() - 1;
  while(i <= j){
    swap(ans[i], ans[j]);
    i++;
    j--;
  }
  return ans;
}
int power(int base, int p){
  int res=1;
  while(p--){
    res*=base;
  }
  return res;
}

int hexToDec(string s){
  int le=s.length();
  int ar[le],n=0;
  for(int i=0;i<le;i++){
    if(((int)s[i])>57){
      ar[i]=s[i]-55;
    }else {
      ar[i]=s[i]-48;
    }
  }
  int p=le-1;
  for(int i=0;i<le;i++){
    n+=ar[i]*power(16,p);
    p--;
  }

  return n;
}
int hexToDecChar(char s){
  // int le=s.length();
  int n=0;
  // for(int i=0;i<le;i++){
  if(((int)s)>57){
    n=s-55;
  }else {
    n=s-48;
  }
  // }
  // int p=le-1;
  // for(int i=0;i<le;i++){
  //   n+=ar[i]*power(16,p);
  //   p--;
  // }

  return n;
}



int main() {
  string plain_text="Two One Nine Two";
  string encryption_key="Thats my Kung Fu";
  // cin>>plain_text>>encryption_key;
  string ar[16],arr[16],state_array[4][4],key[4][4];
  for(int i=0;i<16;i++){
    ar[i]=decToHexa((int)plain_text[i]);
    arr[i]=decToHexa((int)encryption_key[i]);
  }
  int k=0;
  for(int j=0;j<4;j++){
    for(int i=0;i<4;i++){
      state_array[i][j]=ar[k];
      key[i][j]=arr[k];
      k++;
    }
  }
  
  printArray("state array",state_array);
  printArray("encryption key",key);

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      state_array[i][j]=decToHexa(hexToDec(state_array[i][j]) ^ hexToDec(key[i][j]));
    }
  }
  printArray("new state array",state_array);

  string s_box[16][16]={
  {"63",	"7C",	"77",	"7B",	"F2",	"6B",	"6F",	"C5",	"30",	"01",	"67",	"2B",	"FE",	"D7",	"AB",	"76"},
  {"CA",	"82",	"C9",	"7D",	"FA",	"59",	"47",	"F0",	"AD",	"D4",	"A2",	"AF",	"9C",	"A4",	"72",	"C0"},
  {"B7",	"FD",	"93",	"26",	"36",	"3F",	"F7",	"CC",	"34",	"A5",	"E5",	"F1",	"71",	"D8",	"31",	"15"},
  {"04",	"C7",	"23",	"C3",	"18",	"96",	"05",	"9A",	"07",	"12",	"80",	"E2",	"EB",	"27",	"B2",	"75"},
  {"09",	"83",	"2C",	"1A",	"1B",	"6E",	"5A",	"A0",	"52",	"3B",	"D6",	"B3",	"29",	"E3",	"2F",	"84"},
  {"53",	"D1",	"00",	"ED",	"20",	"FC",	"B1",	"5B",	"6A",	"CB",	"BE",	"39",	"4A",	"4C",	"58",	"CF"},
  {"D0",	"EF",	"AA",	"FB",	"43",	"4D",	"33",	"85",	"45",	"F9",	"02",	"7F",	"50",	"3C",	"9F",	"A8"},
  {"51",	"A3",	"40",	"8F",	"92",	"9D",	"38",	"F5",	"BC",	"B6",	"DA",	"21",	"10",	"FF",	"F3",	"D2"},
  {"CD",	"0C",	"13",	"EC",	"5F",	"97",	"44",	"17",	"C4",	"A7",	"7E",	"3D",	"64",	"5D",	"19",	"73"},
  {"60",	"81",	"4F",	"DC",	"22",	"2A",	"90",	"88",	"46",	"EE",	"B8",	"14",	"DE",	"5E",	"0B",	"DB"},
  {"E0",	"32",	"3A",	"0A",	"49",	"06",	"24",	"5C",	"C2",	"D3",	"AC",	"62",	"91",	"95",	"E4",	"79"},
  {"E7",	"C8",	"37",	"6D",	"8D",	"D5",	"4E",	"A9",	"6C",	"56",	"F4",	"EA",	"65",	"7A",	"AE",	"08"},
  {"BA",	"78",	"25",	"2E",	"1C",	"A6",	"B4",	"C6",	"E8",	"DD",	"74",	"1F",	"4B",	"BD",	"8B",	"8A"},
  {"70",	"3E",	"B5",	"66",	"48",	"03",	"F6",	"0E",	"61",	"35",	"57",	"B9",	"86",	"C1",	"1D",	"9E"},
  {"E1",	"F8",	"98",	"11",	"69",	"D9",	"8E",	"94",	"9B",	"1E",	"87",	"E9",	"CE",	"55",	"28",	"DF"},
  {"8C",	"A1",	"89",	"0D",	"BF",	"E6",	"42",	"68",	"41",	"99",	"2D",	"0F",	"B0",	"54",	"BB",	"16"}
};

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      string st = state_array[i][j];
      int x = hexToDecChar(st[0]);
      int y = hexToDecChar(st[1]);
      state_array[i][j]=s_box[x][y];
    }
    cout<<endl;
  }
  printArray("substitutes array",state_array);

  
}

