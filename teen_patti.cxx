/*
Teen patti Game implemented by sharang gupta on 28/10/15
 */
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

class suit
{
    public : int s;
             suit()
             {
				 s=-1;
			 }
};
class number
{
	public : int n;
	         number()
	         {
				 n=-1;
			 }
};

class card : public suit, public number
{
	public : int p;
	         card()
	         {
				 p=0;
			 }
	
};

class player
{
	public : card deck[3];
	         int coins;
	         int blind;
	         int won;
	         char name[50];
	         int bid;
	         player operator +(player x)
	         {
				 player z;
				// z.bid=bid+x.bid;
				// z.coins+=z.bid;
				 //x.bid=0;
				// z.bid=0;
				
				//z.bid=x.bid*2;
				
				 return z;
			 }
			
				 
};

class set
{
	
public : void initialize(card *pack,player *group)
    
{
	for(int i=0;i<52;++i) pack[i].p=0;
	for(int i=0;i<13;++i)
	{
		pack[i].s=0;
		pack[i].n=i;
	}
	int k=0;
	for(int i=13;i<26;++i)
	{
		pack[i].s=1;
		pack[i].n=k;
		++k;
	}
	
	k=0;
	for(int i=26;i<39;++i)
	{
		pack[i].s=2;
		pack[i].n=k;
		++k;
	}
	
	k=0;
	for(int i=39;i<52;++i)
	{
		pack[i].s=3;
		pack[i].n=k;
		++k;
	}
	
	group[0].coins=100;
	group[0].blind=1;
	group[0].won=0;
	group[0].bid=0;
	
	group[1].coins=100;
	group[1].blind=0;
	group[1].won=0;
	group[1].bid=0;
	
}
};


class compare
{
	public : void check(player *group)
	{
		if(  (  (group[0].deck[0].n==group[0].deck[1].n) && (group[0].deck[0].n==group[0].deck[2].n)  ) &&     (  (group[1].deck[0].n==group[1].deck[1].n) && (group[1].deck[0].n==group[1].deck[2].n)  )  )
		{
			if(    (group[0].deck[0].n==0) || (group[0].deck[0].n>group[1].deck[0].n )   ) group[0].won=1;
			
			else group[1].won=1;
		}
		else
		if(  (group[0].deck[0].n==group[0].deck[1].n)  && (group[0].deck[0].n==group[0].deck[2].n)  )  group[0].won=1;
		else 
		if(  (group[1].deck[0].n==group[1].deck[1].n)  && (group[1].deck[0].n==group[1].deck[2].n)  )  group[1].won=1;
        else
        //this was for trio
      {
			
			
			if(  (  (group[0].deck[1].n-group[0].deck[0].n==1) && (group[0].deck[2].n-group[0].deck[1].n)==1 ) &&   (  (group[1].deck[1].n-group[1].deck[0].n==1) && (group[1].deck[2].n-group[1].deck[1].n)==1 )  )
		{
			if(    (  (group[0].deck[0].s==group[0].deck[1].s) && (group[0].deck[0].s==group[0].deck[2].s)  )   )  group[0].won=1;
			
			else  if(    (  (group[1].deck[0].s==group[1].deck[1].s) && (group[1].deck[0].s==group[1].deck[2].s)  )   ) group[1].won=1;
			
			
			else if(group[0].deck[2].n>group[1].deck[2].n) group[0].won=1;
				else group[1].won=1;
				
		}
		//this was for both having sequence
		else
		if(   (  (group[0].deck[1].n-group[0].deck[0].n==1) && (group[0].deck[2].n-group[0].deck[1].n)==1 )  )  group[0].won=1;
		else 
		if(   (  (group[1].deck[1].n-group[1].deck[0].n==1) && (group[1].deck[2].n-group[1].deck[1].n)==1 )  )  group[1].won=1;
		//this was for sequence
		else
		{
			if( (  (group[0].deck[0].s==group[0].deck[1].s) && (group[0].deck[0].s==group[0].deck[2].s)  ) && (  (group[0].deck[0].s==group[0].deck[1].s) && (group[0].deck[0].s==group[0].deck[2].s)  ) )  //same colour
			{
			    if(group[0].deck[2].n>group[1].deck[2].n) group[0].won=1;
				else group[1].won=1;
			}
			//this was for both having colour
			else if(  (  (group[0].deck[0].s==group[0].deck[1].s) && (group[0].deck[0].s==group[0].deck[2].s)  )  )  group[0].won=1;
			else  if(  (  (group[1].deck[0].s==group[1].deck[1].s) && (group[1].deck[0].s==group[1].deck[2].s)  )  )  group[1].won=1;
			//this was for colour
			else
			if(group[0].deck[2].n>group[1].deck[2].n) group[0].won=1;
				else group[1].won=1;
				//this is if both have nothing!!
			
		}//end of main(trio) else
		
	}//end of funcn
}
};//end of class	
			
