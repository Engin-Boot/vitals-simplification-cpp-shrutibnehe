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
	const char* checklimit(int vitalValue, int lowerLimit, int upperLimit)
	{
	      if(vitalValue < lowerLimit)
	        return "LOW";
	      if(vitalValue > upperLimit)
	        return "HIGH";
	      return "Within Range";
}
	void vitalsAreOk(float bpm, float spo2, float respRate) {
	      const char* bpmmsg = checklimit(bpm, bpmrange[0],bpmrange[1] );
	      const char* spo2msg = checklimit(spo2, spo2range[0],spo2range[1] );
	      const char* respRatemsg = checklimit(respRate, respRaterange[0],respRaterange[1] );

	      Alert* alert;
	      SMSAlert alertSMS;
	      SoundAlert alertSound;

	      alert = &alertSMS;
	      alert->raisealert("BPM", bpmmsg);
	      alert->raisealert("SPO2", spo2msg);
	      alert->raisealert("Respiratory Rate", respRatemsg);

	      alert = &alertSound;
	      alert->raisealert("BPM", bpmmsg);
	      alert->raisealert("SPO2", spo2msg);
	      alert->raisealert("Respiratory Rate", respRatemsg);
	    }
};
int main() {
	vitals checkvitals;
	  checkvitals.vitalsAreOk(95, 95, 60);
	  checkvitals.vitalsAreOk(80, 110, 20);
	  checkvitals.vitalsAreOk(80, 98, 45);
	  checkvitals.vitalsAreOk(100, 80, 40);
	  checkvitals.vitalsAreOk(90, 95, 100);
}
