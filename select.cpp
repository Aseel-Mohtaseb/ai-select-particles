// In this program i used cumulative weights
#include <iostream>
#include <time.h>
using namespace std;

// The value of the particle represents its weight
double particles[10];
double selectedParticles[10];
double cumulativeWeights[10];

void setWeights(){
    int sumOfWeights = 0;

    // I'm generating random weights here
    for (int i = 0; i < 10; i++)
    {
        particles[i] = rand()%100;
        sumOfWeights += particles[i];
    }

     for (int i = 0; i < 10; i++)
    {
        particles[i] /= sumOfWeights;
    }
    
}

void calcCumulativeWeights(){
    cout<<"\n\ntheir cumulative Weight: \n" ;
    for (int i = 0; i < 10; i++)
    {
        cumulativeWeights[i] = particles[i];
        for (int j = 0; j < i; j++)
        {
            cumulativeWeights[i] += particles[j];
        }
        cout<<"[" << i << " , " << cumulativeWeights[i] << "]" <<" ";
    }
}

void selectParticles(){
    // Random numbers generated between 0 and 1:
    
    double randNum;
    cout<<"\n\nrandom numbers generated: "<<endl;
    for (int i = 0; i < 10; i++) 
    {
        randNum = (double) rand()/RAND_MAX;
        cout<<randNum<<" ";
        for (int j = 0; j < 10; j++)
        {
            if(randNum<=cumulativeWeights[j]){
                selectedParticles[i] = particles[j];
                break;
            }
        }
    }
}

void printParticleWeight(){
    cout << "particles weights:"<< endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<"[" << i << " , " << particles[i] << "]" <<" ";
    }
}
void printselectedParticles(){
    cout << "\n\nweights of selected particles:"<< endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<selectedParticles[i]<<" ";
    }
}
int main(){
    srand( (unsigned)time( 0 ) );
    setWeights();
    printParticleWeight();
    calcCumulativeWeights();
    selectParticles();
    printselectedParticles();  

    return 0;
}