#include <assert.h>
#include<iostream>
using namespace std;
const int bpmrange[]={70,150};
const int spo2range[]={90,100};
const int resprange[]={30,95};
bool checklimit(float value,int min,int max)
{
    return(value>=min &&value<=max);
}
bool bpmisok(float bpm)
{
    if(checklimit(bpm,bpmrange[0],bpmrange[1])) 
    return true;
    else
    cout<<"BPM check up needed"<<endl;
    return false;
}
bool spo2isok(float spo2)
{
    if(checklimit(spo2,spo2range[0],spo2range[1])) 
        return true;
    else
         cout<<"SPO2 check up needed"<<endl;
         return false;
}
bool respisok(float resp)
{
  if(checklimit(resp,resprange[0],resprange[1])) 
        return true;
    else    
    cout<<"Respiratory check up needed"<<endl;
    return false;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (bpmisok(bpm) && spo2isok(spo2) && respisok(respRate));
 }
int main() {
  assert(checklimit(54,10,100)==true);
  assert(checklimit(50,10,40)==false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(80, 95, 40) == true);
  assert(vitalsAreOk(160, 90, 40) == false);
  assert(vitalsAreOk(90, 80, 40) == false);
  assert(vitalsAreOk(90, 90, 20) == false);
}
