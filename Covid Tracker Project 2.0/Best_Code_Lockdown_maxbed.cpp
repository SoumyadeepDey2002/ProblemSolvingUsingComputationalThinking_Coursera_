//COVID 19 Tracker with Lockdown

// In this code I haven't used the formula in the ppt, I have used r0 which means the number of people a infected person can infect before he has recovered

#include<bits/stdc++.h>
using namespace std;

bool lockdown(int a[],int n,int day){
    for(int i=0;i<n;i++){
        if(a[i]==day){
            return true;
            break;
        }
    }
    return false;
}

int main()
{
	long long S,I,R,r0,V,maxbed;
    int lock[1000];
	double RecoveryRate,MortalityRate;

    long long saved = 0, recovered = 0, death = 0;

	cin>>S>>I>>R>>r0>>RecoveryRate>>MortalityRate>>V>>maxbed;;
    long long r1 = r0, r2 = (r0/2);

    int n;
    cin>>n;
    cout<<"Lockdown in the months :"<<endl;
    for(int i=0;i<n;i++){
        cin>>lock[i];
        cout<<lock[i]<<endl;
        
    }
    cout<<"Initially Suscetible people : "<<S<<endl;
    cout<<"Initially Infected people : "<<I<<endl;
    cout<<"How many people can a infected person infect before recovery : "<<r0<<endl;
    cout<<"Vaccination available per month : "<<V<<endl;
    cout<<"RecoveryRate : "<<RecoveryRate<<endl;
    cout<<"MortalityRate : "<<MortalityRate<<endl;

	cout<<"Total Number of people : "<<S+I<<endl;

    cout<<"\n***************************************************\n";

    cout<<"Month 0 : "<<S<<"     "<<I<<"     "<<R<<"      "<<(int)(MortalityRate*I)<<endl;
    
    int day = 1;
    bool f = false;
	while(I>0){

        if(lockdown(lock,n,day)){
            r0 = r2;
        }
        else{
            r0 = r1;
        }


        if(f == true || ((S-(I*r0)-V) <= 0)){
            I += S;
            int original_i = I;
            S = 0;
            if(I==1){
                I=0;
                recovered++;
            }
            else{
                if(original_i*RecoveryRate>maxbed){
                    I -= maxbed;
                    recovered += maxbed;
                }
                else{
                    I -= (int)(I*RecoveryRate);
                    recovered += (original_i*RecoveryRate);
                }
		    I -= (int)(original_i*MortalityRate);
            death += (original_i*MortalityRate);
            }

            if(original_i*RecoveryRate>maxbed){
                cout<<"Month "<<day<<" :   "<<S<<"      "<<original_i<<"      "<<(int)maxbed<<"      "<<(int)(MortalityRate*original_i)<<endl;
            }
            else{
            cout<<"Month "<<day<<" :   "<<S<<"      "<<original_i<<"      "<<(int)(original_i*RecoveryRate)<<"      "<<(int)(MortalityRate*original_i)<<endl;
            }
        day++;
        f = true;
         }
         else{
        
        //Suseptible to infected
		S -= (I*r0);
		I += (I*r0);
        int original_i = I;
        
        //Reduction of infected rate due to recovery and death
        if(original_i*RecoveryRate>maxbed){
            I-=maxbed;
            recovered += maxbed;
        }
        else{
            I -= (int)(I*RecoveryRate);
            recovered += (original_i*RecoveryRate);
        }
		I -= (int)(original_i*MortalityRate);

		S -= V;

        saved += V;
        
        death += (original_i*MortalityRate);

        if(original_i*RecoveryRate>maxbed){
		cout<<"Month "<<day<<" :   "<<S<<"      "<<original_i<<"      "<<(int)maxbed<<"       "<<(int)(original_i*MortalityRate)<<endl;
        }
        else{
            cout<<"Month "<<day<<" :   "<<S<<"      "<<original_i<<"      "<<(int)(original_i*RecoveryRate)<<"       "<<(int)(original_i*MortalityRate)<<endl;
        }
        day++;
         }

	}

    cout<<"People saved by Vaccination : "<<saved<<endl;
        cout<<"People recovered from COVID 19 :"<<recovered<<endl;
        cout<<"Total Deaths : "<<death;

	return 0;
}