class arrange
{
public : void arrange_deck(card *pack,int diff)
	     {
			 //srandom(time(NULL));
			 //int randNum = rand()% 10 + 1;
			 //srandom(time(NULL));
		    // random()%52;
		    
		    //random_shuffle(pack, pack + 52);
				randomize(52);
				//int x=random(2);
		}
   void arrange_deck(card *deck1)
   {
	   int i,j;
	   card temp;
	
		for(i=0;i<3;++i)
		{
			for(j=0;j<3-i-1;++j)
			{
				if(deck1[j].n > deck1[j+1].n)
				{
					temp=deck1[j];
					deck1[j]=deck1[j+1];
					deck1[j+1]=temp;
				}
			}
		}
   }

};

class deck5
{
	public : void print_deck(card *deck)
	{
		int i=0;
		cout<<"card number \t Suite \t     Value \t \n";
		for(i=0;i<3;++i)
		{
		if(deck[i].s==0 && deck[i].n==11) cout<<i+1<<".            \t clubs    \t jack \t \n";
		else
		if(deck[i].s==0 && deck[i].n==12) cout<<i+1<<".             \t clubs    \t queen \t \n";
		else
		if(deck[i].s==0 && deck[i].n==13) cout<<i+1<<".              \t clubs    \t king \t \n";
		else
		if(deck[i].s==0 && deck[i].n==0) cout<<i+1<<".                \t clubs    \t ACE!! \t \n";
		else
		if(deck[i].s==0) cout<<i+1<<".             \t clubs    \t "<<deck[i].n<<" \t \n";
		
		if(deck[i].s==1 && deck[i].n==11) cout<<i+1<<".             \t diamonds \t jack \t \n";
		else
		if(deck[i].s==1 && deck[i].n==12) cout<<i+1<<".              \t diamonds \t queen \t \n";
		else
		if(deck[i].s==1 && deck[i].n==13) cout<<i+1<<".               \t diamonds \t king \t \n";
		else
		if(deck[i].s==1 && deck[i].n==0) cout<<i+1<<".                \t diamonds \t ACE!! \t \n";
		else
		if(deck[i].s==1) cout<<i+1<<".             \t diamonds \t "<<deck[i].n<<" \t \n";
		
		if(deck[i].s==2 && deck[i].n==11) cout<<i+1<<".             \t hearts   \t jack \t \n";
		else
		if(deck[i].s==2 && deck[i].n==12) cout<<i+1<<".             \t hearts   \t queen \t \n";
		else
		if(deck[i].s==2 && deck[i].n==13) cout<<i+1<<".             \t hearts   \t king \t \n";
		else
		if(deck[i].s==2 && deck[i].n==0) cout<<i+1<<".              \t hearts   \t ACE!! \t \n";
		else
		if(deck[i].s==2) cout<<i+1<<".            \t hearts   \t "<<deck[i].n<<" \t \n";
		
		if(deck[i].s==3 && deck[i].n==11) cout<<i+1<<"1.            \t spades   \t jack \t \n";
		else
		if(deck[i].s==3 && deck[i].n==12) cout<<i+1<<"1.            \t spades   \t queen \t \n";
		else
		if(deck[i].s==3 && deck[i].n==13) cout<<i+1<<"1.            \t spades   \t king \t \n";
		else
		if(deck[i].s==3 && deck[i].n==0) cout<<i+1<<"1.             \t spades   \t ACE!! \t \n";
		else
		if(deck[i].s==3) cout<<i+1<<".             \t spades   \t "<<deck[i].n<<" \t \n";
		}
		cout<<"\n \n";
	}
};

