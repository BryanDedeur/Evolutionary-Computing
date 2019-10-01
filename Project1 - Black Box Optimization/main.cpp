#include <iostream>

using namespace std;

const int LEN = 100;

double eval(int *pj);

int main(int argc, char *argv[])
{
  long itterations = 100;

  for (int i = 0; i < argc; ++i) { 
    switch(i) {
      case 1:
      itterations = (long int) argv[i];
      break;
      default:
      break;
    }
  }

  int vec[LEN];

  // initialization
  for(int i = 0; i < LEN; i++){
    vec[i] = 0;
  }

  // hill climber
  int best = 0;
  double fitness;

  for(int i = 0; i < LEN; i++){
    int temp = vec[i];
    if (vec[i] == 0) { 
      vec[i] = 1;
    } else {
      vec[i] = 0;
    }

    fitness = eval(vec);
    cout << "fitness = " << fitness << endl;
    if (fitness <= best) {
      vec[i] = temp;
    }
  }

  cout << "Best fitness is:" << best << endl;
}

