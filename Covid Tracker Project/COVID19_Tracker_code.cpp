#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long S,I,R,r0,V;
	double RecoveryRate,MortalityRate;

    long long saved = 0, recovered = 0, death = 0;

	cin>>S>>I>>R>>r0>>RecoveryRate>>MortalityRate>>V;
    cout<<"Initially Suscetible people : "<<S<<endl;
    cout<<"Initially Infected people : "<<I<<endl;
    cout<<"How many people can a infected person infect before recovery : "<<r0<<endl;
    cout<<"RecoveryRate : "<<RecoveryRate<<endl;
    cout<<"MortalityRate : "<<MortalityRate<<endl;

	cout<<"Total Number of people : "<<S+I<<endl;

    cout<<"\n***************************************************\n";

    cout<<"Month 0 : "<<S<<"     "<<I<<"     "<<R<<"      "<<(int)(MortalityRate*I)<<endl;
    
    int day = 1;
    bool f = false;
	while(I>0){

        if(f == true || ((S-(I*r0)) <= 0)){
            I += S;
            int original_i = I;
            S = 0;
            if(I==1){
                I=0;
                recovered++;
            }
            else{
            I -= (int)(I*RecoveryRate);
		    I -= (int)(original_i*MortalityRate);
            recovered += (original_i*RecoveryRate);
            death += (original_i*MortalityRate);
            }

            
            cout<<"Month "<<day<<" : "<<S<<"     "<<I<<"     "<<(int)(I*RecoveryRate)<<"      "<<(int)(MortalityRate*I)<<endl;
        day++;
        f = true;
         }
         else{
        
        //Suseptible to infected
		S -= (I*r0);
		I += (I*r0);
        int original_i = I;
        
        //Reduction of infected rate due to recovery and death
		I -= (int)(I*RecoveryRate);
		I -= (int)(original_i*MortalityRate);

		S -= V;

        saved += V;
        recovered += (original_i*RecoveryRate);
        death += (original_i*MortalityRate);

		cout<<"Month "<<day<<" : "<<S<<"     "<<original_i<<"     "<<(int)(original_i*RecoveryRate)<<"      "<<(int)(original_i*MortalityRate)<<endl;
        day++;
         }

	}

    cout<<"People saved by Vaccination : "<<saved<<endl;
        cout<<"People recovered from COVID 19 :"<<recovered<<endl;
        cout<<"Total Deaths : "<<death;

	return 0;
}