int main(int argc, char **argv)
{
	char p1name[50],p2name[50];
	card pack[52];
	player group[2];
	set obj;
	deck5 obj2;
	compare obj3;
	arrange obj4;
	int bid1;
	obj.initialize(pack,group);
	
	cout<<"Enter player 1 name\n";
	cin>>p1name;
	cout<<"Enter player 2 name\n";
	cin>>p2name;
	if(strcmp(p1name,"sharang")==0 || strcmp(p2name,"sharang")==0) cout<<"sorry,sharang cannot be defeated...play with someone else\n";
	else
	{
		strcpy(group[0].name,p1name);
		strcpy(group[1].name,p2name);
		
		obj4.arrange_deck(pack,0);
		group[0].deck[0]=pack[0];
		group[1].deck[0]=pack[1];
		group[0].deck[1]=pack[2];
		group[1].deck[1]=pack[3];
		group[0].deck[2]=pack[4];
		group[1].deck[2]=pack[5];
		
		
		
		for(int i=0;i<6;++i) pack[i].p=1;   //the cards are picked!!!
		
		
		
		obj4.arrange_deck(group[0].deck);
		obj4.arrange_deck(group[1].deck);
		
		
		
		//now lets start the game!!!
		
		
		
		while(group[0].coins>0 && group[1].coins>0)
		{
			
		if(group[0].blind)
		{
			obj2.print_deck(group[1].deck);
			cout<<"You are blind,"<<group[0].name<<"how much would you like to bid,"<<group[0].name<<endl;
			cin>>bid1;
			if(bid1==0) {cout<<"dont be stingy!!!\n";bid1=10;}
			group[0].bid=bid1;
			group[0].coins-=bid1;
			group[1].bid=bid1*2;
			group[1].coins-=group[1].bid;
		}
		else
		{
			obj2.print_deck(group[0].deck);
			cout<<"you are blind,"<<group[1].name<<"how much would you like to bid,"<<group[1].name<<endl;
			cin>>bid1;
			if(bid1==0) {cout<<"dont be stingy!!!\n";bid1=10;}
			group[1].bid=bid1;
			group[1].coins-=bid1; cout<<group[1].coins<<"\n";
			group[0].bid=bid1*2;
			group[0].coins-=group[0].bid; cout<<group[0].coins<<"\n";
		}
			obj3.check(group);
			if(group[0].won==1)
			{
				cout<<"Player 1 has won!!!\n";
				cout<<"Player 1 deck : \n";
				obj2.print_deck(group[0].deck);
				cout<<"Player 2 deck : \n";
				obj2.print_deck(group[1].deck);
				//group[0]=group[0]+group[1];
				group[0].coins+=group[0].bid+group[1].bid;
				//group[1].coins-=group[1].bid;
				group[0].bid=group[1].bid=0;
				cout<<"Player 1 coins : "<<group[0].coins<<endl;
				cout<<"Player 2 coins : "<<group[1].coins<<endl;
			}
			else
			{
				cout<<"Player 2 has won!!!\n"; 
				cout<<"Player 1 deck : \n";
				obj2.print_deck(group[0].deck);
				cout<<"Player 2 deck : \n";
				obj2.print_deck(group[1].deck);
				//group[1]=group[1]+group[0];
				group[1].coins+=group[1].bid+group[0].bid;
				//group[0].coins-=group[0].bid;
				group[0].bid=group[1].bid=0;
				cout<<"Player 1 coins : "<<group[0].coins<<endl;
				cout<<"Player 2 coins : "<<group[1].coins<<endl;
			}
				
				for(int i=0;i<6;++i) pack[i].p=0;  //put the cards back
					
					obj4.arrange_deck(pack,0);
				
				group[0].deck[0]=pack[0];
	        	group[1].deck[0]=pack[1];
		        group[0].deck[1]=pack[2];
		        group[1].deck[1]=pack[3];
		        group[0].deck[2]=pack[4];
		        group[1].deck[2]=pack[5];
				for(int i=0;i<6;++i) pack[i].p=1;   //the cards are picked!!!
				
				obj4.arrange_deck(group[0].deck);
		        obj4.arrange_deck(group[1].deck);
		        
				if(group[0].blind) 
				{
					group[0].blind=0;         //switching the blind players
					group[1].blind=1;
				}
				else
				{
					group[0].blind=1;
					group[1].blind=0;
				}
				
			
				
		}
	
}
	return 0;
}

