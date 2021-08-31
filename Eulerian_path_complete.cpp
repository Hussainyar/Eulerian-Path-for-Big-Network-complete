

#include <bits/stdc++.h>
using namespace std;
void findpath(int graph[][101], int n)
{
    vector<int> numofadj;

    for (int i = 0; i < n; i++)
        numofadj.push_back(accumulate(graph[i],
                                      graph[i] + 101, 0));
 
    // Find out how many vertex has odd number edges
    int startpoint = 0, numofodd = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (numofadj[i] % 2 == 1)
        {
            numofodd++;
            startpoint = i;
        }
    }
 
   
    if (numofodd > 2)
    {
        cout << "No Solution" << endl;
        return;
    }
 
   
    stack<int> stack;
    vector<int> path;
    int cur = startpoint;
 
   
    while (!stack.empty() or
            accumulate(graph[cur],
                       graph[cur] + 101, 0) != 0)
    {
        
        if (accumulate(graph[cur],
                       graph[cur] + 101, 0) == 0)
        {
            path.push_back(cur);
            cur = stack.top();
            stack.pop();
        }
 
      
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (graph[cur][i] == 1)
                {
                    stack.push(cur);
                    graph[cur][i] = 0;
                    graph[i][cur] = 0;
                    cur = i;
                    break;
                }
            }
        }
    }
 
    // print the path
    for (auto ele : path) cout << ele << " -> ";
    cout << cur << endl;
}
//**************************************************************************************************
 
int is_odd_arr(int a[], int size_ );
int is_odd_arr(int a[] , int size_ )
{
    int sum = 0;
    for (int i =0 ; i < size_ ;i++)
        sum += a[i];

    /*for (int i =0 ; i < size_ ;i++)
        cout << a[i] << "\t";*/
    return (sum%2);
}
//***************************************************************************8************************

int main()
{
int N=50;
float P = 0.3;
int Adjmat[N][N];
int Adjmat2[101][101];
//***************************************************************************************************

for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		Adjmat[i][j] = 0;


	for (int i = 0; i < N; i++)
	{
        for (int j = 0; j < N; j++)
		{
            double r = ((double)rand() / (RAND_MAX));
			if (r < P && i!= j)
			{
                Adjmat[i][j] = 1;
				Adjmat[j][i] = 1;
            }
		}
	}
//**********************************************************************************************
    for (int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N; j++)
            cout <<Adjmat[i][j]<<'\t';
        cout <<endl;

    }
//**********************************************************************************************
    //int Adjmat2[N+1][N+1];
     for(int i = 0 ; i < N+1 ; i++)
        for(int j = 0 ; j <N+1 ;j++)
            Adjmat2[i][j] = 0;

cout << "/****************************************************** \n";
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N+1 ;j++)
        {
            if(j == N)
            {
                 Adjmat2[i][j] = is_odd_arr(Adjmat[i], N);
                 Adjmat2[j][i] = is_odd_arr(Adjmat[i], N);
             }
            else
                Adjmat2[i][j] = Adjmat[i][j];

        }

    for(int i = 0 ; i < N+1 ; i++)
    {
        for(int j = 0 ; j <N+1 ;j++)
           cout <<  Adjmat2[i][j] << "\t";
        cout << endl;
    }
//************************************************************************************************
    ofstream adj("ad1.txt");
    for(int i = 0 ; i < N ;i++)
        {
            for(int j = 0 ; j <N ; j++)
			
                adj << Adjmat [i][j] << "\t";
            adj  << endl;
			
			
			

        }
    ofstream adj2("ad2.txt");
    for(int i = 0 ; i < N+1 ;i++)
        {
            for(int j = 0 ; j <N+1 ; j++)
			
                adj2 << Adjmat2 [i][j] << "\t";
            adj2  << endl;
		
        }
    //*****************************************************************************************************
    // Test case 1
    /*int Adjmat2[][7] = {{0, 0, 1, 1, 1, 1, 0},
                       {0, 0, 0, 1,	1, 0, 0},
                       {1, 0, 0, 1,	1, 0, 1},
                       {1, 1, 1, 0,	1, 1, 1},
                       {1, 1, 1, 1,	0, 1, 1},
                      {1, 0, 0, 1,	1, 0, 1},
                      {0, 0, 1, 1,	1, 1, 0}};*/
    int n = sizeof(Adjmat2) / sizeof(Adjmat2[0]);
    findpath(Adjmat2, N+1);
 //**********************************************************************************************
  
    // n = sizeof(Adjmat2) / sizeof(Adjmat2[0]);
    //findpath(Adjmat2, n);

   
}