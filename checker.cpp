#include <assert.h>
bool bpmisok(float bpm)
{
    if(bpm > 70 && bpm < 150) 
      return true;
}
bool spo2isok(float spo2)
{
  if(spo2>90)
     return true;
 }
bool respisok(float resp)
{
    if(resp > 30 && resp< 95) 
       return true;
 }
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if((bpmisok(bpm)) && (spo2isok(spo2)) && (respisok(respRate)))
  {
      return true;
  }
  else
  {
     return false;
  }
  
}
int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
