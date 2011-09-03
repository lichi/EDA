#include <iostream>
#include <queue>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <tbb/tick_count.h>
#include <tbb/spin_mutex.h>
#include <tbb/tbb_thread.h>

using namespace std;
using namespace tbb;

spin_mutex m1;
queue <int> q;
class cola_sincro{

 	public:
 	   int tamMax;
 	   queue <int> q;
 	   spin_mutex::scoped_lock lock;
 	   spin_mutex m1;
 	   //tbb_thread mt1;
 	   tbb_thread mt2;
 	   tbb_thread mt3;
 	   tbb_thread mt4;
 	   
 	cola_sincro()
 	{
 		tamMax = 100;
 	}
 	   
	void push(int d)
	{
	    spin_mutex::scoped_lock lock;
	    if(!q.empty())       
	    	q.push(d);
	    else 
	    	lock.acquire(m1);
	}

	void pop()
	{
	   spin_mutex::scoped_lock lock;
	   if(!q.empty())
	    q.pop();
	    else
	    {
	       lock.acquire(m1);//bloquea
	       sleep(3);
	       lock.release();//libera el bloqueo
	   }
	}
	
	void llenar()
	{
		int cantidad, temp;
		cout<<"Cuantos números quiere generar?"<<endl;
	  	cin>>cantidad;
	  	srand(time(0));
	  	
	  	for(int i=1; i<=cantidad; i++)
	   	{
	      	     temp = 1 + rand() % 50;
		     tbb_thread mt1(push,temp);   
		     //lock.acquire(m1);
		     //sleep(3);
		     //mt2(push,temp);   
		      //lock.release();
		      for(int j=1; j<=2; j++)
		      {
			 
		      }	
		}
		/*	
		while(!q.empty()) {
		    cout<<q.front();
		    q.pop();
		    //tbb_thread mt3(delet);
		    tbb_thread mt4(delet);
		  }
		  cout<<endl;*/
	}
};


int main()
{
  srand(time(0));
  queue <int> q;
  return 0; 
}
 

