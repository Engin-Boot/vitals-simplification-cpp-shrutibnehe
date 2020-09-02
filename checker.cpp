#include <iostream>
using namespace std;
const int bpmrange[]={90,150};
const int spo2range[]={90,100};
const int respRaterange[]={30,95};

class Alert
{
  public:

    virtual void raisealert(const char*, const char*) = 0;
};
class SMSAlert: public Alert
{
public:
	void raisealert(const char* vitalname,const char* msg) override
	{
     cout<<"SMS Alert  "<<vitalname<<" is "<<msg<<endl;
	}
};

class SoundAlert:public Alert
{
public:
	void raisealert(const char* vitalname,const char*msg) override
		{
		cout<<"Sound Alert "<<vitalname<<" is "<<msg<<endl;
		}

};
class vitals
{
 public:
	 void checklimit(const char* vitalname,int vitalValue, int lowerLimit, int upperLimit,Alert* alert)
	{
	      if(vitalValue < lowerLimit)
	         alert->raisealert(vitalname,"LOW");
	      else if(vitalValue > upperLimit)
	    	  alert->raisealert(vitalname,"HIGH");
	      else
	        alert->raisealert(vitalname,"NORMAL");
}
	void vitalsAreOk(float bpm, float spo2, float respRate,Alert* alert) {
	       checklimit("BPM",bpm, bpmrange[0],bpmrange[1],alert );
	       checklimit("SPO2",spo2, spo2range[0],spo2range[1],alert );
	       checklimit("RESPRATE",respRate, respRaterange[0],respRaterange[1],alert );
	}
};
int main() {
          SMSAlert smsalert;
	  SoundAlert soundalert;
	  vitals checkvitals;
	  checkvitals.vitalsAreOk(100, 95, 60, &smsalert); //No alert

	  checkvitals.vitalsAreOk(155, 90, 90, &smsalert); //Bpm is high
	  checkvitals.vitalsAreOk(140, 80, 60, &smsalert); //  spo2 is low
	  checkvitals.vitalsAreOk(140, 95, 110, &smsalert); //resprate is high

	  checkvitals.vitalsAreOk(100, 95, 60, &soundalert); //No alert

	  checkvitals.vitalsAreOk(155, 90, 90, &soundalert); //Bpm is high
	  checkvitals.vitalsAreOk(140, 80, 60, &soundalert); //  spo2 is low
	  checkvitals.vitalsAreOk(140, 95, 110, &soundalert); //resprate is high
}
